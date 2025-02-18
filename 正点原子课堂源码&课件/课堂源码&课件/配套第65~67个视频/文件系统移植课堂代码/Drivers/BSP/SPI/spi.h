/**
 ****************************************************************************************************
 * @file        spi.h
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2022-4-20
 * @brief       SPI ��������
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
 * �޸�˵��
 * V1.0 20220420
 * ��һ�η���
 *
 ****************************************************************************************************
 */
 
#ifndef __SPI_H
#define __SPI_H

#include "./SYSTEM/sys/sys.h"

/******************************************************************************************/
/* SPI5 ���� ���� */

#define SPI5_SCK_GPIO_PORT              GPIOF
#define SPI5_SCK_GPIO_PIN               GPIO_PIN_7
#define SPI5_SCK_GPIO_CLK_ENABLE()      do{ __HAL_RCC_GPIOF_CLK_ENABLE(); }while(0)   /* PF��ʱ��ʹ�� */

#define SPI5_MISO_GPIO_PORT             GPIOF
#define SPI5_MISO_GPIO_PIN              GPIO_PIN_8
#define SPI5_MISO_GPIO_CLK_ENABLE()     do{ __HAL_RCC_GPIOF_CLK_ENABLE(); }while(0)   /* PF��ʱ��ʹ�� */

#define SPI5_MOSI_GPIO_PORT             GPIOF
#define SPI5_MOSI_GPIO_PIN              GPIO_PIN_9
#define SPI5_MOSI_GPIO_CLK_ENABLE()     do{ __HAL_RCC_GPIOF_CLK_ENABLE(); }while(0)   /* PF��ʱ��ʹ�� */

/* SPI5��ض��� */
#define SPI5_SPI                        SPI5
#define SPI5_SPI_CLK_ENABLE()           do{ __HAL_RCC_SPI5_CLK_ENABLE(); }while(0)    /* SPI5ʱ��ʹ�� */

/******************************************************************************************/


extern SPI_HandleTypeDef g_spi5_handle;  /* SPI��� */

void spi5_init(void);
void spi5_set_speed(uint8_t SPI_BaudRatePrescaler);
uint8_t spi5_read_write_byte(uint8_t TxData);

#endif
