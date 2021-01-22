#include "common.h"
//#define DEBUG_START
UINT32 check_response(void)
{
	int check=2;
	while(ON)
	{
		if (REC == ON)
		{
			check++;
		}
		else
		{
			delay(2);
			check--;
		}
		if(check <= 0)
		{
	      UINT32 i = strlen_mod(response_temp);
	      if (response_temp[i-4]=='O' && response_temp[i-3]=='K')
	      {
					  ERROR = 0;
	      	  return 0;
	      }
	      else if(response_temp[i-7]=='E' && response_temp[i-6]=='R'  && response_temp[i-6]=='R')
	      {
					  ERROR = 1;
	      	  return 1;
	      }
				else
				{
					check=2;
					continue;
				}
		}
  }
}

void response_to_owner(const INT8 * str1)
{
	ERROR = 1;
	while(ERROR)
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
	  check_response();
		memset(extracted_location,0,50);
		memset(extracted_message,0,50);
		memset(response_temp,0,200);
		buffer_counter = 0;
		delay(2);
	}
}


/***************************************************************************
*  Funtion Name: get_user_info                                          *
***************************************************************************/
void get_user_info(void)
{
	if (!ERROR)
	{
	    response_to_owner("Hello Mr. Arora, Please Provide User Name and Number!!");
	}
}
/********************************End of File*******************************/
