#include "my_gui.h"
#include "lvgl.h"
#include <stdio.h>

lv_obj_t *switch1;

static void my_event_cb(lv_event_t *event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        if(lv_obj_has_state(switch1, LV_STATE_CHECKED))
        {
            printf("SWITCH ON\n");
        }
        else
        {
            printf("SWITCH OFF\n");
        }
    }

}

void my_gui(void)
{
    /*开关部件*/
    switch1 = lv_switch_create(lv_scr_act());

    lv_obj_set_size(switch1,100,50);                                                /* 大小 */
    lv_obj_set_align(switch1,LV_ALIGN_CENTER);                                      /* 对齐 */
    lv_obj_set_style_bg_color(switch1, lv_color_hex(0xf03af7),LV_PART_MAIN);    /* 背景颜色 */
    lv_obj_set_style_bg_color(switch1, lv_color_hex(0x9898d9),LV_STATE_CHECKED | LV_PART_INDICATOR  );
                                                                    /*单独设置LV_PART_INDICATOR时，
                                                                    是默认状态的指示器颜色，当开关
                                                                    按下时，状态会发生改变。所以此时
                                                                    按下开关并不会显示设置的指示器颜色
                                                                    LV_STATE_CHECKED | LV_PART_INDICATOR
                                                                    则表示被选中时，指示器的颜色，故可正常显示。
                                                                    */
    lv_obj_add_state(switch1,LV_STATE_CHECKED);                     //添加选中状态
    lv_obj_clear_state(switch1,LV_STATE_CHECKED);                   //清除选中状态
    lv_obj_add_state(switch1,LV_STATE_CHECKED | LV_STATE_DISABLED); //添加选中状态并且不可修改
    lv_obj_clear_state(switch1,LV_STATE_CHECKED | LV_STATE_DISABLED); //删除选中状态和不可修改

    lv_obj_add_event_cb(switch1,my_event_cb,LV_EVENT_VALUE_CHANGED,NULL);//添加事件：对象的值已更改


}






















