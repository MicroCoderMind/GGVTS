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
#define __GLOBAL__
#define OFF 0
#define ON 1
#define NO 0
#define YES 1
#define NA 5
#define TRUE 1
#define FALSE 0
	
	extern const uint LED_PIN;
    extern uint8_t dataRecieved;
	extern uint8_t IGNORE;
	extern uint8_t SEND_LOCATION;
	extern char * GSM_INIT[4];
	extern char * GSM_READ_MSG[1];
	extern char * GSM_DELETE_MSG[1];
	extern char * user_number[1];
	extern char * SEND_MESSAGE[1];
	extern char * OWNER_NUMBER[1];
	extern char * alpha[11];
	extern char USER_NAME[20];
	extern char USER_NUMBER[14];
	extern char * MAP_LINK[1];
	extern uint8_t ENTER;
	extern uint8_t ERROR;
	extern uint8_t ESCAPE;
	extern uint8_t DATA_SEND;
	extern uint32_t PARK_MODE;
	extern int8_t response_temp[500];
    extern int8_t response_temp_debug[500];
	extern uint32_t i;
	extern uint32_t buffer_counter;
	extern uint32_t REC;
	extern uint32_t receiving;
	extern uint32_t SYSTEM_STRUCT;
	extern uint32_t Ignore_int8_t;
	extern uint8_t ATTEMPTS;
	extern char joined_string[200];
	extern int8_t LOCATION;
	extern int8_t TIMER;
	extern int8_t TIMER0;
	extern int8_t TIMER0_OVER;
	extern int8_t extracted_message[50];
	extern int8_t extracted_number[14];
	extern void init_module(void);
	extern uint32_t new_mes,comp;
	extern volatile uint32_t new_message;
	extern uint32_t Received_Message_Count;
	extern uint32_t RESET;
	extern uint8_t DIAGNOSE;
	extern int8_t diagnose_data;
	extern int8_t Message_Frequency;
	extern int8_t diagnoseDataSent;
	extern uint8_t Read_Message_Count;
	extern int8_t DELETE_MESSAGES;
	extern uint8_t CmdSentCount;
	extern int32_t message;                                                   /* Local variable to count number of messages already read */
	extern struct repeating_timer timer0,timer1;
#endif
/********************************End of File*******************************/
