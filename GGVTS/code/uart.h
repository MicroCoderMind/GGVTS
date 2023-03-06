/***************************************************************************
*  File Name: uart.h                                                       *
*--------------------------------------------------------------------------*
*  Description: This file contains all the declarations for functions and  *
*               global parameters used for UART functionality.             *
*  Author: Arora Motor Works                                               *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
#ifndef __UART__
#define __UART__

/***************************************************************************
*  Funtion Name: isr_uart                                                  *
*--------------------------------------------------------------------------*
*  Description: This function contains ISR for interrupts related to UART. *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern __irq void isr_uart(void);
  
/***************************************************************************
*  Funtion Name: init_uart                                                 *
*--------------------------------------------------------------------------*
*  Description: This function contains initialization of all the global    *
*               registers required for UART functionality.                 *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern void init_uart(void);

/***************************************************************************
*  Funtion Name: interrupt_init                                            *
*--------------------------------------------------------------------------*
*  Description: This function contains initialization of all the global    *
*               registers required for all the interrupts functionality.   *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern void interrupt_init(void);
	
#endif
/********************************End of File*******************************/
