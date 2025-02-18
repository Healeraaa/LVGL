/**
 ****************************************************************************************************
 * @file        lv_mainstart.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-03-23
 * @brief       中文字库应用课堂代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 阿波罗 F429开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */
 
#include "LVGL/GUI_APP/lv_mainstart.h"
#include "lvgl.h"
#include <stdio.h>


LV_FONT_DECLARE(Font30)       /* 声明字体 */

void lv_mainstart(void)
{
    lv_obj_t *font_label = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(font_label, &Font30, LV_STATE_DEFAULT);
    lv_label_set_text(font_label, "你好，正点原子");
    lv_obj_center(font_label);
}


