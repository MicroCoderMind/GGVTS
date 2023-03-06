#include "common.h"
//#define DEBUG_START

/***************************************************************************
*  Funtion Name: check_response_command                                    *
*  Function prototype:  UINT32 check_response_command(void)                *
*  Function return type: UINT32                                            *
*  Function description: This function will check response from GPS/GSM    *
*                        after sending command.                            *
***************************************************************************/
UINT32 check_response_command(void)
{
	while(ON)
	{
        delay(0.2);
	      UINT32 i = strlen_mod(response_temp);
	      if (!(strstr_mod(response_temp,"OK")))
	      {
					  ERROR = 0;
	#ifdef DEBUG_START
		debug("Command response checked Without Error\n");
	#endif
	      	  return ERROR;      /* Return 0 if command sent successfully and OK received from module */
	      }
	      else if(!(strstr_mod(response_temp,"ERROR")))
	      {
					  ERROR=1;
	#ifdef DEBUG_START
		debug("Command response checked With Error\n");
	#endif
	      	  return ERROR;      /* Return 1 if command was not sent successfully and ERROR received from module */
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

/***************************************************************************
*  Funtion Name: check_response_message                                    *
*  Function prototype:  UINT32 check_response_message(void)                *
*  Function return type: UINT32                                            *
*  Function description: This function will check response from GPS/GSM    *
*                        after sending command.                            *
***************************************************************************/
UINT32 check_response_message(void)
{
	int WAIT = OFF;
	while(ON)
	{
        delay(5);
	      if (!(strstr_mod(response_temp,"OK")))
	      {
					  ERROR = 0;
					  memset(joined_string,0,200);
	      	  return 0;
	      }
	      else if(!(strstr_mod(response_temp,"ERROR")))
	      {
					  U0THR = ESCAPE;
					  clear_buffer();
					  ERROR++;
	      	  return ERROR;
	      }
				else if (WAIT == ON)
				{
					  U0THR = ESCAPE;
					  delay(0.5);
					  ERROR++;
	      	  return ERROR;
				}
				else
				{
					delay(20);
					WAIT = ON;
				}
	}
}

/***************************************************************************
*  Funtion Name: response_back                                             *
*  Function prototype:  void response_back(const INT8 *,const INT8 *)      *
*  Function return type: void                                              *
*  Function description: This function contains functionality to reply     *
*                         back to USER/OWNER                               *
***************************************************************************/
void response_back(const INT8 * ph_number,const INT8 *msg)
{
	ERROR = 1;
	while(ERROR)
	{
		memset(joined_string,0,200);
		clear_buffer();
		delay(1);
		join_strings(SEND_MESSAGE[0],ph_number);
	  join_strings("","\"\r");
		gsm_transmit(joined_string);
#ifdef DEBUG_START
  debug(msg);
#endif
	  gsm_transmit(msg);
	  delay(0.2);
		U0THR = DATA_SEND;
	  check_response_message();
		if (ERROR > 5)
		{
			reset_module(ON);
			ERROR = 1;
		}
		memset(extracted_location,0,50);
		delay(0.05);
		memset(joined_string,0,200);
		clear_buffer();     /* Clear the main buffer */
#ifdef DEBUG_START
  debug(response_temp);
#endif
	}
}


/***************************************************************************
*  Funtion Name: get_user_info                                             *
*  Function prototype:  void get_user_info(void)                           *
*  Function return type: void                                              *
*  Function description: This function will ask for USER info from OWNER   *
***************************************************************************/
void get_user_info(void)
{
	if (!ERROR)
	{
	  response_back(USER_NUMBER,"User name and mumber please!!!");
		return;
	}
}
/********************************End of File*******************************/
