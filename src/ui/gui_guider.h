#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef  __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
   lv_obj_t *screen_firstpage;
   bool screen_firstpage_del;
   lv_obj_t *screen_firstpage_label1;
   lv_obj_t *screen_firstpage_btn_1;
   lv_obj_t *screen_firstpage_btn_1_label; 
   lv_obj_t *screen_secondpage;
   bool screen_secondpage_del; 
   lv_obj_t *screen_secondpage_label2;
   lv_obj_t *screen_secondpage_btn_2;
   lv_obj_t *screen_second_btn_2_label; 
       
   lv_obj_t *screen_thirdpage;
   bool screen_thirdpage_del; 
   lv_obj_t *screen_thirdpage_label3;
   lv_obj_t *screen_thirdpage_btn_3;
   lv_obj_t *screen_thirdpage_btn_3_label; 
    /* data */
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

extern lv_ui guider_ui;

void setup_scr_firstpage(lv_ui *ui);
void setup_scr_secondpage(lv_ui *ui);
void setup_scr_thirdpage(lv_ui *ui);
LV_FONT_DECLARE(lv_font_montserratMedium_24)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_48)


#ifdef __cplusplus
}
#endif
#endif
