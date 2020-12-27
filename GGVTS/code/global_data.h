  #ifndef __GLOBAL__
	#define __GLOBAL__ 1
	#define OFF 0
  #define ON 1
  #define LCD P2
  extern const INT8 * GSM_INIT[4];
	extern const INT8 * GSM_READ_MSG[1];
  extern const INT8 * GSM_DELETE_MSG[1];
	extern const INT8 * user_number[1];
	extern const INT8 * SEND_MESSAGE[1];
	extern const INT8 * USER_NUMBER[1];
	extern const INT8 * MAP_LINK[1];
  extern UINT8 ENTER;
	extern UINT32 ERROR;
  extern UINT8 DATA_SEND;
  extern UINT32 PARK_MODE;
  extern INT8 response_temp[200];
	extern UINT32 i;
	extern UINT32 buffer_counter;
	extern UINT32 REC;
	extern UINT32 receiving;
	extern UINT32 ATTEMPTS;
	extern UINT32 SYSTEM_STRUCT;
  extern char extracted_message[50];
	#endif
