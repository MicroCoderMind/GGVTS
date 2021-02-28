#include "common.h"
UINT32 check_response(void)
{
	int check=2,timer =OFF;
	T1MCR = 0x07;				 //Tell processor to reset timer after 1 sec
	while(ON)
	{
		CHECKING = ON;
		if (REC == ON)
		{
			check++;
		}
		else
		{
			delay(1);
			check--;
		}
		if(check <= 0)
		{
	      UINT32 i = strlen_mod(response_temp);
	      if (!(strstr_mod(response_temp,"OK")))
	      {
					  ERROR = 0;
					  CHECKING = OFF;
					module_reset_timer(OFF);
						  T1MCR = 0x06;				 //Tell processor to reset timer after 1 sec
	      	  return 0;
	      }
	      else if(!(strstr_mod(response_temp,"ERROR")))
	      {
					  ERROR=1;
					  CHECKING = OFF;
					module_reset_timer(OFF);
					T1MCR = 0x06;				 //Tell processor to reset timer after 1 sec
	      	  return 1;
	      }
				else if (RESET == OFF)
					{
						if(timer == OFF)
						{
								module_reset_timer(ON);
							timer = ON;
						}
						continue;
					}
					else if (RESET == ON && !(strstr_mod(response_temp,"READY")))
					{
						RESET = OFF;
						CHECKING = OFF;
						 T1MCR = 0x06;				 //Tell processor to reset timer after 1 sec
						module_reset_timer(OFF);
						ERROR=1;
						return 1;
					}
		}
  }
}

void response_back(const INT8 * ph_number,const INT8 *msg)
{
	ERROR = 1;
	while(ERROR)
	{
		join_strings(SEND_MESSAGE[0],ph_number);
		join_strings("","\"\r");
		gsm_transmit(joined_string);
		memset(joined_string,0,200);
#ifdef DEBUG_START
  debug(msg);
	debug("Next");
#endif
	  gsm_transmit(msg);
	  delay(1);
				memset(response_temp,0,200);
		buffer_counter = 0;
		U0THR = DATA_SEND;
	  check_response();
		delay(2);
		memset(extracted_location,0,50);
		delay(8);
		memset(response_temp,0,200);
		buffer_counter = 0;
	}
	memset(joined_string,0,200);
}


/***************************************************************************
*  Funtion Name: get_user_info                                          *
***************************************************************************/
void get_user_info(void)
{
	if (!ERROR)
	{
	    response_back(USER_NUMBER,"User NAme and mumber please!!!");
		return;
	}
}
/********************************End of File*******************************/
