  #ifndef __UART__
	#define __UART__
	
	extern __irq void uart_isr(void);
  extern void uart_init(void);
	extern void interrupt_init(void);
		
	#endif
