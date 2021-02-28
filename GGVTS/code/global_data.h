/***************************************************************************
*  File Name: global_data.h                                                *
*--------------------------------------------------------------------------*
*  Description: This file contains declarations of all global parameters   *
*               used in this project.                                      *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/
#ifndef __GLOBAL__
#define __GLOBAL__ 1
#define OFF 0
#define ON 1
#define TRUE 1
#define FALSE 0
//#define DEBUG_START
    extern UINT8 IGNORE;
    extern const INT8 * GSM_INIT[4];
	extern const INT8 * GSM_READ_MSG[1];
    extern const INT8 * GSM_DELETE_MSG[1];
	extern const INT8 * user_number[1];
	extern const INT8 * SEND_MESSAGE[1];
	extern const INT8 * OWNER_NUMBER[1];
	extern const INT8 alpha[11][2];
	extern INT8 USER_NAME[20];
	extern INT8 USER_NUMBER[14];
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
		extern UINT32 CHECKING;
		extern UINT32 Ignore_Char;
	//extern UINT32 user_info_stored;
	extern char joined_string[200];
    extern char extracted_message[50];
		 extern char extracted_number[14];
		 extern void init_module(void);
		extern UINT32 new_mes,comp,new_message;
		extern UINT32 RESET;
#endif
/********************************End of File*******************************/
