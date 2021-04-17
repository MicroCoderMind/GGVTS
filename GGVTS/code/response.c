#include "common.h"
#undef DEBUG_START
UINT32 check_response_command(void)
{
	int check=10;
	while(ON)
	{
		CHECKING = ON;
		if (REC == ON)
		{
			check++;
		}
		else
		{
			delay(0.1);
			check--;
		}
		if(check <= 0)
		{
	      UINT32 i = strlen_mod(response_temp);
	      if (!(strstr_mod(response_temp,"OK")))
	      {
					  ERROR = 0;
					  CHECKING = OFF;
	#ifdef DEBUG_START
		debug("Command response checked Without Error\n");
	#endif
	      	  return 0;
	      }
	      else if(!(strstr_mod(response_temp,"ERROR")))
	      {
					  ERROR=1;
					  CHECKING = OFF;
	#ifdef DEBUG_START
		debug("Command response checked With Error\n");
	#endif
	      	  return 1;
	      }
				else
				{
					#ifdef DEBUG_START
					    debug(response_temp);
					    debug("\n");
					    debug("No Response\n");
					#endif
				}
		}
  }
}
	
UINT32 check_response_message(void)
{
	int check=4,WAIT = OFF;
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
	      	  return 0;
	      }
	      else if(!(strstr_mod(response_temp,"ERROR")))
	      {
					  ERROR=1;
					  CHECKING = OFF;
	      	  return 1;
	      }
				else if (WAIT == ON)
				{
					  U0THR = ESCAPE;
					  delay(0.5);
						ERROR=1;
					  CHECKING = OFF;
	      	  return 1;
				}
				else
				{
					delay(20);
					WAIT = ON;
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
#endif
	  gsm_transmit(msg);
	  delay(0.2);
		memset(response_temp,0,200);
		buffer_counter = 0;
		U0THR = DATA_SEND;
	  check_response_message();
		memset(extracted_location,0,50);
		delay(0.05);
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
