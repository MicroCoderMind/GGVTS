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

//#define DEBUG_START    /*This macro is used to enable debug related code*/

/***************************************************************************
*  Funtion Name: gsm_init                                                  *
***************************************************************************/
void gsm_init()
{
	if (!ERROR)
	{
	    unsigned int k;
	    for (k=0;k<3;k++)
	    {
	      gsm_transmit(GSM_INIT[k]);
	    	if (!check_response())
	    	{
	    		//Do Nothing
	    	}
	    	else
	    	{
	    		ERROR++;
	    		//response_to_owner("Initialization Unsuccessfull!! Trying Again...");
	    		return;
	    	}
	    }
    }
	if (ERROR == 0)
	{
		//response_to_owner("Initialising System!!! Please Wait...");
	}
}

/***************************************************************************
*  Funtion Name: gsm_transmit                                              *
***************************************************************************/
void gsm_transmit(const INT8 * str1)
{
	unsigned int k;
	for (k=0;k<strlen_mod(str1);k++)
	{
	    IO0SET = 0x00000008;
	    U0THR = str1[k];
	    delay(15);
	}
#ifdef DEBUG_START
  	debug(response_temp);
#endif
	IO0CLR = 0x00000008;
}

/***************************************************************************
*  Funtion Name: extract_message                                           *
***************************************************************************/
void extract_message(void)
{
	UINT32 i,j=0,new_lines=0;
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
#ifdef DEBUG_START
	debug(extracted_message);
#endif
	memset(response_temp,0,200);
	buffer_counter = 0;
}

/***************************************************************************
*  Funtion Name: read_message                                              *
***************************************************************************/
void read_message(void)
{
	unsigned int k;
	buffer_counter = 0;
	REC = OFF;
	if (strcmp(response_temp,"\r\n+CMTI: \"SM\",1\r\n")==0)
	{
		memset(response_temp,0,200);
		for (k=0;k<strlen_mod(GSM_READ_MSG[0]);k++)
		{
		    IO0SET = 0x00000008;
		    U0THR = GSM_READ_MSG[0][k];
		    delay(15);
		}
		delay(2);
	    IO0CLR = 0x00000008;
#ifdef DEBUG_START
		debug(response_temp);
#endif
		REC = OFF;
		buffer_counter = 0;
		extract_message();
	}
}

/***************************************************************************
*  Funtion Name: delete_message                                            *
***************************************************************************/
void delete_message(void)
{
	unsigned int k;
	for (k=0;k<strlen_mod(GSM_DELETE_MSG[0]);k++)
	{
	    IO0SET = 0x00000008;
	    U0THR = GSM_DELETE_MSG[0][k];
	    delay(9);
	}
	delay(2);
	   IO0CLR = 0x00000008;
	buffer_counter = 0;
	REC = OFF;
	memset(response_temp,0,200);
}
/******************************End of File*********************************/
