#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "main.h"

#define LED0_Pin 								LL_GPIO_PIN_8
#define LED0_GPIO_Port 					GPIOA
#define LED0_CLK_ENABLE()				LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA)
#define LED1_Pin 								LL_GPIO_PIN_2
#define LED1_GPIO_Port 					GPIOD
#define LED1_CLK_ENABLE()				LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOD)

#define LED0_ON									LL_GPIO_ResetOutputPin(LED0_GPIO_Port, LED0_Pin)
#define LED0_OFF								LL_GPIO_SetOutputPin(LED0_GPIO_Port, LED0_Pin)
#define LED0_TOGGLE							LL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin)
#define LED1_ON									LL_GPIO_ResetOutputPin(LED1_GPIO_Port, LED1_Pin)
#define LED1_OFF								LL_GPIO_SetOutputPin(LED1_GPIO_Port, LED1_Pin)
#define LED1_TOGGLE							LL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin)

void LED_GPIO_Init(void);

#endif
