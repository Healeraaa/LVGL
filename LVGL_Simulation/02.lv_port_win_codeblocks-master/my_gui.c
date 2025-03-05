#include "my_gui.h"
#include "lvgl.h"
#include <stdio.h>



void my_gui(void)
{
    /*标签部件*/
    lv_obj_t *label = lv_label_create(lv_scr_act());

//    /*设置文本的三种方式*/
//    lv_label_set_text(label,"Hello lvgl");                                                  //直接设置文本，储存文本的内存动态分配
//    lv_label_set_text_static(label,"Hello\nlvgl");                                          //（慎用）文本不存储在动态内存，而是在指定的缓冲区中
//    lv_label_set_text_fmt(label,"Value:%d",50);                                             //格式化显示文本，类似printf
//
//    /*设置文本样式*/
//    lv_obj_set_style_bg_color( label, lv_color_hex(0xffe1d4), LV_STATE_DEFAULT );           //背景颜色
//    lv_obj_set_style_bg_opa(label,175,LV_STATE_DEFAULT);                                    //透明度
//    lv_obj_set_style_text_font( label, &lv_font_montserrat_30, LV_STATE_DEFAULT );          //字体大小
//    lv_obj_set_style_text_color( label, lv_color_hex(0xf7b37b), LV_STATE_DEFAULT );         //文本颜色
//
//    /*设置个别文本的字体颜色*/
//    lv_label_set_recolor( label, true ); 						                            // 开启重新着色功能
//    lv_label_set_text( label, "hallo #ff0000 lvgl# " );			                            // 单独设置颜色

    /*长文本模式*/
    lv_label_set_text(label,"Hello lvgl Hello lvgl Hello lvgl Hello lvgl Hello lvgl");
    lv_obj_set_size(label,100, 50);
    lv_label_set_long_mode(label, LV_LABEL_LONG_CLIP);             /*LV_LABEL_LONG_WRAP,默认模式, 如果部件大小已固定，超出的文本将被剪切
                                                                    LV_LABEL_LONG_DOT,将 label 右下角的最后 3 个字符替换为点…
                                                                    LV_LABEL_LONG_SCROLL, 来回滚动
                                                                    LV_LABEL_LONG_SCROLL_CIRCULAR,循环滚动
                                                                    LV_LABEL_LONG_CLIP,直接剪切掉部件外面的文本部分 */



}






















