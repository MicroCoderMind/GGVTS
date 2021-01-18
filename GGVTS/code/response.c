#include "common.h"
//#define DEBUG_START
UINT32 check_response(void)
{
	UINT32 i = strlen_mod(response_temp);
	if (response_temp[i-4]=='O' && response_temp[i-3]=='K')
	{
		  memset(response_temp,0,200);
		  buffer_counter = 0;
		  return 0;
	}
	else
	{
		  memset(response_temp,0,200);
		  buffer_counter = 0;
		  return 1;
	}
}

void response_to_owner(const INT8 * str1)
{
		join_strings(SEND_MESSAGE[0],OWNER_NUMBER[0]);
		join_strings("","\"\r");
	#ifdef DEBUG_START
		debug(joined_string);
	#endif
		gsm_transmit(joined_string);
		memset(joined_string,0,100);
	  gsm_transmit(str1);
	  delay(1);
		U0THR = DATA_SEND;
		delay(0.2);
		memset(extracted_location,0,50);
		memset(extracted_message,0,50);
		memset(response_temp,0,200);
		buffer_counter = 0;
		delay(2);
}


/***************************************************************************
*  Funtion Name: get_user_info                                          *
***************************************************************************/
void get_user_info(void)
{
	if (!ERROR)
	{
	    response_to_owner("Hello Mr. Arora, Please Provide User Name and Number!!");
		  delay(0.5);
	}
}
/********************************End of File*******************************/
