/***************************************************************************
*  File Name: timer.h                                                      *
*--------------------------------------------------------------------------*
*  Description: This file contains all the declarations for functions and  *
*               global parameters used for Timer functionality.            *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
#ifndef __TIMER__
#define __TIMER__

/***************************************************************************
*  Funtion Name: timer0_isr                                                *
*--------------------------------------------------------------------------*
*  Description: This function will be called when timer 0 runs for time    *
*               desired by user for delay purpose and to delete messages   *
*--------------------------------------------------------------------------*
*  Input Parameters: none                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
__irq void timer0_isr(void);

/***************************************************************************
*  Funtion Name: timer1_isr                                                 *
*--------------------------------------------------------------------------*
*  Description: This function will be called when timer 1 runs for time    *
*               desired by user and this will set global parameter which   *
*               will further be used to send location after user desired   *
*               time.                                                      *
*--------------------------------------------------------------------------*
*  Input Parameters: none                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
__irq void timer1_isr(void);
    
/***************************************************************************
*  Funtion Name: delay                                                     *
*--------------------------------------------------------------------------*
*  Description: This function will generate user desired delay             *
*--------------------------------------------------------------------------*
*  Input Parameters: float                                                 *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments: Formula used in this is 1sec multiplied by input float value. *
*            For example: If input is 1, generated delay will be 1 second  *
*            and input is 2 generated delay will be of 2 seconds           * 
*                                                                          *
***************************************************************************/
  extern void delay(float);
  
/***************************************************************************
*  Funtion Name: sel_location_frequency                                    *
*--------------------------------------------------------------------------*
*  Description: This function will start timer 1 for user desired time     *
*--------------------------------------------------------------------------*
*  Input Parameters: unsigned integer                                      *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments: User can set timer for 1,3,5,7,10 minutes and after this much *
*            time location will be sent to user continously.               *
***************************************************************************/
  extern void set_location_frequency(UINT32);
  
/***************************************************************************
*  Funtion Name: timer_init                                                *
*--------------------------------------------------------------------------*
*  Description: This function will initialize all the timer related global *
*               registers.                                                 *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
  extern void timer_0_init(void);
	
	  extern void timer_1_init(void);
	
	extern void delete_message_timer(void);
  
/***************************************************************************
*  Funtion Name: pll_init                                                  *
*--------------------------------------------------------------------------*
*  Description: This function will initialize all the global registers     *
*               related to PLL to use processor at 12 MHz frequency.       *
*--------------------------------------------------------------------------*
*  Input Parameters:None                                                   *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
  extern void pll_init(void);
	
	void module_reset_timer(UINT32 start_stop);
	
	
    
#endif
/********************************End of File*******************************/
