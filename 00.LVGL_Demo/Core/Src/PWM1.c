#include "PWM1.h"

#define AUTORELOAD 65535 //PWM1自动重装载值

void PWM1_Init(void)
{
  // 定义并初始化TIM和OC（Output Compare）结构体
  LL_TIM_InitTypeDef TIM_InitStruct = {0};
  LL_TIM_OC_InitTypeDef TIM_OC_InitStruct = {0};

  // 定义并初始化GPIO结构体
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  // 使能TIM3时钟，TIM3挂载在APB1总线上
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);

  // 配置TIM3的基本参数
  TIM_InitStruct.Prescaler = 0;                             // 预分频器为0，即不分频
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;       // 向上计数模式
  TIM_InitStruct.Autoreload = AUTORELOAD;                        // 自动重装载值，最大为65535
  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1; // 时钟分频为1
  LL_TIM_Init(TIM3, &TIM_InitStruct);                       // 初始化TIM3

  // 禁用TIM3的自动重装载预装载功能
  LL_TIM_DisableARRPreload(TIM3);

  // 使能TIM3通道3的输出比较预装载功能
  LL_TIM_OC_EnablePreload(TIM3, LL_TIM_CHANNEL_CH3);

  // 配置TIM3通道3的输出比较模式
  TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;                // PWM模式1
  TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;           // 初始状态下禁用输出比较
  TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;          // 初始状态下禁用互补输出比较
  TIM_OC_InitStruct.CompareValue = 0;                           // 比较值为0，即占空比为0%
  TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;        // 输出极性为高电平有效
  LL_TIM_OC_Init(TIM3, LL_TIM_CHANNEL_CH3, &TIM_OC_InitStruct); // 初始化TIM3通道3

  // 禁用TIM3通道3的快速输出比较模式
  LL_TIM_OC_DisableFast(TIM3, LL_TIM_CHANNEL_CH3);

  // 设置TIM3的触发输出为复位
  LL_TIM_SetTriggerOutput(TIM3, LL_TIM_TRGO_RESET);

  // 禁用TIM3的主从模式
  LL_TIM_DisableMasterSlaveMode(TIM3);

  // 使能GPIOB时钟，GPIOB挂载在AHB1总线上
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

  // 配置GPIOB的Pin 0为复用功能
  GPIO_InitStruct.Pin = LL_GPIO_PIN_0;                  // 选择Pin 0
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;        // 复用模式
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;       // 低速模式
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL; // 推挽输出
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;               // 无上下拉电阻
  GPIO_InitStruct.Alternate = LL_GPIO_AF_2;             // 复用功能选择AF2（TIM3）
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);                // 初始化GPIOB

  // 启动TIM3计数器
  LL_TIM_EnableCounter(TIM3);

  // 使能TIM3通道3的输出
  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH3);

  // 设置占空比（0%占空比）
  LL_TIM_OC_SetCompareCH3(TIM3, 0);
}

/**
  * @brief  设置 TIM3 通道 3 的 PWM 占空比
  * @param  duty_cycle: PWM 占空比，范围为 0 ~ 100（0% ~ 100%）
  * @retval None
  */
void PWM1_SetDutyCycle(uint8_t duty_cycle)
{
  // 确保占空比在有效范围内（0 ~ 100）
  if (duty_cycle > 100)
  {
    duty_cycle = 100; // 如果超过 100%，则限制为 100%
  }

  // 计算比较值
  // 公式：CompareValue = (Autoreload + 1) * (duty_cycle / 100)
  // 其中 Autoreload 是 TIM3 的自动重装载值
  uint32_t compare_value = (AUTORELOAD + 1) * duty_cycle / 100;

  // 设置 TIM3 通道 3 的比较值
  LL_TIM_OC_SetCompareCH3(TIM3, compare_value);
}