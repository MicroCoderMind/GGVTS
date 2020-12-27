#include "common.h"
//#define DEBUG_START
UINT32 check_response(void)
{
	UINT32 i = strlen_mod(response_temp);
	if (response_temp[i-4]=='O' && response_temp[i-3]=='K')
	{
//		U1THR = response_temp[i-3];
//		delay(9);
//		U1THR = response_temp[i-4];
//		delay(9);
		  memset(response_temp,0,200);
		  buffer_counter = 0;
		  return 0;
	}
	else
	{
//		delay(1);
//		debug(response_temp);
//		U1THR = response_temp[i-3];
//		delay(9);
//		U1THR = response_temp[i-4];
//		delay(9);
		memset(response_temp,0,200);
		buffer_counter = 0;
//		while(1);
		return 1;
	}
}

void collecting_location_info(void)
{
		join_strings(SEND_MESSAGE[0],USER_NUMBER[0]);
		join_strings("","\"\r");
	#ifdef DEBUG_START
		debug(joined_string);
	#endif
		gsm_transmit(joined_string);
		memset(joined_string,0,100);
	  gsm_transmit("Collecting Location Info!!! Please Wait...");
		U0THR = DATA_SEND;
		delay(0.2);
		memset(extracted_location,0,50);
		memset(extracted_message,0,50);
		memset(response_temp,0,200);
		buffer_counter = 0;
		delay(2);
}

void response_to_user(const INT8 * str1)
{
		join_strings(SEND_MESSAGE[0],USER_NUMBER[0]);
		join_strings("","\"\r");
	#ifdef DEBUG_START
		debug(joined_string);
	#endif
		gsm_transmit(joined_string);
		memset(joined_string,0,100);
	  gsm_transmit(str1);
		U0THR = DATA_SEND;
		delay(0.2);
		memset(extracted_location,0,50);
		memset(extracted_message,0,50);
		memset(response_temp,0,200);
		buffer_counter = 0;
		delay(2);
}
