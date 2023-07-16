#include "bsp_key.h"

void KEY_EXTI_Init(void)
{
	LL_EXTI_InitTypeDef EXTI_InitStruct;
	
	/* GPIO Ports Clock Enable */
	WKUP_CLK_ENABLE;
	
	LL_GPIO_AF_SetEXTISource(WKUP_EXTI_Port, WKUP_EXTI_Line);
	
	EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_0;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING;
  LL_EXTI_Init(&EXTI_InitStruct);
	
	LL_GPIO_SetPinPull(WKUP_GPIO_Port, WKUP_Pin, LL_GPIO_PULL_DOWN);
	
	LL_GPIO_SetPinMode(WKUP_GPIO_Port, WKUP_Pin, LL_GPIO_MODE_INPUT);
	
	/* EXTI interrupt init*/
  NVIC_SetPriority(EXTI0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI0_IRQn);
}
