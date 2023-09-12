#@copyright: Ahmed Elsayed Abdelmaksood
ProjectName=learn-in-depth
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=

SRC=$(wildcard *.c)
ASS=$(wildcard *.s)

SRC_OBJ=$(SRC:.c=.o)
ASS_OBJ=$(ASS:.s=.o)

all: learn-in-depth.bin
	@echo "*****Build is Done*****"
	

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) -c $< -o $@

$(ProjectName).elf: $(SRC_OBJ) $(ASS_OBJ)
	$(CC)ld -T Linker_Script.ld $(LIBS) $(SRC_OBJ) $(ASS_OBJ) -o $@ -Map=Map_file.map

$(ProjectName).bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@


	
clean_all:
	rm *.o *.elf *.bin
	@echo "*****Every_Thing_cleared*****"
clean:
	rm *.elf *.bin
	
	
	
	
    
    
    
   
	