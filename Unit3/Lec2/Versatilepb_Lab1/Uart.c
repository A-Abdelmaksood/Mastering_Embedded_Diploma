/* Learn-in-depth 
   write code from scratch
   Eng.Ahmed_Elsayed
*/
#include "Uart.h"
/* UART REGISTER */
#define UARTODR   *((volatile unsigned int*)0x101f1000)
/* IMPLEMENTATION */
void UART_Send_String(unsigned char *p_tx_string)
{
	while(*p_tx_string!='\0')
	{
		UARTODR = (unsigned int)(*p_tx_string);
		p_tx_string++; /* NEXT CHAR */
	}
}