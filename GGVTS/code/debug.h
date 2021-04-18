/***************************************************************************
*  File Name: debug.h                                                      *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function declarations used for  *
*               debugging purpose.                                         *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/
  
#ifndef __DEBUG__
#define __DEBUG__
/***************************************************************************
*  Funtion Name: uart_isr_debug                                            *
*--------------------------------------------------------------------------*
*  Description: This function contains ISR for the interrupt happened for  *
*               UART1. UART1 is only used to tarnsfer data to terminal     *
*               hence this function only contains clearing of IIR flag.    *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/
  __irq void uart_isr_debug(void);

/***************************************************************************
*  Funtion Name: uart_init_debug                                           *
*--------------------------------------------------------------------------*
*  Description: This function contains initialization of all the registers *
*               required for UART1 functionality.                          *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/
  extern void uart_init_debug(void);

/***************************************************************************
*  Funtion Name: debug                                                     *
*--------------------------------------------------------------------------*
*  Description: In this function data is sent to Transmit hold             *
*               register(buffer)                                           *
*--------------------------------------------------------------------------*
*  Input Parameters: String of data which needs to be transmitted to       *
*                    terminal through UART1                                *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/
  extern void debug(const char *);

#endif
/******************************End of File*********************************/
