  #ifndef __GSM__
	#define __GSM__
	
	extern void gsm_init(void);
	extern void gsm_transmit(const INT8 *);
		extern void extract_message(void);
		extern void delete_message(void);
	extern void read_message(void);
	#endif
