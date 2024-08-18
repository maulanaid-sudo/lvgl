#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "main.h"
#include "lvgl_porting.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

uint8_t btn_status[3]={0};

static lv_timer_t *screen_firstpage_update_data_task;
static lv_timer_t *screen_secondpage_update_data_task;
static lv_timer_t *screen_thirdpage_update_data_task;

static void screen_firstpage_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SCREEN_LOADED:
    {

        screen_firstpage_update_data_task = lv_timer_create(screen_firstpage_timer_cb, 10, &guider_ui);

         break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        lv_timer_del(screen_firstpage_update_data_task);
         break;
    }
    default:
    break;
       
    }

}

static void screen_firstpage_btn_1_event_handler (lv_event_t *e)
{
   lv_event_code_t code = lv_event_get_code(e);
   switch (code)

   {
   case LV_EVENT_CLICKED:
   {
   /* code */
    ui_load_scr_animation(&guider_ui, &guider_ui.screen_secondpage, guider_ui.screen_secondpage_del, &guider_ui.screen_firstpage_del, setup_scr_secondpage, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, false, true);
    break;
   }
 
   
   default:
    break;
   } 
}

void events_init_screen_firstpage(lv_ui *ui)
{
  	lv_obj_add_event_cb(ui->screen_firstpage, screen_firstpage_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_firstpage_btn_1, screen_firstpage_btn_1_event_handler, LV_EVENT_ALL, NULL);
  
}


static void screen_secondpage_event_handler (lv_event_t *e){
    lv_event_code_t code = lv_event_get_code(e);
    switch (code){
    case LV_EVENT_SCREEN_LOADED:
    {
        screen_secondpage_update_data_task = lv_timer_create(screen_secondpage_timer_cb, 100, &guider_ui);
         break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        lv_timer_del(screen_secondpage_update_data_task);
         break;
    }
    default:
       break;
    }

}

static void screen_secondpage_btn_2_event_handler (lv_event_t *e)
{
   lv_event_code_t code = lv_event_get_code(e);
   switch (code)

   {
   case LV_EVENT_CLICKED:
   {
   /* code */
    ui_load_scr_animation(&guider_ui, &guider_ui.screen_thirdpage, guider_ui.screen_thirdpage_del, &guider_ui.screen_secondpage_del, setup_scr_thirdpage, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, false, true);
    break;
   }
 
   
   default:
    break;
   } 
}

void events_init_screen_secondpage(lv_ui *ui)
{
  	lv_obj_add_event_cb(ui->screen_secondpage, screen_secondpage_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_secondpage_btn_2, screen_secondpage_btn_2_event_handler, LV_EVENT_ALL, NULL);
  
}



static void screen_thirdpage_event_handler (lv_event_t *e){
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SCREEN_LOADED:
    {
        screen_thirdpage_update_data_task = lv_timer_create(screen_thirdpage_timer_cb, 10, &guider_ui);

         break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        lv_timer_del(screen_thirdpage_update_data_task);
         break;
    }
       
    
    default:
       break;
    }

}

static void screen_thirdpage_btn_3_event_handler (lv_event_t *e)
{
   lv_event_code_t code = lv_event_get_code(e);
   switch (code)

   {
   case LV_EVENT_CLICKED:
   {
   /* code */
    ui_load_scr_animation(&guider_ui, &guider_ui.screen_firstpage, guider_ui.screen_firstpage_del, &guider_ui.screen_thirdpage_del, setup_scr_firstpage, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, false, true);
    break;
   }
 
   
   default:
    break;
   } 
}

void events_init_screen_thirdpage(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_thirdpage, screen_thirdpage_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_thirdpage_btn_3, screen_thirdpage_btn_3_event_handler, LV_EVENT_ALL, NULL);
  
}
void events_init(lv_ui *ui)
{

}
