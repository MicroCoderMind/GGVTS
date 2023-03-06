/***************************************************************************
*  File Name: gsm.c                                                        *
*--------------------------------------------------------------------------*
*  Description: This file contains definitions of all functions            *
*               which are performing GSM related functionality.            *
*  Author: Arora Motor Works											                         *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                             *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Below are required header files					                               *
***************************************************************************/
#include "common.h"
/***************************************************************************
*  Funtion Name: initialize_gsm                                            *
*  Function prototype: void initialize_gsm(void)                           *
*  Function return type: void                                              *
*  Function description: This function will intialize gsm module           *
*  and also check whether gsm intialized or not                            *
***************************************************************************/
void initialize_gsm()
{
	if (!ERROR)
	{
	    int k;
	    for (k=0;k<3;k++)
	    {
	      	gsm_transmit(GSM_INIT[k]);
			CmdSentCount++;
	    	if (!check_response_command())
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
					reset_module(OFF);
				}
	    	}
	    }
    }
	if (ERROR == 0)
	{
		//response_back(USER_NUMBER,"GSM Initialized, Initializing GPS please wait...");
	}
}

/***************************************************************************
*  Funtion Name: gsm_transmit                                              *
*  Function prototype: void gsm_transmit(const int8_t * str1)                *
*  Function return type: void                                              *
*  Function description: This function will transmitt commands to GSM      *
*  through UART0.                                                          *
***************************************************************************/
void gsm_transmit(const int8_t * str1)
{
	unsigned int k;
	for (k=0;k<strlen_mod(str1);k++)
	{
	    IO0SET = 0x00000008;
	    U0THR = str1[k];
	    delay(0.02);
	}
#ifdef DEBUG_START
  	debug(response_temp);
#endif
}

/***************************************************************************
*  Function Name: extract_message                                          *
*  Function prototype: void extract_message(void)                          *
*  Function return type: void                                              *
*  Function description: This function will extract received message from  *
*  GSM. as well as number of user also.                                    *
***************************************************************************/
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
	delay(0.2);
#ifdef DEBUG_START
	debug(extracted_message);				/* For debug purpose */
	debug("\n");
#endif
	for (i=0;i<strlen_mod(response_temp);i++)
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
	debug(extracted_number);				/* For debug purpose */
#endif
	delay(0.2);
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
	gsm_transmit(joined_string);
	delay(1);
	memset(joined_string,0,200);
	new_message--;
	Read_Message_Count++;
	extract_message();
	clear_buffer();     /* Clear the main buffer */
}

/******************************End of File*********************************/
