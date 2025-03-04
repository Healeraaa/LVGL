#include "my_gui.h"
#include "lvgl.h"
#include <stdio.h>

lv_obj_t * obj1;
lv_obj_t * obj2;
static void my_event_cb(lv_event_t * event);

void my_gui(void)
{
    //lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
    //lv_obj_set_size(switch_obj, 120, 60);
    //lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);

    /*
    部件的基本属性
    1.大小（size）
    2.位置（position）
    3.对齐（alignment）
    4.样式（styles）
    5.事件（events）
    */
////    1.大小（size）
//    lv_obj_t *obj1 = lv_obj_create(lv_scr_act());
//    lv_obj_set_width(obj1, 200);
//    lv_obj_set_height(obj1, 100);
//    lv_obj_set_size(obj1, 200, 200);

////    2.位置（position）
//    lv_obj_t *obj1 = lv_obj_create(lv_scr_act());
//    lv_obj_set_x(obj1, 40);
//    lv_obj_set_y(obj1, 40);
//    lv_obj_set_pos(obj1, 20, 80);

////    3.对齐（alignment）
//    lv_obj_t *obj1 = lv_obj_create(lv_scr_act());
////    3.1.参照父对象对齐
//    lv_obj_set_align(obj1, LV_ALIGN_CENTER);
////    3.2.参照父对象对齐，再进行偏移
//    lv_obj_align(obj1, LV_ALIGN_CENTER, 50, 50);
////    3.3.参照其他对象对齐（无父子关系）
//    lv_obj_t *obj2 = lv_obj_create(lv_scr_act());
//    lv_obj_set_size(obj1, 100, 100);
//    lv_obj_set_pos(obj2, 0, 0);
//    lv_obj_align_to(obj2, obj1, LV_ALIGN_OUT_RIGHT_MID, 0, 0);

////    4.样式（styles）
////    4.1添加样式
////    4.1.1添加普通样式
//    static lv_style_t style; 									                /* 定义样式变量 */
//    lv_style_init(&style); 									                /* 初始化样式 */
//    lv_style_set_bg_color(&style, lv_color_hex(0xe8e560)); 				    /* 设置背景颜色 */
//    lv_obj_t * obj1 = lv_obj_create(lv_scr_act()); 						    /* 创建一个部件 */
//    lv_obj_add_style(obj1, & style, LV_STATE_DEFAULT); 					    /* 设置部件的样式 */

////    4.1.1添加本地样式
//    lv_obj_t * obj1 = lv_obj_create(lv_scr_act()); 						        /* 创建一个部件 */
//    lv_obj_set_style_bg_color(obj1, lv_color_hex(0xf4b183),LV_STATE_PRESSED);	/* 设置部件的样式 */

////    4.2.设置边框样式
//    lv_obj_t * obj1 = lv_obj_create(lv_scr_act());
//    lv_obj_align(obj1, LV_ALIGN_CENTER, 0, 0);
//    lv_obj_set_style_border_color(obj1,lv_color_hex(0xf4b183),LV_STATE_DEFAULT);//边框颜色
//    lv_obj_set_style_border_width(obj1,10,LV_STATE_DEFAULT);//边框宽度
//    lv_obj_set_style_border_opa(obj1,50,LV_STATE_DEFAULT);//边框透明度

////    4.3.设置轮廓样式
//    lv_obj_t * obj1 = lv_obj_create(lv_scr_act());
//    lv_obj_align(obj1, LV_ALIGN_CENTER, 0, 0);
//    lv_obj_set_style_outline_color(obj1,lv_color_hex(0xf4b183),LV_STATE_DEFAULT);//轮廓颜色
//    lv_obj_set_style_outline_width(obj1,10,LV_STATE_DEFAULT);//轮廓宽度
//    lv_obj_set_style_outline_opa(obj1,50,LV_STATE_DEFAULT);//轮廓透明度

////    4.4.单独设置部件某个部分的样式
//    lv_obj_t * slider = lv_slider_create(lv_scr_act());//滑块部件
//    lv_obj_set_size(slider, 100, 20);
//    lv_obj_set_align(slider, LV_ALIGN_CENTER);
//    lv_obj_set_style_bg_color(slider,lv_color_hex(0xf4b183),LV_STATE_DEFAULT | LV_PART_INDICATOR);//修改指示器（LV_PART_INDICATOR）样式
//    lv_obj_set_style_bg_color(slider,lv_color_hex(0xf4b183),LV_STATE_DEFAULT | LV_PART_KNOB);//修改手柄（LV_PART_KNOB）样式

//    5.事件（events）
    obj1 = lv_obj_create(lv_scr_act());
    lv_obj_add_event_cb(obj1,my_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(obj1,my_event_cb,LV_EVENT_PRESSING,NULL);
    lv_obj_set_size(obj1, 200, 200);

    obj2 = lv_obj_create(lv_scr_act());
    lv_obj_add_event_cb(obj2,my_event_cb,LV_EVENT_CLICKED,NULL);


}

static void my_event_cb(lv_event_t * event)//事件回调函数
{
    lv_obj_t *target = lv_event_get_target(event);//获取触发事件的部件
    lv_event_code_t code = lv_event_get_code(event); //获取触发事件类型
    if(target == obj1)
    {
        if(code == LV_EVENT_CLICKED)
        {
            printf("obj1 LV_EVENT_CLICKED\n");
        }
        else if(code == LV_EVENT_PRESSING)
        {
            printf("obj1 LV_EVENT_PRESSING\n");
        }
    }
    else if(target == obj2)
    {
        if(code == LV_EVENT_CLICKED)
        {
            printf("obj2 LV_EVENT_CLICKED\n");
        }
    }


}


















