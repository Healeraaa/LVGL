/* Private includes -----------------------------------------------------------*/
#include "user_TasksInit.h"
#include "lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "stdio.h"
// #include "OLED.h"
// #include "key.h"
#include "LED.h"
#include "ui.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Timers --------------------------------------------------------------------*/

/* Tasks ---------------------------------------------------------------------*/
TaskHandle_t SPITEST_Task_Handler;
TaskHandle_t LEDToggle_Task_Handler;
TaskHandle_t RGBLEDToggle_Task_Handler;
TaskHandle_t LvHandlerTask_Handle;
TaskHandle_t LVGL_Task_Handler;

/* Queues --------------------------------------------------------------------*/

/* Events --------------------------------------------------------------------*/

// 定义互斥锁
SemaphoreHandle_t xMutex;

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
 * @brief  RGB间隔0.5s变化一次
 * @param  argument: Not used
 * @retval None
 */
void RGBLEDToggle_Task(void *argument)
{
  uint8_t Color = 0;
  while (1)
  {
    (++Color > 6) ? (Color = 0) : (Color = Color);
    LED1_RGB_ON(Color);
    vTaskDelay(500);
  }
}

/**
 * @brief  LVGL实验
 * @param  argument: Not used
 * @retval None
 */
void LVGL_Task(void *argument)
{
  // ui_init();
  // lv_obj_t *switch_obj = lv_switch_create(lv_scr_act());
  // lv_obj_set_size(switch_obj, 100, 50);
  // lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);

  // LED_ON();
  while (1)
  {
    // 使用互斥锁来保护LVGL操作
    if (pdTRUE == xSemaphoreTake(xMutex, portMAX_DELAY))
    {
      xSemaphoreGive(xMutex); // 释放互斥锁
    }
    vTaskDelay(500);
  }
}

void LvHandlerTask(void *argument);

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void User_Tasks_Init(void)
{
  // 创建互斥锁
  xMutex = xSemaphoreCreateMutex();

  xTaskCreate(LvHandlerTask, "LvHandlerTask", 128 * 24, NULL, 3, &LvHandlerTask_Handle);
  xTaskCreate(LVGL_Task, "LVGL_Task", 128, NULL, 3, &LVGL_Task_Handler);
  xTaskCreate(LEDToggle_Task, "LEDToggle_Task", 128, NULL, 1, &LEDToggle_Task_Handler);
  xTaskCreate(RGBLEDToggle_Task, "RGBLEDToggle_Task", 128, NULL, 1, &RGBLEDToggle_Task_Handler);
}

/**
 * @brief  FreeRTOS Tick Hook, to increase the LVGL tick
 * @param  None
 * @retval None
 */
void TaskTickHook(void)
{
  // to increase the LVGL tick
  lv_tick_inc(1);
  // to increase the timerpage's timer(put in here is to ensure the Real Time)
}

/**
 * @brief  LVGL Handler task, to run the lvgl
 * @param  argument: Not used
 * @retval None
 */
void LvHandlerTask(void *argument)
{
  while (1)
  {
    if (pdTRUE == xSemaphoreTake(xMutex, portMAX_DELAY))
    {
      lv_task_handler();      // 执行LVGL的任务处理
      xSemaphoreGive(xMutex); // 释放互斥锁
    }
    vTaskDelay(5);
  }
}
