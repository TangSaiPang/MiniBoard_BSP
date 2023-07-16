#ifndef __BSP_USART_H
#define __BSP_USART_H

#include "main.h"
#include <stdio.h>

#define USART1_RX_Pin						LL_GPIO_PIN_10
#define USART1_TX_Pin						LL_GPIO_PIN_9
#define USART1_GPIO_Port				GPIOA
#define USART1_GPIO_CLK_ENABLE	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA)
#define USART1_CLK_ENABLE				LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1)
#define USART1_BaudRate					115200

void DEBUG_USART1_Init(void);

#endif
