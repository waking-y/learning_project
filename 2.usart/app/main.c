#include "stm32f4xx.h"
#include <stdio.h>
#include <string.h>

static void board_uart_init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
}

void USART_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	USART_StructInit(&USART_InitStructure);
	USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
		
	USART_Init(USART1, &USART_InitStructure);
	USART_Cmd(USART1, ENABLE);
}

//static void usart_write(const char str[])
//{
//	uint8_t len = strlen(str);
//	for(int i = 0; i < len; i ++)
//	{
//		USART_ClearFlag(USART1, USART_FLAG_TC);
//		USART_SendData(USART1, str[i]);
//	  while(USART_GetFlagStatus(USART1,  USART_FLAG_TC) == RESET); 
//	}
//}


int main(void)
{
	board_uart_init();
	USART_init();
//	
//	usart_write("nihao");
	printf("hello world\r\n");
	while(1)
	{
		
	}
	
}

int fputc(int ch, FILE *stream)
{
	(void)stream;
	USART_ClearFlag(USART1, USART_FLAG_TC);
	USART_SendData(USART1, (uint16_t)ch);
	while(USART_GetFlagStatus(USART1,  USART_FLAG_TC) == RESET); 
	
	return ch;
}
