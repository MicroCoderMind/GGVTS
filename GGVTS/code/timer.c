/***************************************************************************
*  File Name: timer.c                                                      *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions used for   *
*               timers.                                                    *
*  Author: Arora Motor Works                                               *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Below are the header files required to build this file                  *
***************************************************************************/
#include "common.h"

/***************************************************************************
*  Funtion Name: timer1_isr                                                *
*  Function prototype: __irq void timer1_isr(void)                         *
*  Function return type: void                                              *
*  Function description: This function contains interrupt routine of timer1*
***************************************************************************/
void timer1_isr(void) __irq
{
    T1IR = 0x01;                        /* Clear timer interrupt */
	if (LOCATION == ON)
	{
        SEND_LOCATION = ON;                 /* Global variable to enable functionality of sending location as per user desired frequency */
	}
    VICVectAddr = 0x00;                 /* Inform processor that ISR ends here */
}

/***************************************************************************
*  Funtion Name: timer0_isr                                                *
*  Function prototype: __irq void timer0_isr(void)                         *
*  Function return type: void                                              *
*  Function description: This function contains interrupt routine of timer0*
***************************************************************************/

void timer0_isr(void) __irq
{
	  T0TCR = 0x02;	                    /* Reset Timer */
	if (TIMER0 == ON)
	{
       DELETE_MESSAGES = ON;
       //Delete messages as soon as related functionality is completed
	}	
	if (TIMER0 == OFF)
	{
		DELETE_MESSAGES = OFF;
		//Do not delete messages as there are messages in buffer.
	}
	T0IR = 0x01;                        /* Clear timer interrupt */
	TIMER0_OVER = OFF;
    VICVectAddr = 0x00;                 /* Inform processor that ISR ends here */
}

/***************************************************************************
*  Funtion Name: set_location_frequency                                    *
*  Function prototype: void set_location_frequency(uint32_t freq)            *                                                   
*  Function return type: void                                              *
*  Function description: This function used to set timer frequency for     *
*  user desired time delay.                                                *
***************************************************************************/
void set_location_frequency(uint32_t freq)
{
	LOCATION = ON;
    T1PR = 11999 * freq * 60; 	/* To make timer run for desired time, freq can have values 1,3,5,7,10 */
#ifdef DEBUG_START
    debug("Timer Start");       /* Debug purpose */
#endif
    T1TCR = 0x01;               /* Start Timer */
    return;                     /* Return statement */
}

/***************************************************************************
*  Funtion Name: delete_message_timer                                      *
*  Function prototype: void delete_message_timer(void)                     *
*  Function return type: void                                              *
*  Function description: This function starts timer 0 to delete message    *
*                         present in buffer.                               *
***************************************************************************/
void delete_message_timer(void)
{
	TIMER0 = ON;
    T0PR = 11999 * 0.125; 	    /* Timer to wait for processor finish its on going functionality, current message will be deleted once this timer over. */
#ifdef DEBUG_START
    debug("Timer Start");       /* Debug purpose */
#endif
    T1TCR = 0x01;               /* Start Timer */
    return;                     /* Return statement */
}

/***************************************************************************
*  Funtion Name: delay                                                     *
*  Function prototype:  void delay(float)                                  *
*  Function return type: void                                              *
*  Function description: This is delay function.                           *
***************************************************************************/
void delay(float seconds)
{
    TIMER0_OVER = ON;
    T0PR = (uint32_t)(11999 * seconds); 	   /* Value to make delay of desired seconds. */
    T0TCR = 0x01;    	                   /* Start Timer */
    IO0SET = 0x00000010;
	while(TIMER0_OVER);                    /* Wait for timer to over */
	IO0CLR = 0x00000010;
	return;
}

/***************************************************************************
*  Funtion Name: timer_0_init                                              *
*  Function prototype: void timer_0_init(void)                             *
*  Function return type: void                                              *
*  Function description: This function will intialize timer0               *
***************************************************************************/
void timer_0_init(void)
{
    if (!ERROR)
    {
        T0TCR = 0x02;	     /* Reset Timer */
        T0CTCR = 0x00;       /* Set Timer 0 into Timer Mode */
        T0MCR = 0x07;	     /* Inform processor to reset timer after 1 sec */
        T0MR0 = 1000;        /* Value to make delay of 1sec */
    }
}

/***************************************************************************
*  Funtion Name: timer_1_init                                              *
*  Function prototype: void timer_1_init(void)                             *
*  Function return type: void                                              *
*  Function description: This function will intialize timer1.              *
***************************************************************************/
void timer_1_init(void)
{
    if (!ERROR)
    {
        T1TCR = 0x02;	     /* Reset Timer */
        T1CTCR = 0x00;       /* Set Timer 1 into Timer Mode */
        T1MCR = 0x07;	     /* Inform processor to reset timer after 1 sec and enable timer 1 interrupt */
        T1MR0 = 1000;        /* Value to make delay of 1sec */
    }
}

/***************************************************************************
*  Funtion Name: pll_init                                                  *
*  Function prototype:  void pll_init(void)                                *
*  Function return type: void                                              *
*  Function description: This function will intialize PLL for desired      *  
*                        clock frequency for timer.                        *
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
