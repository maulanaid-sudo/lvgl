#include <Arduino.h>
#include <M5Unified.h>
#include <lvgl.h>
#include <esp_timer.h>

static lv_indev_drv_t lv_indev;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[LCD_WIDTH * 20];

static lv_color_t buf2[LCD_WIDTH * 20];
const uint32_t LV_TICK_PERIOD_MS;


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
if (touched) {
        data->point.x = touchX;
        data->point.y = touchY;
        data->state = LV_INDEV_STATE_PR;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }
     
    }



// continue setup code
void setup() {


  M5.begin();
  M5.Display.begin();
  M5.Display.setEpdMode(epd_mode_t::epd_fastest);

  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf1, buf2, LCD_WIDTH * 20);


  static lv_disp_drv_t display;
  lv_disp_drv_init(&display);
  display.hor_res = LCD_WIDTH;
  display.ver_res = LCD_HEIGHT;
  display.flush_cb = my_disp_flush;
  display.draw_buf = &draw_buf;
 lv_disp_drv_register(&display);

  lv_indev_drv_init(&lv_indev);
  lv_indev.type=LV_INDEV_TYPE_POINTER;
  lv_indev.read_cb = my_touchpad_read;
  lv_indev_drv_register(&lv_indev);

    // Menggunakan timer atau task untuk memanggil lv_tick_inc()
     
    xTaskCreate([](void*) {
        while(true) {
            lv_tick_inc(LV_TICK_PERIOD_MS);
            vTaskDelay(LV_TICK_PERIOD_MS / portTICK_PERIOD_MS);
        }
    }, "lv_tick_task", 2048, nullptr, 1, nullptr);
   
}

void loop() {
  lv_task_handler();
  vTaskDelay(1);
}