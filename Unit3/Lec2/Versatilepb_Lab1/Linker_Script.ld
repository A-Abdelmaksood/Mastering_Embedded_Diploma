/* Learn-in-depth 
   write code from scratch
   Eng.Ahmed_Elsayed
*/

ENTRY(reset)
MEMORY
{
	MEM(rwx) : ORIGIN = 0X00000000, LENGTH = 64M
}
SECTIONS
{
	.startup :
	{
	    . = 0x10000;
		startup.o(.text)
	}> MEM
	.text :
	{
		*(.text) *(.rodata)
	}> MEM
	.data :
	{
		*(.data) 
	}> MEM
	.bss :
	{
		*(.bss) *(.COMMON)
	}> MEM
	. = . + 0x1000; 
	Stack_Top = .;
}