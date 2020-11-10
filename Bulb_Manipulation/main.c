#include "common.h"
UINT8* commands[]={"AT+CMGF=1\r","AT+CPMS=\"SM\"\r","AT+CMGD=1,4\r","AT+CMGR=1\r","AT+CMGD=1,4\r"};
UINT8* fixed_response[]={"\r\n+CMTI: \"SM\",1\r\n"};
//UINT8 characters[]={12,40};
UINT8 ENTER = 0x0D;
UINT8 DATA_SEND = 0x1A;
UINT8 PARK_MODE = 0;
UINT8 response[5];
UINT8 response_temp[80];
UINT8 OK_FLAG=FALSE;
unsigned char x=0;
UINT8 i=0;
UINT8 strcmp2(void);
void extract(void);
void read_message(void);
void functionality(void);
void send(UINT8 string_length,UINT8 number);
void uart_transmit(void);
void uart_init(void);
void compare(void);
void delay(void);
void gsm_ready(void);
void wait_to_receive(void);
void receive_response(void);
void main()
{
	IE = 0x90;
	green = 0;
	red = 1;
  P1=0xAA;
	P2=0;
	uart_init();
	gsm_ready();
	functionality();
	while(1);
}

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

void delay(void)
{
	UINT8 i;
	for (i=0;i<254;i++);
				for (i=0;i<254;i++);
		for (i=0;i<254;i++);
				for (i=0;i<254;i++);
		for (i=0;i<254;i++);
				for (i=0;i<254;i++);
		for (i=0;i<254;i++);
				for (i=0;i<254;i++);
		for (i=0;i<254;i++);
				for (i=0;i<254;i++);
		for (i=0;i<254;i++);
				for (i=0;i<254;i++);
		for (i=0;i<254;i++);
				for (i=0;i<254;i++);
		for (i=0;i<254;i++);
				for (i=0;i<254;i++);
}
void gsm_ready(void)
{
	UINT8 flag=0;
	for (i=0;i<3;i++)
	{
      send(strlen(commands[i]),i);
			delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
			x=0;
	memset(response_temp,0,80);
	}
	wait_to_receive();
/*	compare();
		while(!OK_FLAG);
		x=0;
		*/
}

void functionality(void)
{
}
void wait_to_receive(void)
{ 
	x=0;
			memset(receive_response,0,80);
		while(TRUE)
	{
x=0;
	delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
			delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
			delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
	 delay();
			delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
		if (strcmp2()!=0)
		{
			red=0;
			//P2=response_temp[1];
			P2 = strcmp2();
		}
		else
		{
			red = 1;
			P2 = 0xff;
			read_message();
		}
		}
}
void read_message(void)
{
		x=0;
			memset(receive_response,0,80);
		delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
			delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
			delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
	 delay();
			delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
	send(strlen(commands[i]),i);
		delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
			delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
			delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
	 delay();
			delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
	extract();
}
UINT8 strcmp2(void)
{
	UINT8 len=strlen(fixed_response[0]),j;
	for (j=0;j<len;j++)
	{
		if (fixed_response[0][j] == response_temp[j])
		{
			continue;
		}
		else
		{
			return fixed_response[0][j];
			//return j+1;
		}
	}
	return 0;
}
void extract(void)
{
	UINT8 f,g=0;
	UINT8 count=0;
	for (f=0;f<strlen(response_temp);f++)
	{
		if (response_temp[f]=='\r')
		{
			count++;
		}
		if(count == 3)
		{
			response[g]=response_temp[f+2];
			g++;
		}
	}
	x=0;
	memset(response_temp,0,80);
	if(response[0]=='H' || response[0] == 'h')
	{
				send(strlen(commands[2]),2);
		  delay();
				  delay();
				  delay();
				  delay();
				  delay();
				  delay();
				  delay();
		green = 1;
	}
	else if(response[0]=='L' || response[0]=='l')
	{
				send(strlen(commands[2]),2);
		  delay();
				  delay();
				  delay();
				  delay();
				  delay();
				  delay();
				  delay();
				  delay();
				  delay();
		green = 0;
	}
}