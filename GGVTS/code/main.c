#include "common.h"
const int8_t * GSM_INIT[]={"AT+CMGF=1\r","AT+CMGD=1,4\r","AT+CPMS=\"SM\"\r"};
const int8_t alpha[11][2] = {"0","1","2","3","4","5","6","7","8","9","10"};
const int8_t * GSM_READ_MSG[]={"AT+CMGR="};
const int8_t * GPS_LOCATION[]={"AT+CGNSINF\r"};
const int8_t * GPS_STATUS[]={"AT+CGPSSTATUS?\r"};
const int8_t * GSM_DELETE_MSG[]={"AT+CMGD="};
const int8_t * GPS_INIT[1] = {"AT+CGPSPWR=1\r"};
const int8_t * OWNER_NUMBER[1]={"+919915990657"};
const int8_t * SEND_MESSAGE[1] = {"AT+CMGS=\""};
const int8_t * MAP_LINK[1] = {"maps.google.com/maps/place/"};
//uint32_t user_info_stored = ON;
int8_t response_temp_diag[50];
uint32_t buffer_counter_diag=0;
int8_t USER_NAME[20];
int8_t USER_NUMBER[14] ={"+919915990657"};
uint8_t IGNORE = OFF;
uint8_t SEND_LOCATION = OFF;
int8_t extracted_message[50];
int8_t extracted_number[14];
int8_t extracted_location[50];
int8_t joined_string[200];
uint32_t RESET = OFF;
uint32_t ERROR = 0;
uint8_t ENTER = 0x0D;
uint8_t ESCAPE = 0x1B;
uint8_t DATA_SEND = 0x1A;
uint32_t PARK_MODE = 0;
int8_t response_temp[200];
uint32_t REC= OFF;
uint32_t receiving = 0;
uint32_t buffer_counter=0;
uint32_t SYSTEM_STRUCT = 0;
uint32_t Ignore_Char;
uint8_t ATTEMPTS = 0;
uint32_t new_mes=0,comp=1;
volatile uint32_t new_message=0;
uint32_t Received_Message_Count=0;
int8_t LOCATION = OFF;
int8_t TIMER = OFF;
int8_t TIMER0 = OFF;
int8_t TIMER0_OVER = ON;
uint8_t Read_Message_Count = 0;
int32_t message = 0;
int8_t DELETE_MESSAGES = OFF;
uint8_t DIAGNOSE = OFF;
int8_t diagnose_data;
int8_t diagnoseDataSent;
uint8_t CmdSentCount = 0;

/***************************************************************************
*  Funtion Name: main                                                      *
*  Function prototype: int main(void)                                      *
*  Function return type: void                                              *
*  Function description: No introduction required                          *
***************************************************************************/
int main(void)
{
	IO0DIR=0X0000FFFC;
	init_module();
	if(ERROR == 0)
	{
		wait_for_message();
	}
	else
  	{
		//Do Nothing
  	}
}

/***************************************************************************
*  Funtion Name: init_module                                               *
*  Function prototype: void init_module(void)                              *
*  Function return type: void                                              *
*  Function description: This functions will initialize timer, UART and    *
*                        their interrupts                                  *
***************************************************************************/
void init_module(void)
{
	IO0CLR = IO0CLR | ERROR_INDICATOR;   	/* Switching OFF bulb */
	pll_init();
  interrupt_init();
	timer_0_init();
	timer_1_init();
	init_uart();
 	init_uart_diagnose();
 	delay(1);
 	initialize_gsm();

 	initialize_gps();
}
