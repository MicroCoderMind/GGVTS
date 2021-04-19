/***************************************************************************
*  File Name: timer.c                                                      *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions used for   *
*               timers.                                                    *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Below are the header files required to build this file                  *
***************************************************************************/
#include "common.h"
#undef DEBUG_START

/***************************************************************************
*  Funtion Name: timer_isr                                                 *
***************************************************************************/
__irq void timer_isr(void)
{
    T1IR = 0x01;                        /* Clear timer interrupt */
#ifdef DEBUG_START                      /* Debug Purpose */
    debug("Timer Interrupt Start\n");   /* Debug purpose */
#endif                                  /* Debug purpose */
    SEND_LOCATION = ON;                 /* Global variable to enable SEND_FREQ functionality */
#ifdef DEBUG_START                      /* Debug purpose */
    debug("Timer Interrupt End\n");     /* Debug purpose */
#endif                                  /* Debug purpose */
    VICVectAddr = 0x00;                 /* This line tells processor that interrupt ends here */
}

/***************************************************************************
*  Funtion Name: set_location_frequency                                    *
***************************************************************************/
void set_location_frequency(UINT32 freq)
{
    T1PR = 11999 * freq * 60; 	/* To make timer run for desired time, freq can have values 1,3,5,7,10 */
#ifdef DEBUG_START              /* Debug purpose */
    debug("Timer Start");       /* Debug purpose */
#endif                          /* Debug purpose */
    T1TCR = 0x01;               /* Start Timer */
    return;                     /* Return statement */
}

/***************************************************************************
*  Funtion Name: delay                                                     *
***************************************************************************/
void delay(float seconds)
{
    T0PR = (UINT32)(11999 * seconds); 	   /* Value to make delay of desired time. */
    T0TCR = 0x01;                          /* Start Timer */
    while(T0TCR);                          /* Wait until timer reset (1 sec delay generated) */
    T0TCR = 0x02;                          /* Stop Timer */
}

/***************************************************************************
*  Funtion Name: timer_init                                                *
***************************************************************************/
void timer_init(void)
{
    if (!ERROR)
    {
        T0TCR = 0x02;	     /* Reset Timer */
        T0CTCR = 0x00;       /* Set Timer 0 into Timer Mode */
        T0MCR = 0x06;	     /* Tell processor to reset timer after 1 sec */
        T0MR0 = 1000;        /* Value to make delay of 1sec */
        T1TCR = 0x02;	     /* Reset Timer */
        T1CTCR = 0x00;       /* Set Timer 1 into Timer Mode */
        T1MCR = 0x07;	     /* Tell processor to reset timer after 1 sec and enable timer 1 interrupt */
        T1MR0 = 1000;        /* Value to make delay of 1sec */
    }
}

/***************************************************************************
*  Funtion Name: pll_init                                                  *
***************************************************************************/
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
