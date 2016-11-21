#include <pic32mz.h>
#include <libc.h>

#define MILISECOND (100000000 / 1000)
#define INTERVAL (MILISECOND * 1)
#define CPU_TICK_TO_MS(ticks) ((ticks)/100000)

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
	
}

int start_app() {
	
	proc_init();

	start_timer();

	init_mem();

	init_uart(115200, 200000000);
	
	coremain();
	
	return 0;
}

