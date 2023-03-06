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
#define DEBUG_START
/***************************************************************************
*  Funtion Name: gsm_init                                                  *
*  Function prototype: void gsm_init()                                     *
*	 Function return type: void                                              *
*  Function description: This function will intialize gsm module           *
*  and also check whether gsm intialized or not                            *
***************************************************************************/
void gsm_init()
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
	    		//response_back(USER_NUMBER,"Initialization Unsuccessfull!! Trying Again...");
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
		//response_back(USER_NUMBER,"Initialising System!!! Please Wait...");
	}
}

/***************************************************************************
*  Funtion Name: gsm_transmit                                              *
*  Function prototype: void gsm_transmit(const INT8 * str1)                *
*  Function return type: void                                              *
*  Function description: This function will transmitt commands to GSM      *
*  through UART0.                                                          *
***************************************************************************/
void gsm_transmit(const INT8 * str1)
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
*  Function prototype: void read_message(UINT32 message)                   *
*  Function return type: void                                              *
*  Function description: This function will read message after extracting. *
***************************************************************************/
void read_message(UINT32 message)
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

/***************************************************************************
*  Function Name: delete_message                                           *
*  Function prototype: void delete_message(UINT32 message)                 *
*  Function return type: void                                              *
*  Function description: This function will delete the messages            *
***************************************************************************/
void delete_message(UINT32 message)
{
	clear_buffer();     /* Clear the main buffer */
	delay(0.5);
	join_strings(GSM_DELETE_MSG[0],alpha[message]);
	join_strings(",2","\r");
	gsm_transmit(joined_string);
	memset(joined_string,0,200);
	clear_buffer();     /* Clear the main buffer */
	delay(0.5);
}
/******************************End of File*********************************/
