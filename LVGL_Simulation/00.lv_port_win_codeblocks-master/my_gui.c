#include "my_gui.h"
#include "lvgl.h"

void my_gui(void)
{
    lv_obj_t* switch1 = lv_switch_create(lv_scr_act());//lv_scr_act（）获取父对象屏幕
    lv_obj_set_size(switch1, 120, 60);
    lv_obj_t* switch2 = lv_switch_create(switch1);
    //lv_obj_set_size(switch1, 120, 60);
}
