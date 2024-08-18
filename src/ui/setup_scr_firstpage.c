#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
void setup_scr_firstpage(lv_ui *ui)
{
    ui->screen_firstpage = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_firstpage, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_firstpage, LV_SCROLLBAR_MODE_OFF);
    
		//Write style for screen_rs485, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_firstpage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);


    ui->screen_firstpage_label1 = lv_label_create(ui->screen_firstpage);
	lv_label_set_text(ui->screen_firstpage_label1, "halaman pertama");
	lv_label_set_long_mode(ui->screen_firstpage_label1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_firstpage_label1, 50, 100);
	lv_obj_set_size(ui->screen_firstpage_label1, 290, 52);

	//Write style for screen_rs485_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_firstpage_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_firstpage_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_firstpage_label1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_firstpage_label1, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_firstpage_label1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_firstpage_label1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_firstpage_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_firstpage_label1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_firstpage_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_firstpage_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_firstpage_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_firstpage_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_firstpage_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_firstpage_label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);


    ui->screen_firstpage_btn_1 = lv_btn_create(ui->screen_firstpage);
	ui->screen_firstpage_btn_1_label = lv_label_create(ui->screen_firstpage_btn_1);
	lv_label_set_text(ui->screen_firstpage_btn_1_label, "Next");
	lv_label_set_long_mode(ui->screen_firstpage_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_firstpage_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_firstpage_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_firstpage_btn_1, 120, 200);
	lv_obj_set_size(ui->screen_firstpage_btn_1, 80, 40);

	//Write style for screen_rs485_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_firstpage_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_firstpage_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_firstpage_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_firstpage_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_firstpage_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_firstpage_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_firstpage_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_firstpage_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_firstpage_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_firstpage_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen_rs485.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_firstpage);

	//Init events for screen.
	events_init_screen_firstpage(ui);

	
	


}