/**
 ****************************************************************************************************
 * @file        spi.h
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-4-20
 * @brief       SPI 驱动代码
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
 * 修改说明
 * V1.0 20220420
 * 第一次发布
 *
 ****************************************************************************************************
 */
 
#ifndef __SPI_H
#define __SPI_H

#include "./SYSTEM/sys/sys.h"

/******************************************************************************************/
/* SPI5 引脚 定义 */

#define SPI5_SCK_GPIO_PORT              GPIOF
#define SPI5_SCK_GPIO_PIN               GPIO_PIN_7
#define SPI5_SCK_GPIO_CLK_ENABLE()      do{ __HAL_RCC_GPIOF_CLK_ENABLE(); }while(0)   /* PF口时钟使能 */

#define SPI5_MISO_GPIO_PORT             GPIOF
#define SPI5_MISO_GPIO_PIN              GPIO_PIN_8
#define SPI5_MISO_GPIO_CLK_ENABLE()     do{ __HAL_RCC_GPIOF_CLK_ENABLE(); }while(0)   /* PF口时钟使能 */

#define SPI5_MOSI_GPIO_PORT             GPIOF
#define SPI5_MOSI_GPIO_PIN              GPIO_PIN_9
#define SPI5_MOSI_GPIO_CLK_ENABLE()     do{ __HAL_RCC_GPIOF_CLK_ENABLE(); }while(0)   /* PF口时钟使能 */

/* SPI5相关定义 */
#define SPI5_SPI                        SPI5
#define SPI5_SPI_CLK_ENABLE()           do{ __HAL_RCC_SPI5_CLK_ENABLE(); }while(0)    /* SPI5时钟使能 */

/******************************************************************************************/


extern SPI_HandleTypeDef g_spi5_handle;  /* SPI句柄 */

void spi5_init(void);
void spi5_set_speed(uint8_t SPI_BaudRatePrescaler);
uint8_t spi5_read_write_byte(uint8_t TxData);

#endif
