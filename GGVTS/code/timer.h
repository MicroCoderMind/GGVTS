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

__irq void timer_isr(void);
    
/***************************************************************************
*  Funtion Name: delay                                                     *
*--------------------------------------------------------------------------*
*  Description: This function will generate user desired delay             *
*--------------------------------------------------------------------------*
*  Input Parameters: float                                                 *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments: Formula used in this is 1sec divided by enetered float value. *
*            For example: If input is 1, generated delay will be 1 second  *
*            and input is 2 generated delay will be of                     * 
*			 500ms.                                                        *
*                                                                          *
***************************************************************************/
  extern void delay(float);
  
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
  extern void timer_init(void);
  
/***************************************************************************
*  Funtion Name: response_back                                          *
*--------------------------------------------------------------------------*
*  Description: This function will initialize all the global registers
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
