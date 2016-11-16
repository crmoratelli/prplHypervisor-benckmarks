#include <pic32mz.h>
#include <libc.h>

#define MILISECOND (100000000 / 1000)
#define INTERVAL (MILISECOND * 1)

volatile uint32_t milisecond_passed = 0;


void _irq_handler(){
	uint32_t count;
	
	if(!(PORTB & (1<<12))){
		SoftReset();
	}

	milisecond_passed++;
	
	count = mfc0(CP0_COUNT, 0);
	count += INTERVAL;
	mtc0(CP0_COMPARE, 0, count);
	
	IFSCLR(0) = 1;  
}

long time(long *tm){
	
	if (tm){
		*tm=milisecond_passed/1000;
	}
	
	return milisecond_passed/1000;
}


int start_app() {
	proc_init();

	start_timer();

	init_mem();

	init_uart(115200, 200000000);

	main(RUNS);

	return 0;
}

