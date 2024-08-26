
#include "common.h"


void uartInterruptHandler(void) {
    int chars_rxed = 0;
    char temp;
    while (uart_is_readable(UART1_ID)) {
        REC = ON;
        temp = uart_getc(UART1_ID);
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
				buffer_counter = 0;
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
    uart_putc(UART2_ID,response_temp[buffer_counter - 1]);
    dataRecieved = true;
}

void uartDebugInterruptHandler(void) {
    int chars_rxed = 0;
    while (uart_is_readable(UART2_ID)) {
        response_temp_debug[chars_rxed] = uart_getc(UART2_ID);
	    if(response_temp_debug[chars_rxed] == '~')
	    {
	    	DIAGNOSE = ON;             /* Diagnose Mode ON */
	    }
	    else if(response_temp_debug[chars_rxed] == '_')
	    {
	    	DIAGNOSE = NA;             /* Diagnose Mode Not Applicable */
	    }

    }
    if (DIAGNOSE == ON)
	{
		diagnose_data = response_temp_debug[chars_rxed];
		diagnoseDataSent = OFF;
	}
    chars_rxed++;
    dataRecieved = true;
}

void sendDataOverUART(const char * datatosend)
{
    int16_t i;
    for (i=0;i<strlen_mod(datatosend);)
    {
        if (uart_is_writable(UART1_ID))
        {
            uart_putc(UART1_ID,datatosend[i++]);
            sleep_ms(50);
        }
    }
}

void sendDataOverDebug(const char * datatosend)
{
    int16_t i;
    for (i=0;i<strlen_mod(datatosend);)
    {
        if (uart_is_writable(UART2_ID))
        {
            uart_putc(UART2_ID,datatosend[i++]);
            sleep_ms(50);
        }
    }
    uart_putc(UART2_ID,'\r');
    uart_putc(UART2_ID,'\n');
}

void initUart(void)
{
    uart_init(UART1_ID, 2400);
    gpio_set_function(UART1_TX_PIN, UART_FUNCSEL_NUM(UART1_ID, UART1_TX_PIN));
    gpio_set_function(UART1_RX_PIN, UART_FUNCSEL_NUM(UART1_ID, UART1_RX_PIN));
    uart_set_baudrate(UART1_ID, BAUD_RATE);
    uart_set_hw_flow(UART1_ID, false, false);
    uart_set_format(UART1_ID, DATA_BITS, STOP_BITS, PARITY);
    uart_set_fifo_enabled(UART1_ID, false);
    irq_set_exclusive_handler(UART0_IRQ, uartInterruptHandler);
    irq_set_enabled(UART0_IRQ, true);
    uart_set_irq_enables(UART1_ID, true, false);
}

void initUartDebug(void)
{
    uart_init(uart1, 2400);
    gpio_set_function(UART2_TX_PIN, UART_FUNCSEL_NUM(UART2_ID, UART2_TX_PIN));
    gpio_set_function(UART2_RX_PIN, UART_FUNCSEL_NUM(UART2_ID, UART2_RX_PIN));
    uart_set_baudrate(UART2_ID, BAUD_RATE);
    uart_set_hw_flow(UART2_ID, false, false);
    uart_set_format(UART2_ID, DATA_BITS, STOP_BITS, PARITY);
    uart_set_fifo_enabled(UART2_ID, false);
    irq_set_exclusive_handler(UART1_IRQ, uartDebugInterruptHandler);
    irq_set_enabled(UART1_IRQ, true);
    uart_set_irq_enables(UART2_ID, true, false);
}