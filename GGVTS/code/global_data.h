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
#define NA 5
#define TRUE 1
#define FALSE 0
#define ERROR_INDICATOR 0x00000004
	extern uint8_t IGNORE;
	extern uint8_t SEND_LOCATION;
	extern const int8_t * GSM_INIT[4];
	extern const int8_t * GSM_READ_MSG[1];
	extern const int8_t * GSM_DELETE_MSG[1];
	extern const int8_t * user_number[1];
	extern const int8_t * SEND_MESSAGE[1];
	extern const int8_t * OWNER_NUMBER[1];
	extern const int8_t alpha[11][2];
	extern int8_t USER_NAME[20];
	extern int8_t USER_NUMBER[14];
	extern const int8_t * MAP_LINK[1];
	extern uint8_t ENTER;
	extern uint32_t ERROR;
	extern uint8_t DATA_SEND;
	extern uint32_t PARK_MODE;
	extern int8_t response_temp[200];
	extern uint32_t i;
	extern uint32_t buffer_counter;
	extern uint32_t REC;
	extern uint32_t receiving;
	extern uint32_t SYSTEM_STRUCT;
	extern uint32_t Ignore_Char;
	extern uint8_t ATTEMPTS;
	extern char joined_string[200];
	extern char LOCATION;
	extern char TIMER;
	extern char TIMER0;
	extern char TIMER0_OVER;
	extern char extracted_message[50];
	extern char extracted_number[14];
	extern void init_module(void);
	extern uint32_t new_mes,comp;
	extern volatile uint32_t new_message;
	extern uint32_t Received_Message_Count;
	extern uint32_t RESET;
	extern uint8_t DIAGNOSE;
	extern int8_t diagnose_data;
	extern int8_t diagnoseDataSent;
	extern uint8_t Read_Message_Count;
	extern char DELETE_MESSAGES;
	extern uint8_t CmdSentCount;
	extern int32_t message;                                                   /* Local variable to count number of messages already read */
#endif
/********************************End of File*******************************/
