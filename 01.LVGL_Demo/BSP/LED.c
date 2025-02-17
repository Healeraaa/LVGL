#include "LED.h"

void LED_Init(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
	LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_13);
	GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
	LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void LED_ON(void)
{
	LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_13);
}

void LED_OFF(void)
{
	LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_13);
}

void LED_Reveral(void)
{
	LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_13);
}