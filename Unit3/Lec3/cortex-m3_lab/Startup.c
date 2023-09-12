/* 
   Learn-in-depth 
   write code from scratch
   Eng.Ahmed_Elsayed
*/

#include <stdint.h>
#define STACK_START_SP 0x20001000
/* TO ALLOW THE USER EDIT HERE */
extern int main(void);

void Reset_Handler(void);


void Default_Handler()
{
	Reset_Handler;
}

void NMI_Handler(void)         __attribute__((weak, alias("Default_Handler")));;
void H_fault_Handler(void)     __attribute__((weak, alias("Default_Handler")));;
void MM_Fault_Handler(void)    __attribute__((weak, alias("Default_Handler")));;
void Bus_Fault(void)           __attribute__((weak, alias("Default_Handler")));;
void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));;

uint32_t vectors[] __attribute__((section(".vectors"))) = {
	STACK_START_SP,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault,
	(uint32_t) &Usage_Fault_Handler,
	
};

extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;
extern unsigned int _E_text;



void Reset_Handler(void)
{
	/* COPY DATA FROM ROM TO RAM */
	unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;
	for(int i=0; i<DATA_SIZE; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	/* INIT THE .bss WITH ZERO */
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss;
	for(int i=0; i<DATA_SIZE; i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;
	}
	
	/* JUMP TO MAIN */
	main();
}