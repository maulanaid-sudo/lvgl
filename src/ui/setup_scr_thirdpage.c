#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
void setup_scr_thirdpage(lv_ui *ui)
{
    ui->screen_thirdpage = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_thirdpage, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_thirdpage, LV_SCROLLBAR_MODE_OFF);
    
	lv_obj_set_style_bg_opa(ui->screen_thirdpage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);


    ui->screen_thirdpage_label3 = lv_label_create(ui->screen_thirdpage);
	lv_label_set_text(ui->screen_thirdpage_label3, "halaman pertama");
	lv_label_set_long_mode(ui->screen_thirdpage_label3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_thirdpage_label3, 50, 100);
	lv_obj_set_size(ui->screen_thirdpage_label3, 290, 52);

	//Write style for screen_rs485_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_thirdpage_label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_thirdpage_label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_thirdpage_label3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_thirdpage_label3, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_thirdpage_label3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_thirdpage_label3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_thirdpage_label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_thirdpage_label3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_thirdpage_label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_thirdpage_label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_thirdpage_label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_thirdpage_label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_thirdpage_label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_thirdpage_label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);


    ui->screen_thirdpage_btn_3 = lv_btn_create(ui->screen_thirdpage);
	ui->screen_thirdpage_btn_3_label = lv_label_create(ui->screen_thirdpage_btn_3);
	lv_label_set_text(ui->screen_thirdpage_btn_3_label, "Next");
	lv_label_set_long_mode(ui->screen_thirdpage_btn_3_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_thirdpage_btn_3_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_thirdpage_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_thirdpage_btn_3, 120, 200);
	lv_obj_set_size(ui->screen_thirdpage_btn_3, 80, 40);

	//Write style for screen_rs485_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_thirdpage_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_thirdpage_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_thirdpage_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_thirdpage_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_thirdpage_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_thirdpage_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_thirdpage_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_thirdpage_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_thirdpage_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_thirdpage_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen_rs485.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_thirdpage);

	//Init events for screen.
	events_init_screen_thirdpage(ui);


}