#include "main.h"
//#include <examples/porting/lv_port_disp_template.h>
#include <WiFi.h>
#include "lvgl_porting.h"

TaskHandle_t task_firstpage_handle    = NULL;

//  void task_firstpage(void * pvParameters){

//  }

void setup() {
    M5.begin();
    M5.Display.begin();
    M5.Display.setEpdMode(epd_mode_t::epd_fastest);
    lvgl_init();
    //lv_port_disp_init();
    
}
 

void loop() {

}
