#ifndef __LCD_INIT_H
#define __LCD_INIT_H

#include "main.h"

//-----------------LCD端口定义---------------- 
#define SCLK_PORT			GPIOA
#define SCLK_PIN			GPIO_PIN_5

#define SDA_PORT			GPIOA
#define SDA_PIN				GPIO_PIN_7

#define RES_PORT			GPIOB
#define RES_PIN				GPIO_PIN_4

#define DC_PORT				GPIOC
#define DC_PIN				GPIO_PIN_12

#define CS_PORT				GPIOD
#define CS_PIN				GPIO_PIN_2

#define BLK_PORT			GPIOA
#define BLK_PIN				GPIO_PIN_15



#endif
