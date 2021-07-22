#include "common.h"
const INT8 * GSM_INIT[]={"AT+CMGF=1\r","AT+CMGD=1,4\r","AT+CPMS=\"SM\"\r"};
const INT8 alpha[11][2] = {"0","1","2","3","4","5","6","7","8","9","10"};
const INT8 * GSM_READ_MSG[]={"AT+CMGR="};
const INT8 * GPS_LOCATION[]={"AT+CGNSINF\r"};
const INT8 * GPS_STATUS[]={"AT+CGPSSTATUS?\r"};
const INT8 * GSM_DELETE_MSG[]={"AT+CMGD="};
const INT8 * GPS_INIT[1] = {"AT+CGPSPWR=0\r"};
const INT8 * OWNER_NUMBER[1]={"+919915990657"};
const INT8 * SEND_MESSAGE[1] = {"AT+CMGS=\""};
const INT8 * MAP_LINK[1] = {"maps.google.com/maps/place/"};
//UINT32 user_info_stored = ON;
INT8 response_temp_diag[50];
UINT32 buffer_counter_diag=0;
INT8 USER_NAME[20];
INT8 USER_NUMBER[14] ={"+919915990657"};
UINT8 IGNORE = OFF;
UINT8 SEND_LOCATION = OFF;
char extracted_message[50];
char extracted_number[14];
char extracted_location[50];
char joined_string[200];
UINT32 RESET = OFF;
UINT32 ERROR = 0;
UINT8 ENTER = 0x0D;
UINT8 ESCAPE = 0x1B;
UINT8 DATA_SEND = 0x1A;
UINT32 PARK_MODE = 0;
INT8 response_temp[200];
UINT32 REC= OFF;
UINT32 receiving = 0;
UINT32 buffer_counter=0;
UINT32 ATTEMPTS = 0;
UINT32 SYSTEM_STRUCT = 0;
UINT32 CHECKING = OFF;
UINT32 Ignore_Char;
UINT32 new_mes=0,comp=1;
volatile UINT32 new_message=0;
UINT32 Received_Message_Count=0;
char LOCATION = OFF;
char TIMER = OFF;
UINT8 Read_Message_Count = 0;
INT32 message = 0;
char DELETE_MESSAGES = OFF;

int main(void)
{
	BASE:
	if (ATTEMPTS == 2)
	{
		SYSTEM_STRUCT++;
		//reset_module();
	}
	IO0DIR=0X0000FFFC;
	pll_init();
	timer_0_init();
	timer_1_init();
	uart_init();
  	uart_init_debug();
  	interrupt_init();
  	delay(1);
     gsm_init();
 	  gps_init();
		#ifdef DEBUG_START
	debug(response_temp);
  #endif
	if(!ERROR)
	{
		wait_for_message();
	}
	
    if(ERROR > 0)
	{
	    ATTEMPTS++;
		ERROR=0;
		goto BASE;
	}
}

void init_module(void)
{
	 
}
