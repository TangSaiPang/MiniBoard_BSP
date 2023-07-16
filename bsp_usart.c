#include "bsp_usart.h"

#ifdef __GNUC__
/*
 * With GCC, small printf (option LD Linker -> Libraries -> Small printf
 * set to 'Yes') calls __io_putchar()
 * */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#define GETCHAR_PROTOTYPE int __io_getchar(FILE *f)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#endif

void DEBUG_USART1_Init(void)
{
	LL_USART_InitTypeDef USART_InitStruct;
	
	LL_GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Peripheral clock enable */
	USART1_CLK_ENABLE;
	USART1_GPIO_CLK_ENABLE;
	/**USART1 GPIO Configuration
  PA9   ------> USART1_TX
  PA10   ------> USART1_RX
  */
	
	GPIO_InitStruct.Pin = 				USART1_TX_Pin;
	GPIO_InitStruct.Mode = 				LL_GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Speed = 			LL_GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.OutputType = 	LL_GPIO_OUTPUT_PUSHPULL;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = 				USART1_RX_Pin;
  GPIO_InitStruct.Mode = 				LL_GPIO_MODE_FLOATING;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	USART_InitStruct.BaudRate = 						USART1_BaudRate;
  USART_InitStruct.DataWidth = 						LL_USART_DATAWIDTH_8B;
  USART_InitStruct.StopBits = 						LL_USART_STOPBITS_1;
  USART_InitStruct.Parity = 							LL_USART_PARITY_NONE;
  USART_InitStruct.TransferDirection = 		LL_USART_DIRECTION_TX_RX;
  USART_InitStruct.HardwareFlowControl = 	LL_USART_HWCONTROL_NONE;
  USART_InitStruct.OverSampling = 				LL_USART_OVERSAMPLING_16;
  LL_USART_Init(USART1, &USART_InitStruct);
  LL_USART_ConfigAsyncMode(USART1);
  LL_USART_Enable(USART1);
}


/**
	* 函数功能: 发送字节长度为8位的字符串
  * 输入参数: 通信串口，缓冲区指针，数据长度
  * 返 回 值: 无
  * 说    明: 
  */
void USARTx_Tx_Data(USART_TypeDef * UART, uint8_t *p_data, uint32_t size)
{
	while(size)
	{
    while(!LL_USART_IsActiveFlag_TXE(UART)){}//等待发送为空
		LL_USART_TransmitData8(UART,*p_data);	
		size--;
		p_data++;
	}
	while(LL_USART_IsActiveFlag_TC(UART)==RESET){}//等待发送完成
}

/**
	* 函数功能: 接收字节长度为8位的字符串
  * 输入参数: 缓冲区指针，数据长度
  * 返 回 值: 无
  * 说    明: 
  */
void USARTx_Rx_Data(USART_TypeDef * UART, uint8_t *p_data, uint32_t size)
{
	while(size)
	{
		while(!LL_USART_IsActiveFlag_RXNE(UART)){}  //RXNE为1时，上一数据已接收并可读取			
		*p_data = LL_USART_ReceiveData8(UART);
		size--;
		p_data++;
	}
}


PUTCHAR_PROTOTYPE
{
	USARTx_Tx_Data(USART1, (uint8_t *)&ch, 1);
	return ch;
}

GETCHAR_PROTOTYPE
{
	uint8_t ch = 0;
	USARTx_Rx_Data(USART1, &ch, 1);
	return ch;
}

