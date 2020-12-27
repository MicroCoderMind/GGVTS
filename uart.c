#include "common.h"

void send(UINT8 string_length,UINT8 number)
{
	UINT8 i;
	for (i=0;i<string_length;i++)
	{
    buffer = commands[number][i];
	  uart_transmit();
	}
}
void uart_transmit(void)
{
	while(!transmit_interrupt_uart);
	transmit_interrupt_uart = 0;
}

void uart_init(void)
{
	uart_reg = 0x50;
	timer_reg = 0x21;
	timer_data_reg = -3;
	timer_on_off = 1;
}
void receive_response(void)  interrupt 4
{ 
/* ISR routine to save responses/new message */
	if(RI){
		EA = 0;
		response_temp[x] = buffer;	/* copy SBUF(received value) to buffer */
		x++;
		RI = 0;
		EA = 1;
	}
}