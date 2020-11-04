  #ifndef __GLOBAL__
	#define __GLOBAL__ 1
	
	#define FALSE 0
  #define TRUE 1
  #define LCD P2
  extern UINT8* commands[5];
  extern UINT8 ENTER;
  extern UINT8 DATA_SEND;
  extern UINT8 PARK_MODE;
	extern UINT8 characters[2];
  extern UINT8 response_temp[50];
	extern UINT8 response[30];
  extern UINT8 OK_FLAG;
	extern UINT8 i;
	extern unsigned char x;
	
	#endif