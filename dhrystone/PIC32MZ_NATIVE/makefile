
#Uncoment if you desires to generate dhyrstone using registers.
USE_REGISTERS=yes

#Number of executions. 
RUNS = 10000000

#platform options
BAUDRATE=115200
F_CLK=200000000
SERIAL_DEV=/dev/ttyACM0
TIME_FUNC= -DTIME
CPU_SPEED = 200000000


#cross-compiler 
CROSS_COMPILER=mips-mti-elf-

#gcc options. Must be tunned for dhyrstone
GCCOPTIM= -O2
LFLAGS= -static
AS_FLAGS = -EL -mips32r2 -msoft-float
GCCFLAGS= -EL $(GCCOPTIM) $(TIME_FUNC) -DRUNS=$(RUNS) -DCPU_SPEED=$(CPU_SPEED) -DLITTLE_ENDIAN -DPIC32MZ -c -Wno-unused-result -Wno-pointer-to-int-cast -mips32r2 -mtune=m14k -mno-check-zero-division -msoft-float -fshort-double -ffreestanding -nostdlib -fomit-frame-pointer -G 0 
INCLUDE = -Ibare-app/include -I../

AS_MIPS = $(CROSS_COMPILER)as 
LD_MIPS = $(CROSS_COMPILER)ld 
DUMP_MIPS = $(CROSS_COMPILER)objdump
READ_MIPS = $(CROSS_COMPILER)readelf
OBJ_MIPS = $(CROSS_COMPILER)objcopy
SIZE_MIPS = $(CROSS_COMPILER)size
GCC_MIPS = $(CROSS_COMPILER)gcc

ifeq ($(USE_REGISTERS),yes)
    GCCFLAGS += -DREG=register
    REG_NAME=_reg
endif


BIN_NAME = dry2$(REG_NAME)

all:
	$(AS_MIPS) $(AS_FLAGS) -o crt0.o bare-app/lib/crt0.s
	$(GCC_MIPS) $(GCCFLAGS) $(INCLUDE) -o libc.o bare-app/lib/libc.c
	$(GCC_MIPS) $(GCCFLAGS) $(INCLUDE) -o malloc.o bare-app/lib/malloc.c
	$(GCC_MIPS)  $(GCCFLAGS) $(INCLUDE) -o native_app.o bare-app/native_app.c
	$(GCC_MIPS)  $(GCCFLAGS) $(INCLUDE) -fno-inline -o dhry_1.o ../dhry_1.c
	$(GCC_MIPS)  $(GCCFLAGS) $(INCLUDE) -fno-inline -o dhry_2.o ../dhry_2.c
	$(LD_MIPS) -Tbare-app/lib/pic32mz.ld -Map $(BIN_NAME).map -N -o $(BIN_NAME).elf *.o
	$(DUMP_MIPS) --disassemble --reloc $(BIN_NAME).elf > $(BIN_NAME).lst
	$(DUMP_MIPS) -h $(BIN_NAME).elf > $(BIN_NAME).sec
	$(DUMP_MIPS) -s $(BIN_NAME).elf > $(BIN_NAME).cnt
	$(OBJ_MIPS) -O binary $(BIN_NAME).elf $(BIN_NAME).bin
	$(OBJ_MIPS) -O ihex --change-addresses=0x80000000 $(BIN_NAME).elf $(BIN_NAME).hex
	$(SIZE_MIPS) $(BIN_NAME).elf
	
serial:
	stty ${BAUDRATE} raw cs8 -parenb -crtscts clocal cread ignpar ignbrk -ixon -ixoff -ixany -brkint -icrnl -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke -F ${SERIAL_DEV}

load: serial
	./bare-app/pic32prog -d ${SERIAL_DEV} $(BIN_NAME).hex 

clean:
	-rm -rf *~ *.o *.axf *.map *.lst *.sec *.cnt *.txt *.bin *.srec *.hex *.elf
	-rm -rf app/*~
	-rm -rf include/*~
	-rm -rf lib/*~

