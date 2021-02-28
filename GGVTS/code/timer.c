#include "common.h"
__irq void timer_isr(void)
{
	#ifdef DEBUG_START
  debug("Timer Interrupt");
#endif
		T1TCR = 0x02;        //Stop Timer
	  reset_module();
		VICVectAddr = 0x00;
}

void module_reset_timer(UINT32 start_stop)
{
		
	if (start_stop == ON)
	{
		T1PR = 11999/(0.015625); 			 //Value to make delay of 2 minute
			#ifdef DEBUG_START
  debug("Timer Start");
#endif
	  T1TCR = 0x01;        //Start Timer
	}
	else if (start_stop == OFF)
	{

		T1TCR = 0x02;				 //Reset Timer
			#ifdef DEBUG_START
  debug("Timer Stop");
#endif
	}
	else
	{
		//Do Nothing
	}
}

void delay(float divisor)
{
		T0PR = 11999/divisor; 			 //Value to make delay of 1ms
	  T0TCR = 0x01;        //Start Timer
		while(T0TCR);        //Wait until timer reset (1 sec delay generated)
		T0TCR = 0x00;        //Stop Timer
}
void timer_init(void)
{
	if (!ERROR)
	{
		T0TCR = 0x02;				 //Reset Timer
		T0CTCR = 0x00;       //Set Timer 0 into Timer Mode 
	  T0MCR = 0x06;				 //Tell processor to reset timer after 1 sec
		T0MR0 = 1000;        //Value to make delay of 1sec 
		
		T1TCR = 0x02;				 //Reset Timer
		T1CTCR = 0x00;       //Set Timer 0 into Timer Mode 
	  T1MCR = 0x07;				 //Tell processor to reset timer after 1 sec
		T1MR0 = 1000;        //Value to make delay of 1sec 

	}
}

void pll_init(void)
{
	if (!ERROR)
	{
	  PLL0CON = 0x01;
	  PLL0CFG = 0x60;
	  PLL0FEED = 0xAA;
	  PLL0FEED = 0x55;
	  while(!(PLL0STAT & 0x00000400));
	  PLL0CON = 0x03;
	  PLL0FEED = 0xAA;
	  PLL0FEED = 0x55;
	  VPBDIV = 0x01;
	}
}
