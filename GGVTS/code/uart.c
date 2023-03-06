#include "common.h"

/***************************************************************************
*  Funtion Name: uart_isr                                                  *
*  Function prototype:  void uart_isr(void)                                *
*  Function return type: void                                              *
*  Function description: This function contains the interrupt reoutine of  *  
*                        UART0.                                            *
***************************************************************************/
__irq void uart_isr(void)
{
	UINT32 iir_value;
	char temp;
  iir_value = U0IIR;
	if( iir_value & 0x00000004 )
	{
		REC = ON;
		temp = U0RBR;
		if((temp == '+' || temp == 'C' || temp == 'M' || temp == 'T' || temp == 'I')  && ((comp-new_mes)==1))
		{
			new_mes++;
			if(new_mes == 5)
			{
				new_message++;
				TIMER = OFF;
				Received_Message_Count++;
				new_mes = 0;
			  comp=0;
				buffer_counter -= 13;
			}
		}
		else
		{
			new_mes = 0;
			comp=0;
		}
		response_temp[buffer_counter++] = temp;
		comp++;
	}
	else
	{
		iir_value = U0IIR;
	}

	REC = OFF;
	VICVectAddr = 0x00;
}


/***************************************************************************
*  Funtion Name: uart_init                                                 *
*  Function prototype:  void uart_init(void)                               *
*  Function return type: void                                              *
*  Function description: This function will intialize the UART0            *
***************************************************************************/
void uart_init(void)
{
	if (!ERROR)
	{
		PINSEL0 = PINSEL0 | 0x00050005;	/* Enable UART0 Rx0 and Tx0 pins of UART0 */
		U0LCR = 0x83;	                  /* DLAB = 1, 1 stop bit, 8-bit character length */
		U0DLM = 0x00;	                  /* For baud rate of 9600 with Pclk = 12MHz */
		U0DLL = 0x4E;	                  /* We get these values of U0DLL and U0DLM from formula */
		U0LCR = 0x03;                   /* DLAB = 0 */
		U0TER = 0x80;   	
		U0IER = 0x00000003;	            /* Enable THRE and RBR interrupt */
	}
}

/***************************************************************************
*  Funtion Name: interrupt_init                                            *
*  Function prototype:  void interrupt_init(void)                          *
*  Function return type: void                                              *
*  Function description: This function will intialize interrupt for all    *
*                        the functionalities like Timer, UART etc          *
***************************************************************************/
void interrupt_init(void)
{
	if (!ERROR)
	{
		VICVectAddr0 = (unsigned) uart_isr;	/* UART0 ISR Address */
		VICVectAddr2 = (unsigned) timer1_isr;	/* Timer1 ISR Address */
		VICVectAddr1 = (unsigned) uart_isr_debug;	/* UART0 ISR Address need to remove this line after finishing*/
		VICVectAddr3 = (unsigned) timer0_isr;	/* UART0 ISR Address need to remove this line after finishing*/
		VICVectCntl0 = 0x00000026;	/* Enable UART0 IRQ slot */
		VICVectCntl1 = 0x00000027;	/* Enable UART1 IRQ slot need to remove this line after finishing*/
		VICVectCntl2 = 0x00000025;	/* Enable TImer 1 Interrupt*/
		VICVectCntl3 = 0x00000024;	/* Enable TImer 0 Interrupt*/
		VICIntEnable = 0x000000F0;	/* Enable UART0, UART1, Timer0 and Timer1 interrupt*/
		VICIntSelect = 0x00000000;	/* UART0 configured as IRQ */
	}
}
