/***************************************************************************
*  File Name: debug.c                                                      *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions used for   *
*               debugging purpose.                                         *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Below are the header files required to build this file                  *
***************************************************************************/
#include "common.h"
//#ifdef DEBUG_START

/***************************************************************************
*  Funtion Name: uart_isr_debug                                            *
***************************************************************************/
__irq void uart_isr_debug(void)
{
    UINT32 iir_value;       /* Local variable to clear interrupt */
    iir_value = U1IIR;      /* Cleaaring interrupt */
    VICVectAddr = 0x00;     /* Informing processor that interrupt ends here */
}

/***************************************************************************
*  Funtion Name: uart_init_debug                                           *
***************************************************************************/
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
***************************************************************************/
void debug(const char * str1)
{
    UINT32 k=0;                         /* Local variable used as counter */
	delay(0.2);                         /* Delay of 0.2 seconds */
	for (k=0;k<strlen_mod(str1);k++)    /* For loop */
	{
	    U1THR = str1[k];                /* Writing data in transmit buffer */
	    delay(0.01);                    /* delay of 0.01 seconds */
	}
	REC = OFF;                          /* Flag used for debug purpose */
}
//#endif

/********************************End of File*******************************/
