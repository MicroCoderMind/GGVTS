#define UART1_ID uart0
#define UART2_ID uart1
#define BAUD_RATE 115200
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY    UART_PARITY_NONE

// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART1_TX_PIN 0
#define UART1_RX_PIN 1

#define UART2_TX_PIN 4
#define UART2_RX_PIN 5

extern void initUart(void);
extern void initUartDebug(void);

extern void uartInterruptHandler(void);
extern void sendDataOverUART(const char * );
extern void sendDataOverDebug(const char * );