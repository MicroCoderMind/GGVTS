#ifndef __REGISTERS__
#define __REGISTERS__ 1

sfr uart_reg = 0x0098;
sfr buffer = 0x0099;
sfr timer_reg = 0x0089;
sfr timer_data_reg = 0x008D;
sbit timer_on_off = 0x8E;
sbit transmit_interrupt_uart = 0x99;
sbit receive_interrupt_uart = 0x98;

//Temporary Pins
sbit green = P1^0;
sbit red = P1^1;

#endif