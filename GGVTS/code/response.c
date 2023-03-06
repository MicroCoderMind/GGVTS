/***************************************************************************
*  File Name: response.c				                                   *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions used to    *
*				send response to user/owner								   *
*  Author: Arora Motor Works                                               *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Below are the header files required to build project                    *
***************************************************************************/
#include "common.h"

/***************************************************************************
*  Funtion Name: check_response_command                                    *
*  Function prototype:  uint32_t check_response_command(void)                *
*  Function return type: uint32_t                                            *
*  Function description: This function will check response from GPS/GSM    *
*                        after sending command.                            *
***************************************************************************/
uint32_t check_response_command(void)
{
	while(ON)
	{
        delay(0.2);	 
	    if (!(strstr_mod(response_temp,"OK")))			/* If response from GPS/GSM module contains OK */
	    {
			ERROR = 0;
#ifdef DEBUG_START
	debug("Command response checked Without Error\n");
#endif
	      	return ERROR;      /* Return 0 if command sent successfully and OK received from module */
	    }
	    else if(!(strstr_mod(response_temp,"ERROR")))	/* If response from GPS/GSM module contains ERROR */
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
	debug(response_temp);				/* For debug purpose */
	debug("\n");
	debug("No Response\n");
#endif
		}
	}
}

/***************************************************************************
*  Funtion Name: check_response_message                                    *
*  Function prototype:  uint32_t check_response_message(void)                *
*  Function return type: uint32_t                                            *
*  Function description: This function will check response from GPS/GSM    *
*                        after sending command.                            *
***************************************************************************/
uint32_t check_response_message(void)
{
	int lcWait = OFF;
	while(ON)
	{
        delay(5);
	    if (!(strstr_mod(response_temp,"OK")))			/* If response from GSM/GPS contains OK */
	    {
			ERROR = 0;
			memset(joined_string,0,200);
	      	return 0;
	    }
	    else if(!(strstr_mod(response_temp,"ERROR")))	/* If response from GSM/GPS contains ERROR */
	    {
			U0THR = ESCAPE;
			clear_buffer();
			ERROR++;
	      	return ERROR;
	    }
		else if (lcWait == ON)							/* If response timeout happens */
		{
			U0THR = ESCAPE;
			delay(0.5);
			ERROR++;
	      	return ERROR;
		}
		else
		{
			delay(20);
			lcWait = ON;
		}
	}
}

/***************************************************************************
*  Funtion Name: response_back                                             *
*  Function prototype:  void response_back(const int8_t *,const int8_t *)      *
*  Function return type: void                                              *
*  Function description: This function contains functionality to reply     *
*                         back to USER/OWNER                               *
***************************************************************************/
void response_back(const int8_t * ph_number,const int8_t *msg)
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
  debug(msg);						/* For debug purpose */
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
		response_back(USER_NUMBER,"Greetings Mr. Arora, User Name and Number please!!!");
		return;
	}
}
/********************************End of File*******************************/
