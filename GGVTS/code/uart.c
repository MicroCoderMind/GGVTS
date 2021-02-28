#include "common.h"
__irq void uart_isr(void)
{
	UINT32 iir_value;
	char temp;
  iir_value = U0IIR;
	if( iir_value & 0x00000004 )
	{
		REC = ON;
		temp = U0RBR;
		if((temp == '+' || temp == 'C' || temp == 'M' || temp == 'T' || temp == 'I' || temp == ':' || temp == ' ' || temp == '"' || temp == 'S' || temp == 'M' || temp == ',')  && ((comp-new_mes)==1))
		{
			new_mes++;
			if(new_mes == 11)
			{
				new_message++;
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
		while( (U0LSR & 0x40) == 0 );
	}

	REC = OFF;
	VICVectAddr = 0x00;
}

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

void interrupt_init(void)
{
	if (!ERROR)
	{
		VICVectAddr0 = (unsigned) uart_isr;	/* UART0 ISR Address */
		VICVectAddr2 = (unsigned) timer_isr;	/* UART0 ISR Address */
#ifdef DEBUG_START
		VICVectAddr1 = (unsigned) uart_isr_debug;	/* UART0 ISR Address need to remove this line after finishing*/
#endif
		VICVectCntl0 = 0x00000026;	/* Enable UART0 IRQ slot */
		VICVectCntl1 = 0x00000027;	/* Enable UART1 IRQ slot need to remove this line after finishing*/
		VICVectCntl2 = 0x00000025;	/* Enable TImer 1 Interrupt*/
		VICIntEnable = 0x000000E0;	/* Enable UART0, UART1 and Timer1 interrupt*/
		VICIntSelect = 0x00000000;	/* UART0 configured as IRQ */
	}
}
