#include "UART.h"
unsigned char Info[100] = "Learn_in_depht:Ahmed";
void main(void)
{
	
	UART_Send_String(Info);
}