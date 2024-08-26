#include "common.h"

void response_back(const char * ph_number,const char *msg)
{
	ERROR = 1;
	while(ERROR)
	{
		memset(joined_string,0,200);
		clear_buffer();
		sleep_ms(100);
		join_strings(SEND_MESSAGE[0],ph_number);
#ifdef DEBUG_START
  sendDataOverDebug("\n");						/* For debug purpose */
  sendDataOverDebug(joined_string);						/* For debug purpose */
#endif
		join_strings("","\"\r");
		sleep_ms(100);
		sendDataOverUART(joined_string);
		sleep_ms(100);
#ifdef DEBUG_START
  sendDataOverDebug("\n");						/* For debug purpose */
  sleep_ms(100);
  sendDataOverDebug(joined_string);						/* For debug purpose */
  sleep_ms(100);
  sendDataOverDebug(msg);						/* For debug purpose */
  sleep_ms(100);
#endif
	  	sendDataOverUART(msg);
	  	sleep_ms(200);
		uart_putc_raw(UART1_ID,DATA_SEND);
		sleep_ms(50);
	  	check_response_message();
		if (ERROR > 5)
		{
			reset_module(ON);
			ERROR = 1;
		}
		memset(extracted_location,0,50);
		sleep_ms(50);
		memset(joined_string,0,200);
		clear_buffer();     /* Clear the main buffer */
#ifdef DEBUG_START
  sendDataOverDebug(response_temp);
#endif
	}
}

uint8_t check_response_message(void)
{
	int lcWait = OFF;
	while(ON)
	{
        sleep_ms(5000);
	    if (!(strstr_mod(response_temp,"OK")))			/* If response from GSM/GPS contains OK */
	    {
			ERROR = 0;
			memset(joined_string,0,200);
	      	return 0;
	    }
	    else if(!(strstr_mod(response_temp,"ERROR")))	/* If response from GSM/GPS contains ERROR */
	    {
			uart_putc(UART1_ID,ESCAPE);
			clear_buffer();
			ERROR++;
	      	return ERROR;
	    }
		else if (lcWait == ON)							/* If response timeout happens */
		{
			uart_putc(UART1_ID,ESCAPE);
			sleep_ms(500);
			ERROR++;
	      	return ERROR;
		}
		else
		{
			sleep_ms(12);
			lcWait = ON;
		}
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