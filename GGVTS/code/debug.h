/***************************************************************************
*  File Name: debug.h                                                      *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function declarations used for  *
*               debugging purpose.                                         *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                               *
*                                                                          *
/**************************************************************************/
  
#ifndef __DEBUG__
#define __DEBUG__	
  __irq void uart_isr_debug(void);        /*This function contains ISR for interrupt related to UART1*/
  extern void uart_init_debug(void);      /*This function contains initialization of all the registers used for UART1*/
  extern void debug(const char *);        /*This function contains funct  onality in which data is sent to UART1 */
#endif
/******************************End of File*********************************/
