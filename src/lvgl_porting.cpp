#include "lvgl_porting.h"
#include "freertos/FreeRTOS.h"
#include "M5Unified.h"
#include "../../../../../../.platformio/packages/framework-arduinoespressif32/tools/sdk/esp32/include/freertos/include/freertos/task.h"
#include "../../../../../../.platformio/packages/framework-arduinoespressif32/tools/sdk/esp32/include/freertos/include/freertos/semphr.h"
lv_ui guider_ui;

#define EXAMPLE_LVGL_TICK_PERIOD_MS     2               /*!< LVGL tick period in ms */
#define EXAMPLE_LVGL_TASK_MAX_DELAY_MS  500
#define EXAMPLE_LVGL_TASK_MIN_DELAY_MS  1
#define EXAMPLE_LVGL_TASK_STACK_SIZE    (8 * 1024)
#define EXAMPLE_LVGL_TASK_PRIORITY      2

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[LCD_WIDTH *20];
static lv_color_t buf2[LCD_WIDTH *20];


static int32_t encoder_diff;
static lv_indev_state_t encoder_state;
uint8_t encoder_test_flag = 0;

TaskHandle_t task_lv_handle = NULL;
SemaphoreHandle_t xguisemap;

bool example_lvgl_lock(int timeout_ms)
{
    const TickType_t timeout_ticks = (timeout_ms== -1) ? portMAX_DELAY : pdMS_TO_TICKS(timeout_ms);
    return xSemaphoreTake (xguisemap, timeout_ticks) == pdTRUE;
}


void example_lvgl_unlock(void)
{
    xSemaphoreGive(xguisemap);

}

static void example_lvgl_port_task(void *arg)
{
    uint32_t task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
    setup_ui(&guider_ui);
    while (1)
    {
        if(example_lvgl_lock(-1)){
          //  M5.update();
            task_delay_ms = lv_timer_handler();
           example_lvgl_unlock();
        }
          if (task_delay_ms > EXAMPLE_LVGL_TASK_MAX_DELAY_MS) {
            task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
        } else if (task_delay_ms < EXAMPLE_LVGL_TASK_MIN_DELAY_MS) {
            task_delay_ms = EXAMPLE_LVGL_TASK_MIN_DELAY_MS;
        }
        vTaskDelay(pdMS_TO_TICKS(task_delay_ms));
    }
   
    }
    



static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    int w = (area->x2 - area->x1 + 1);
    int h = (area->y2 - area->y1 + 1);

    M5.Display.startWrite();                            /* Start new TFT transaction */
    M5.Display.setAddrWindow(area->x1, area->y1, w, h); /* set the working window */
    
    M5.Display.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);

    M5.Display.endWrite();     /* terminate TFT transaction */
    lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
}



static void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    uint16_t touchX, touchY;
    bool touched;
    touched = M5.Display.getTouch(&touchX, &touchY);
    if (!touched)
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;
        data->point.x = touchX;
        data->point.y = touchY;

    }
    
}


#if (ENCODER_INPUT > 0)
/*Initialize your keypad*/
static void encoder_init(void)
{
    encoder.resetEncoder();
}

/*Call this function in an interrupt to process encoder events (turn, press)*/
static void encoder_handler(void)
{
    if (btl_upgrade.bootloader_upgrade_lock(1)) {
        if (encoder.getDevStatus()) {
            encoder_diff = encoder.getIncEncoderValue();
            if (encoder_diff)
                M5.Speaker.tone(3300, 15);
            if (encoder.getButtonStatus())
                encoder_state = LV_INDEV_STATE_REL;
            else
                encoder_state = LV_INDEV_STATE_PR;
        }        
        btl_upgrade.bootloader_upgrade_unlock();
    }
}

/*Will be called by the library to read the encoder*/
static void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    if (!encoder_test_flag) {
        encoder_handler();
        data->enc_diff = encoder_diff;
        data->state = encoder_state;
    }
    else {
        data->enc_diff = 0;
        data->state = LV_INDEV_STATE_REL;        
    }
}
#endif
    static void lv_tick_task(void *arg)
    {
        (void)arg;

        lv_tick_inc(LV_TICK_PERIOD_MS);
    }

    
void lvgl_init(void)
{
    lv_init();

    lv_disp_draw_buf_init(&draw_buf, buf1, buf2, LCD_WIDTH * 20);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = LCD_WIDTH;
    disp_drv.ver_res = LCD_HEIGHT;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
    M5.getBoard() == m5::board_t::board_M5StackCore2;
        /*Initialize the (dummy) input device driver*/
        static lv_indev_drv_t indev_drv;
        lv_indev_drv_init(&indev_drv);
        indev_drv.type = LV_INDEV_TYPE_POINTER;
        indev_drv.read_cb = my_touchpad_read;
        lv_indev_drv_register(&indev_drv);
    
    #if (ENCODER_INPUT > 0)    
    if (encoder.getDevStatus()) {
        encoder_init();

        /*Register a encoder input device*/
        static lv_indev_drv_t indev_drv_encoder;
        lv_indev_drv_init(&indev_drv_encoder);
        indev_drv_encoder.type = LV_INDEV_TYPE_ENCODER;
        indev_drv_encoder.read_cb = encoder_read;
        indev_encoder = lv_indev_drv_register(&indev_drv_encoder);        
    }
#endif    
     


 xguisemap = xSemaphoreCreateMutex();
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task, .name = "periodic_gui"};
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(
        esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    xTaskCreate(example_lvgl_port_task, "LVGL", EXAMPLE_LVGL_TASK_STACK_SIZE, NULL, EXAMPLE_LVGL_TASK_PRIORITY, 
    &task_lv_handle);
}

void screen_firstpage_timer_cb(lv_timer_t *t)
{

        lv_label_set_text_fmt(guider_ui.screen_firstpage_label1, "Page Pertama:");
}

void screen_secondpage_timer_cb(lv_timer_t *t)
{

        lv_label_set_text_fmt(guider_ui.screen_secondpage_label2, "Page Kedua:");

}
void screen_thirdpage_timer_cb(lv_timer_t *t)
{

        lv_label_set_text_fmt(guider_ui.screen_thirdpage_label3, "Page Ketiga:");

}