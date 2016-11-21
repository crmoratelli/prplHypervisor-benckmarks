#include <pic32mz.h>
#include <libc.h>

#define MILISECOND (100000000 / 1000)
#define INTERVAL (MILISECOND * 1)
#define CPU_TICK_TO_MS(ticks) ((ticks)/100000)

//volatile uint32_t milisecond_passed = 0;
volatile uint64_t tick_passed = 0;


void _irq_handler(){
	uint32_t count;
	static uint32_t tick_old = 0;
	uint32_t diff_time;
	

	/* For allow reset the board pressing SW1. You may want to comment this
	   for a fair benchmark. */
	if(!(PORTB & (1<<12))){
		SoftReset();
	}
	
	/* Set the compare to the next interval. */
	count = mfc0(CP0_COUNT, 0);
	count += INTERVAL;
	mtc0(CP0_COMPARE, 0, count);
	
	/* ACK timer interrupt */
	IFSCLR(0) = 1;  
	
	/* Determines the time passed. */
	if (tick_old == 0){
		tick_old = count;
		return;
	}
	
	if (count >= tick_old){
		diff_time = count - tick_old;
	}else{
		diff_time = 0xffffffff - (tick_old - count);
	}
	
	tick_old = count;
	
	tick_passed += diff_time;
	
}

long time(long *tm){
	uint32_t seconds = CPU_TICK_TO_MS(tick_passed)/1000;
	if (tm){
		*tm=seconds;
	}
	
	return seconds;
}


int start_app() {
	uint32_t old_time;
	
	proc_init();

	start_timer();

	init_mem();

	init_uart(115200, 200000000);
	
	//printf("%d %d %d\n", sizeof(unsigned long), sizeof(unsigned long int), sizeof(unsigned long long int));

	old_time = tick_passed;
	main_dhry(RUNS);
	printf("\nPassed time: %d", (uint32_t)CPU_TICK_TO_MS(tick_passed - old_time)); 

	return 0;
}

