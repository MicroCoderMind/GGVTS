#ifndef __UART__
#define UART 1

extern void uart_transmit(void);
extern void uart_receive(void);
extern void send(UINT8,UINT8);
extern void uart_init(void);
extern void receive_response(void);

#endif