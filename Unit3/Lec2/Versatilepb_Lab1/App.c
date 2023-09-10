/* Learn-in-depth 
   write code from scratch
   Eng.Ahmed_Elsayed
*/

#include "Uart.h"
unsigned char string[100] = "learn-in-depth : Ahmed";
unsigned char const string2[100] = "learn-in-depth : Ahmed";
unsigned char const string3[100] = "learn-in-depth : Ahmed";
void main(void)
{
	UART_Send_String(string);
}