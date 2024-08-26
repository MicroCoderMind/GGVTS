#include "common.h"

void initGSM()
{
	if (!ERROR)
	{
	    int k;
	    for (k=0;k<4;k++)
	    {
	      	sendDataOverUART(GSM_INIT[k]);
#ifdef DEBUG_START
    sendDataOverDebug(GSM_INIT[k]);
#endif // DEBUG
			CmdSentCount++;
	    	if (!checkResponse())
	    	{
				clear_buffer();
				CmdSentCount = 0;
	    	}
	    	else
	    	{
				clear_buffer();     /* Clear the main buffer */
				if (CmdSentCount < 5)
				{
					k--;
				}
				else
				{
					ERROR++;
					CmdSentCount = 0;
					reset_module(0);
				}
	    	}
	    }
    }
	if (ERROR == 0)
	{
		//response_back(USER_NUMBER[0],"GSM Initialized, Initializing GPS please wait...");
	}
}


void extract_message(void)
{
	uint32_t i,j=0,lcNewLines=0,lcSemicolons=0;
	
	for (i=0;i<strlen_mod(response_temp);i++)
	{
		if (response_temp[i] == 0x0A)
		{
			lcNewLines++;
		}
		else if(lcNewLines == 2 && (response_temp[i] != 0x0D || response_temp[i] != 0x0A))
		{
			extracted_message[j++] = response_temp[i];
		}
		else
		{
			continue;
		}
	}
	extracted_message[j-1] = '\0';
	j=0;
	sleep_ms(200);
#ifdef DEBUG_START
	sendDataOverDebug(extracted_message);				/* For debug purpose */
#endif
	for (i=0;i<strlen(response_temp);i++)
	{
		if (response_temp[i] == '"')
		{
			lcSemicolons++;
		}
		else if(lcSemicolons == 3 && (response_temp[i] != 0x0D || response_temp[i] != 0x0A))
		{
			extracted_number[j++] = response_temp[i];
		}
		else
		{
			continue;
		}
	}
	extracted_number[j] = '\0';
#ifdef DEBUG_START
	sendDataOverDebug(extracted_number);				/* For debug purpose */
#endif
	sleep_ms(200);
}

/***************************************************************************
*  Funtion Name: read_message                                              *
*  Function prototype: void read_message(uint32_t message)                   *
*  Function return type: void                                              *
*  Function description: This function will read message after extracting. *
***************************************************************************/
void read_message(uint32_t message)
{
	clear_buffer();     /* Clear the main buffer */
	join_strings(GSM_READ_MSG[0],alpha[message]);
	join_strings("","\r");
	sendDataOverUART(joined_string);
	sleep_ms(1000);
	memset(joined_string,0,200);
	new_message--;
	Read_Message_Count++;
	extract_message();
	clear_buffer();     /* Clear the main buffer */
}

void delete_message(void)
{
	sendDataOverUART("AT+CMGD=1,4\r");
}