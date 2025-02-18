/**
 ****************************************************************************************************
 * @file        main.c
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2022-4-20
 * @brief       LVGL��ֲ���ô���1 ʵ��
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
#include "./BSP/TOUCH/touch.h"
#include "./BSP/TIMER/btim.h"
#include "lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "lv_demo_stress.h"
#include "lv_demo_music.h"

int main(void)
{
    HAL_Init();                              /* ��ʼ��HAL�� */
    sys_stm32_clock_init(360, 25, 2, 8);     /* ����ʱ��,180Mhz */
    delay_init(180);                         /* ��ʱ��ʼ�� */
    usart_init(115200);                      /* ��ʼ��USART */
    led_init();                              /* ��ʼ��LED */
    key_init();                              /* ��ʼ������ */
    sdram_init();                            /* ��ʼ��SDRAM */

    btim_timx_int_init(10-1, 9000-1);
    lv_init(); 
    lv_port_disp_init(); 
    lv_port_indev_init();

//    lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
//    lv_obj_set_size(switch_obj, 120, 60);
//    lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);

//    lv_demo_stress();
     lv_demo_music();
    
    while(1)
    {
        delay_ms(5);
        lv_timer_handler();
    }
}

