/***************************************************************************
*  File Name: debug.c                                                      *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions used for   *
*               debugging purpose.                                         *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                               *
*                                                                          *
/**************************************************************************/

/**************************************************************************/
*  Below are the header files required to build this file                  *
/**************************************************************************/
#include "common.h"
#define DEBUG_START /*Used for conditional compilation of code related to debug*/
#ifdef DEBUG_START

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
*  Comments:	                                                               *
*                                                                          *
/**************************************************************************/
__irq void uart_isr_debug(void)
{
	UINT32 iir_value;
  iir_value = U1IIR;
	iir_value = iir_value;
	VICVectAddr = 0x00;
}

/***************************************************************************
*  Funtion Name: uart_init_debug                                           *
*--------------------------------------------------------------------------*
*  Description: This function contains initialization of all the registers *
*               required for UART1 functionality.                          *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:	                                                               *
*                                                                          *
/**************************************************************************/
void uart_init_debug(void)
{
		U1LCR = 0x83;	   /* DLAB = 1, 1 stop bit, 8-bit character length */
		U1DLM = 0x00;	   /* For baud rate of 9600 with Pclk = 12MHz */
		U1DLL = 0x4E;	   /* We get these values of U0DLL and U0DLM from formula */
		U1LCR = 0x03;      /* DLAB = 0 */
		U1TER = 0x80;      /* To enable transmission */   
		U1IER = 0x00000003;/* Enable THRE and RBR interrupt */
}

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
*  Comments:	                                                               *
*                                                                          *
/**************************************************************************/
void debug(const char * str1)
{
	  UINT32 k=0;
	  delay(0.5);
	   for (k=0;k<strlen_mod(str1);k++)
	   {
	       IO0SET = 0x00000008;
	       U1THR = str1[k];
	  		delay(9);
	   }
	  REC = OFF;
	  buffer_counter = 0;
	  IO0CLR = 0x00000008;
}
#endif
/*********************************End of File******************************/
