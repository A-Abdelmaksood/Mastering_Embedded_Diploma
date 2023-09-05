#include "UART.h"
#define UART0DR    *((volatile unsigned int*)((unsigned int*)0x101f1000))
#define NULL '\0'


void UART_Send_String(unsigned char* p_tx_string)
{
	while (*p_tx_string!= NULL)
	{
		UART0DR = (unsigned int)(*p_tx_string);
		p_tx_string++;
	}
}