  #ifndef __GPS__
	#define __GPS__
	extern const INT8 * GPS_INIT[1];
	extern const INT8 * GPS_LOCATION[1];
	extern char joined_string[100];
	extern void get_gps_location(void);
	extern char extracted_location[50];
	extern void gps_init(void);
	extern void extract_location(void);
	extern void send_location(void);

	#endif
