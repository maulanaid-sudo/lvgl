#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
void setup_scr_secondpage(lv_ui *ui)
{
    ui->screen_secondpage = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_secondpage, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_secondpage, LV_SCROLLBAR_MODE_OFF);
    
	lv_obj_set_style_bg_opa(ui->screen_secondpage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);


    ui->screen_secondpage_label2 = lv_label_create(ui->screen_secondpage);
	lv_label_set_text(ui->screen_secondpage_label2, "halaman pertama");
	lv_label_set_long_mode(ui->screen_secondpage_label2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_secondpage_label2, 50, 100);
	lv_obj_set_size(ui->screen_secondpage_label2, 290, 52);

	//Write style for screen_rs485_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_secondpage_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_secondpage_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_secondpage_label2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_secondpage_label2, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_secondpage_label2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_secondpage_label2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_secondpage_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_secondpage_label2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_secondpage_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_secondpage_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_secondpage_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_secondpage_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_secondpage_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_secondpage_label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);


    ui->screen_secondpage_btn_2 = lv_btn_create(ui->screen_secondpage);
	ui->screen_second_btn_2_label = lv_label_create(ui->screen_secondpage_btn_2);
	lv_label_set_text(ui->screen_second_btn_2_label, "Next");
	lv_label_set_long_mode(ui->screen_second_btn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_second_btn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_secondpage_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_secondpage_btn_2, 120, 200);
	lv_obj_set_size(ui->screen_secondpage_btn_2, 80, 40);

	//Write style for screen_rs485_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_secondpage_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_secondpage_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_secondpage_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_secondpage_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_secondpage_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_secondpage_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_secondpage_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_secondpage_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_secondpage_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_secondpage_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen_rs485.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_secondpage);

	//Init events for screen.
	events_init_screen_secondpage(ui);


}