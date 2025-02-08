/* Private includes -----------------------------------------------------------*/
#include "user_TasksInit.h"
#include "AToD.h"
#include "stdio.h"
#include "OLED.h"
#include "key.h"
#include "LED.h"

/* Private typedef -----------------------------------------------------------*/
#define EVENT_BIT1 (1 << 1)
#define EVENT_BIT2 (1 << 2)
/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Timers --------------------------------------------------------------------*/

/* Tasks ---------------------------------------------------------------------*/
TaskHandle_t KeyScanf_Task_Handler;
TaskHandle_t LEDToggle_Task_Handler;
TaskHandle_t SerialSend_Task_Handler;

/* Queues --------------------------------------------------------------------*/

/* Events --------------------------------------------------------------------*/
EventGroupHandle_t eventgrount_handle;

/**
 * @brief  按键读取任务
 * @param  argument: Not used
 * @retval None
 */

void KeyScanf_Task(void *argument)
{
  /* 申请内存以及释放内存，并显示空闲内存大小 */
  uint8_t KeyNum = 0,t = 0;
  uint8_t * buff = NULL;
  while (1)
  {
    KeyNum = Key_GetNum(0);
    if(KeyNum == KEY1_PRES)
    {
      /* 申请内存 */
      buff = pvPortMalloc(30);
      if(buff != NULL)
      {
        printf("内存申请成功！！！\r\n");
      }
      else
      {
        printf("内存申请失败！！！\r\n");
      }

    }
    else if(KeyNum == KEY2_PRES)
    {
      /* 释放内存 */
      if(buff != NULL)
      {
        vPortFree(buff);
        printf("释放内存！！！\r\n");
        buff = NULL;
      }
    }
    if(t++ > 50)
    {
      t = 0;
      printf("剩余的空闲内存大小为：%d\r\n",xPortGetFreeHeapSize());
    }
    
    vTaskDelay(20);
  }
}

/**
 * @brief  LED间隔0.5s闪烁一次
 * @param  argument: Not used
 * @retval None
 */
void LEDToggle_Task(void *argument)
{
  while (1)
  {
    LED_Reveral();
    vTaskDelay(500);
  }
}
/**
 * @brief  UART串口打印进行数据显示
 * @param  argument: Not used
 * @retval None
 */
void SerialSend_Task(void *argument)
{
  while (1)
  {
    vTaskDelay(1000);
  }
}

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void User_Tasks_Init(void)
{
  

  xTaskCreate(KeyScanf_Task, "KeyScanf_Task", 128, NULL, 2, &KeyScanf_Task_Handler);
  xTaskCreate(LEDToggle_Task, "LEDToggle_Task", 128, NULL, 1, &LEDToggle_Task_Handler);
  xTaskCreate(SerialSend_Task, "SerialSend_Task", 128, NULL, 3, &SerialSend_Task_Handler);
}
