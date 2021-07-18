/***************************************************************************
*  File Name: gsm.c                                                        *
*--------------------------------------------------------------------------*
*  Description: This file contains definitions of all functions            *
*               which are performing GSM related functionality.            *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Below are the header files required to build project                    *
***************************************************************************/
#include "common.h"
//#define DEBUG_START
/***************************************************************************
*  Funtion Name: gsm_init                                                  *
***************************************************************************/
void gsm_init()
{
	BUSY = ON;
	if (!ERROR)
	{
	    unsigned int k;
	    for (k=0;k<3;k++)
	    {
	      gsm_transmit(GSM_INIT[k]);
	    	if (!check_response_command())
	    	{
	    				buffer_counter = 0;
	  	        memset(response_temp,0,200);
	    	}
	    	else
	    	{
	    		response_back(USER_NUMBER,"Initialization Unsuccessfull!! Trying Again...");
							buffer_counter = 0;
	  	        memset(response_temp,0,200);
					BUSY = OFF;
	    		return;
	    	}
	    }
    }
	if (ERROR == 0)
	{
		//response_back(USER_NUMBER,"Initialising System!!! Please Wait...");
	}
	BUSY = OFF;
}

/***************************************************************************
*  Funtion Name: gsm_transmit                                              *
***************************************************************************/
void gsm_transmit(const INT8 * str1)
{
	unsigned int k;
	BUSY = ON;
	for (k=0;k<strlen_mod(str1);k++)
	{
	    IO0SET = 0x00000008;
	    U0THR = str1[k];
	    delay(0.08);
	}
#ifdef DEBUG_START
  	debug(response_temp);
#endif
	IO0CLR = 0x00000008;
	BUSY = OFF;
}

/***************************************************************************
*  Funtion Name: extract_message                                           *
***************************************************************************/
void extract_message(void)
{
	UINT32 i,j=0,new_lines=0,semicolons=0;
	
	for (i=0;i<strlen_mod(response_temp);i++)
	{
		if (response_temp[i] == 0x0A)
		{
			new_lines++;
		}
		else if(new_lines == 2 && (response_temp[i] != 0x0D || response_temp[i] != 0x0A))
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
	debug(extracted_message);
#endif
#ifdef DEBUG_START
	debug("\n");
#endif
	for (i=0;i<strlen_mod(response_temp);i++)
	{
		if (response_temp[i] == '"')
		{
			semicolons++;
		}
		else if(semicolons == 3 && (response_temp[i] != 0x0D || response_temp[i] != 0x0A))
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
	debug(extracted_number);
#endif
	delay(0.2);
}

/***************************************************************************
*  Funtion Name: read_message                                              *
***************************************************************************/
void read_message(UINT32 message)
{
	  memset(response_temp,0,200);
	  buffer_counter = 0;
	  join_strings(GSM_READ_MSG[0],alpha[message]);
	  join_strings("","\r");
		gsm_transmit(joined_string);
		delay(1);
	  memset(joined_string,0,200);
		new_message--;
		extract_message();
		buffer_counter = 0;
	  memset(response_temp,0,200);
}

/***************************************************************************
*  Funtion Name: delete_message                                            *
***************************************************************************/
void delete_message(UINT32 message)
{
	buffer_counter = 0;
	memset(response_temp,0,200);
	delay(0.5);
	join_strings(GSM_DELETE_MSG[0],alpha[message]);
	join_strings(",2","\r");
	gsm_transmit(joined_string);
	memset(joined_string,0,200);
	buffer_counter = 0;
	memset(response_temp,0,200);
	delay(0.5);
}
/******************************End of File*********************************/
