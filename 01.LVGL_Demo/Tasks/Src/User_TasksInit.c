/* Private includes -----------------------------------------------------------*/
#include "user_TasksInit.h"
#include "lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "lv_demo_stress.h"
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
TaskHandle_t LvHandlerTask_Handle;
TaskHandle_t LVGL_Task_Handler;

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
    // LED_OFF();
    // LED_Reveral();
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
  lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
  lv_obj_set_size(switch_obj, 40, 20);
  lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);
  LED_ON();
  while (1)
  {
    vTaskDelay(10);
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
  xTaskCreate(LvHandlerTask, "LvHandlerTask", 128*48, NULL, 2, &LvHandlerTask_Handle);
  xTaskCreate(LVGL_Task, "LVGL_Task", 128*48, NULL, 3, &LVGL_Task_Handler);


  // xTaskCreate(SPITEST_Task, "SPITEST_Task", 128, NULL, 9, &SPITEST_Task_Handler);
  xTaskCreate(LEDToggle_Task, "LEDToggle_Task", 128, NULL, 1, &LEDToggle_Task_Handler);

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
    // LED_ON();
    lv_task_handler();
    vTaskDelay(5);
  }
}


