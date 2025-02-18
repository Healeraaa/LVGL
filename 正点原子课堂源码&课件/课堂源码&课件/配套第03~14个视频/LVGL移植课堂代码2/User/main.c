/**
 ****************************************************************************************************
 * @file        main.c
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2022-4-20
 * @brief       LVGL��ֲ���ô���2 ʵ��
 * @license     Copyright (c) 2020-2032, ������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ʵ��ƽ̨:����ԭ�� ������ F429������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/LCD/lcd.h"
#include "./BSP/KEY/key.h"
#include "./BSP/SDRAM/sdram.h"
#include "lvgl_demo.h"

int main(void)
{
    HAL_Init();                              /* ��ʼ��HAL�� */
    sys_stm32_clock_init(360, 25, 2, 8);     /* ����ʱ��,180Mhz */
    delay_init(180);                         /* ��ʱ��ʼ�� */
    usart_init(115200);                      /* ��ʼ��USART */
    led_init();                              /* ��ʼ��LED */
    key_init();                              /* ��ʼ������ */
    sdram_init();                            /* ��ʼ��SDRAM */

//    lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
//    lv_obj_set_size(switch_obj, 120, 60);
//    lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);

//    lv_demo_stress();
//     lv_demo_music();
    lvgl_demo();
    while(1)
    {
    }
}

