#include "common.h"
void init(void)
{
	IE = 0x90;
	green = 0;
	red = 0;
  P1=0;
	receive_response();
	uart_init();
	gsm_ready();
}