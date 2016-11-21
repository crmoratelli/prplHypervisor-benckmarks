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
	perf_control_t perf0, perf1;
	uint32_t perfcount0, perfcount1;
	
	proc_init();

	start_timer();

	init_mem();

	init_uart(115200, 200000000);
	
	//printf("\n0x%x ", mfc0(16, 0));

	/* peformance counter 0 - D-Cache Misses */
	perf0.w = 0;
	perf0.ec = 0;
	perf0.event = 11;
	perf0.ie = 0;
	perf0.u = 0;
	perf0.k = 1;
	perf0.exl = 0;
	
	/* peformance counter 1 - I-Cache Misses */
	perf1.w = 0;
	perf1.ec = 0;
	perf1.event = 9;
	perf1.ie = 0;
	perf1.u = 0;
	perf1.k = 1;
	perf1.exl = 0;
	
	mtc0(CP0_PERFCTL0, 1, 0);
	mtc0(CP0_PERFCTL1, 3, 0);
	
	mtc0(CP0_PERFCTL0, 0, perf0.w);
	mtc0(CP0_PERFCTL1, 2, perf1.w);
	
	main_dhry(RUNS);
	
	perfcount0 = mfc0(CP0_PERFCTL0, 1);
	perfcount1 = mfc0(CP0_PERFCTL1, 3);
	
	mtc0(CP0_PERFCTL0, 0, 0);
	mtc0(CP0_PERFCTL1, 2, 0);
	
	printf("\nD-Cache Misses: %d", perfcount0);
	printf("\nI-Cache Misses: %d", perfcount1);

	return 0;
}

