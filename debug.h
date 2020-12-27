  #ifndef __DEBUG__
	#define __DEBUG__
	
  __irq void uart_isr_debug(void);
  extern void uart_init_debug(void);
	extern void debug(const char *);
	#endif
