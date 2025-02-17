/* Private includes -----------------------------------------------------------*/
#include "user_TasksInit.h"
#include "stdio.h"
// #include "OLED.h"
// #include "key.h"
#include "LED.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Timers --------------------------------------------------------------------*/

/* Tasks ---------------------------------------------------------------------*/
TaskHandle_t SPITEST_Task_Handler;
TaskHandle_t LEDToggle_Task_Handler;

/* Queues --------------------------------------------------------------------*/

/* Events --------------------------------------------------------------------*/

/**
 * @brief  测试SPI发送
 * @param  argument: Not used
 * @retval None
 */
void SPITEST_Task(void *argument)
{
  uint8_t data = 0;
  while (1)
  {
    vTaskDelay(1000);
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
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void User_Tasks_Init(void)
{
  

  xTaskCreate(SPITEST_Task, "SPITEST_Task", 128, NULL, 2, &SPITEST_Task_Handler);
  xTaskCreate(LEDToggle_Task, "LEDToggle_Task", 128, NULL, 1, &LEDToggle_Task_Handler);
  
}
