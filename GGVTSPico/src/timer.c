#include "common.h"

bool timer0_isr(__unused struct repeating_timer *t)
{
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
	cancel_repeating_timer(&timer0);        //Stop Timer
	return true;
}

bool timer1_isr(__unused struct repeating_timer *t)
{
	if (LOCATION == ON)
	{
        SEND_LOCATION = ON;                 /* Global variable to enable functionality of sending location as per user desired frequency */
	}
	cancel_repeating_timer(&timer1);        //Stop Timer 
	return true;
}

void delete_message_timer(void)
{
    TIMER0 = ON;
#ifdef DEBUG_START
    sendDataOverDebug("Timer Start");       /* Debug purpose */
#endif
	if (DELETE_MESSAGES == OFF)
	{
    	add_repeating_timer_ms(200, timer0_isr, NULL, &timer0); 	    /* Timer to wait for processor finish its on going functionality, current message will be deleted once this timer over. */
	}
    return;                     /* Return statement */
}

void set_location_frequency(void)
{
	LOCATION = ON;
	cancel_repeating_timer(&timer1);        //Stop Timer 
#ifdef DEBUG_START
    sendDataOverDebug("Timer Start");       /* Debug purpose */
#endif
    add_repeating_timer_ms(Message_Frequency * 1000 * 60, timer1_isr, NULL, &timer1);
    return;                     /* Return statement */
}