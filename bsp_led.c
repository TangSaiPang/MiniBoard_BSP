#include "bsp_led.h"

void LED_GPIO_Init(void)
{
	LL_GPIO_InitTypeDef LED_GPIO_Init;
	
	LED0_CLK_ENABLE();
	LED1_CLK_ENABLE();
	
	LED0_OFF;
	LED1_OFF;
	
  LED_GPIO_Init.Pin = LED0_Pin;
  LED_GPIO_Init.Mode = LL_GPIO_MODE_OUTPUT;
  LED_GPIO_Init.Speed = LL_GPIO_SPEED_FREQ_HIGH;
  LED_GPIO_Init.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  LL_GPIO_Init(LED0_GPIO_Port, &LED_GPIO_Init);
	
	LED_GPIO_Init.Pin = LED1_Pin;
  LL_GPIO_Init(LED1_GPIO_Port, &LED_GPIO_Init);
}	
