/***************************************************************************
*  File Name: debug.c                                                      *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions used for   *
*               debugging purpose.                                         *
*  Author: Arora Motor Works                                               *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Required Header Files         						                   *
***************************************************************************/
#include "common.h"
/***************************************************************************
*  Funtion Name: isr_uart_diagnose                                         *
*  Funtion Prototype: void isr_uart_diagnose(void)                         *
*  Funtion return type: void                                               *  
*  Funtion description: This isr start/stop debugging functionality when   *
*  there is need to diagnose the system after some kind of serious issues  *
*  arised.                                                                 *
***************************************************************************/
__irq void isr_uart_diagnose(void)
{
    uint32_t lcIirValue;       /* Local variable to clear interrupt */
	char temp = 0;          /* Local variable intialize */
    lcIirValue = U1IIR;      /* Cleaaring interrupt */
	if( lcIirValue & 0x00000004 )
	{
	    temp = U1RBR;
	    if(temp == '~')
	    {
	    	DIAGNOSE = ON;             /* Diagnose Mode ON */
	    }
	    else if(temp == '_')
	    {
	    	DIAGNOSE = NA;             /* Diagnose Mode Not Applicable */
	    }
	}
	else
	{
		lcIirValue = U1IIR;
	}
	if (DIAGNOSE == ON)
	{
		diagnose_data = temp;
		diagnoseDataSent = OFF;
	}
    VICVectAddr = 0x00;     /* Informing processor that interrupt ends here */
}

/***************************************************************************
*  Funtion Name: debug                                                     *
*  Function prototype: void debug(const char * dbgdata)                    *
*  Function return type: void                                              *
*  Function description: This function will transmitt debugged information *
*  through uart1 for debugging purpose in diagnose mode.                   *
***************************************************************************/
void debug(const char * dbgdata)
{
    uint32_t lcCounter=0;                                        /* Local variable used as Counter */
	delay(0.2);                                              /* Delay of 0.2 seconds */
	for (lcCounter=0;lcCounter<strlen_mod(dbgdata);lcCounter++)    /* Loop */
	{
	    U1THR = dbgdata[lcCounter];                            /* Writing data in transmit buffer */
	    delay(0.01);                                         /* delay of 0.01 seconds */
	}
	REC = OFF;                                               /* Flag used for debug purpose */
}

/***************************************************************************
*  Funtion Name: init_uart_diagnose                                        *
*  Function prototype: void init_uart_diagnose(void)                       *
*  Function return type: void                                              *
*  Function description: This function intialize uarts for debugging.      *
***************************************************************************/
void init_uart_diagnose(void)
{
    U1LCR = 0x83;	                    /* DLAB = 1, 1 stop bit, 8-bit character length */
	U1DLM = 0x00;	                    /* For baud rate of 9600 with Pclk = 12MHz */
	U1DLL = 0x4E;	                    /* We get these values of U0DLL and U0DLM from formula */
	U1LCR = 0x03;                       /* DLAB = 0 */
	U1TER = 0x80;                       /* To enable transmission */   
	U1IER = 0x00000003;                 /* Enable THRE and RBR interrupt */
	
	return;
}

/********************************End of File*******************************/
