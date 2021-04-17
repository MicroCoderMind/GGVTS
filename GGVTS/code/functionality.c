/***************************************************************************
*  File Name: functionality.c                                              *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions in which   *
*               different kind og functionalities are performed            *
*               for eg. join strings, counting string length etc.          *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Below are the header files required to build project                    *
***************************************************************************/
#include"common.h"
#undef DEBUG_START
/***************************************************************************
*  Funtion Name: join_strings                                              *
***************************************************************************/
void join_strings(const INT8 * str1,const INT8 *str2)
{
		UINT32 i=strlen_mod(joined_string),j;
		for (j=0;j<strlen_mod(str1);j++)
		{
			joined_string[i++] = str1[j];
		}
		i=strlen_mod(joined_string);
		for (j=0;j<strlen_mod(str2);j++)
		{
			joined_string[i++] = str2[j];
		}
		joined_string[i] = '\0';
}

/***************************************************************************
*  Funtion Name: strlen_mod                                                *
***************************************************************************/
UINT32 strlen_mod(const char * ptr)
{
	int i;
	UINT32 j=0;
	for (i=0;ptr[i]!='\0';i++)
	{
		j++;
	}
	return j;
}

/***************************************************************************
*  Funtion Name: strcpy_mod                                                *
***************************************************************************/
void strcpy_mod(char * str1,char * str2)
{
	UINT32 i;
	for (i=0;str2[i]!='\0';i++)
	{
		str1[i] = str2[i];
	}
	str1[i] = '\n';
}
/***************************************************************************
*  Funtion Name: strcmp_mod                                                *
***************************************************************************/
INT32 strcmp_mod(const char * str1, const char * str2)
{
	INT32 i,return_var=0;
	if (strlen_mod(str1) == strlen_mod(str2))
	{
		for(i=0; i<strlen_mod(str1); i++)
		{
			if (str1[i] == str2[i])
			{
				continue;
			}
			else
			{
				return_var = -1;
				break;
			}
		}
	}
	else
  {
		return_var = -1;
	}
	return return_var;
}

/***************************************************************************
*  Funtion Name: functionality                                             *
***************************************************************************/
void functionality(UINT32 message)
{
	UINT32 in_message=0;
	char temp_reply[200];
#ifdef DEBUG_START
  debug(extracted_message);
#endif
		if (strcmp_mod(extracted_message,"Bulb ON\0") == 0)
		{
			if (IGNORE == OFF)
			{
			  IO0SET = IO0SET | 0x00000010;
			  delay(0.1);
			  memset(extracted_message,0,50);
				in_message=0;
			}
			else
			{
				in_message = 1;
			}
		}
		else if(strcmp_mod(extracted_message,"Bulb OFF\0") == 0)
		{
			if (IGNORE == OFF)
			{
			  IO0CLR = 0x00000010;
			  delay(1);
				in_message=0;
			}
			else
			{
				in_message = 1;
			}
		}
		else if(strcmp_mod(extracted_message,"LCTN\0") == 0)
		{
			if (IGNORE == OFF)
			{
        send_location();
			  delay(1);
				in_message=0;
			}
			else
			{
				in_message = 1;
			}
		}
		else if(strcmp_mod(extracted_message,"LCTN FREQ 1\0") == 0)
		{
			if (IGNORE == OFF)
			{
			  set_location_frequency(1);
			  delay(1);
				in_message=0;
			}
			else
			{
				in_message = 1;
			}
		}
		else if(strcmp_mod(extracted_message,"LCTN FREQ 3\0") == 0)
		{
			if (IGNORE == OFF)
			{
			  set_location_frequency(3);
			  delay(1);
				in_message=0;
			}
			else
			{
				in_message = 1;
			}
		}
		else if(strcmp_mod(extracted_message,"LCTN FREQ 5\0") == 0)
		{
			if (IGNORE == OFF)
			{
			  set_location_frequency(5);
			  delay(1);
				in_message=0;
			}
			else
			{
				in_message = 1;
			}
		}
		else if(strcmp_mod(extracted_message,"LCTN FREQ 7\0") == 0)
		{
			if (IGNORE == OFF)
			{
			  set_location_frequency(7);
			  delay(1);
				in_message=0;
			}
			else
			{
				in_message = 1;
			}
		}
		else if(strcmp_mod(extracted_message,"LCTN FREQ 10\0") == 0)
		{
			if (IGNORE == OFF)
			{
			  set_location_frequency(10);
			  delay(1);
				in_message=0;
			}
			else
			{
				in_message = 1;
			}
		}
		else if(strcmp_mod(extracted_message,"LCTN FREQ 0\0") == 0)
		{
			if (IGNORE == OFF)
			{
				SEND_LOCATION = OFF;
				T1TCR = 0x02;        //Stop Timer
	      delay(1);
				response_back(USER_NUMBER,"LCTN_FREQ stopped!!!");
				in_message=0;
			}
			else
			{
				in_message = 1;
			}
		}
		else
		{
			if (IGNORE == OFF)
			{
			  response_back(USER_NUMBER,"Unrecognised Command, Try Again!!!");
			  delay(0.1);
			  memset(extracted_message,0,50);
				in_message=0;
			}
		}
		if (IGNORE == ON && in_message == 1)
		{
		  join_strings("Security Violation Alert!!!","\n");
		  join_strings(extracted_number,extracted_message);
			strcpy_mod(temp_reply,joined_string);
			delay(0.1);
			memset(joined_string,0,200);
		  response_back(USER_NUMBER,temp_reply);
		  IGNORE = OFF;
		  delay(0.1);
		}
		else if(IGNORE == ON && in_message == 0)
		{
			join_strings(extracted_number,extracted_message);
			strcpy_mod(temp_reply,joined_string);
			delay(0.1);
			memset(joined_string,0,200);
		  response_back(USER_NUMBER,temp_reply);
		  IGNORE = OFF;
		  delay(0.1);
		}
		memset(temp_reply,0,200);
		memset(extracted_message,0,50);
		memset(extracted_number,0,14);
}

/***************************************************************************
*  Funtion Name: wait_for_message                                          *
***************************************************************************/
void wait_for_message()
{
	UINT32 user_info_stored = ON;
	if (user_info_stored)
	{
			response_back(USER_NUMBER,"User Name and Number please!!!");
	}
	int message=0;
	buffer_counter = 0;
	memset(response_temp,0,200);
	while(ON)
	{
		delay(0.1);
	  if (!ERROR && user_info_stored == OFF)
	  {
	  	if(REC == OFF)
	  	{
				message=0;
				delay(0.1);
	  		while(new_message > 0)
	  		{	
				  message++;
	  			delay(0.1);
	  			memset(response_temp,0,200);
	        buffer_counter = 0;
					if (!CHECKING)
					{
	  	      read_message(message);
						check_authentication(extracted_number);
	  	      functionality(message);
						delete_message(message);
					}
#ifdef DEBUG_START
  debug(alpha[new_message]);
#endif
					#ifdef DEBUG_START
  debug(alpha[message]);
#endif
					}
				if (SEND_LOCATION == ON)
				{
					send_location();
					SEND_LOCATION = OFF;
				  T1TCR = 0x01;        //Start Timer
				}
			}
			else
			{
#ifdef DEBUG_START
  debug(response_temp);
#endif
				continue;
			}
	}
	else if(!ERROR && user_info_stored)
	{

			
			if(REC == OFF)
			{message=0;
				while(new_message > 0)
				{	
					message++;
			    delay(0.5);
#ifdef DEBUG_START
  debug(response_temp);
#endif
			    read_message(message);
			    user_info_stored = extract_user_info();
			    delete_message(message);
				  break;
				}
			}
	 }
	else
	{
#ifdef DEBUG_START
	debug(alpha[new_message]);
#endif
			continue;
	}
 }
}


/***************************************************************************
*  Funtion Name: extract_user_info                                           *
***************************************************************************/
UINT32 extract_user_info(void)
{
	UINT32 i,j;
	char temp[200];
	for (i=0;extracted_message[i] != ' ';i++)
	{
		USER_NAME[i]=extracted_message[i];
	}
	USER_NAME[i]='\0';
	#ifdef DEBUG_START
	debug(USER_NAME);
  #endif
	if(extracted_message[i+1]!='+')
	{
		response_back(USER_NUMBER,"Invalid Format!!! Try again!! Pro Tip: Add Country code!!");
					memset(extracted_message,0,50);
			memset(extracted_number,0,14);
		return ON;
	}
	else
	{
		for (j=0,i++;j<14;j++)
		{
			USER_NUMBER[j] = extracted_message[i++];
		}
	}
	#ifdef DEBUG_START
	debug(USER_NUMBER);
	debug(alpha[OFF]);
  #endif
	join_strings("Hello Mr. ",USER_NAME);
	strcpy_mod(temp,joined_string);
	memset(joined_string,0,200);
  response_back(USER_NUMBER,temp);
	memset(extracted_message,0,50);
	memset(extracted_number,0,14);
	return OFF;
}
/*
void reset_module(void)
{
		  			memset(response_temp,0,200);
	        buffer_counter = 0;
	delay(0.1);
		#ifdef DEBUG_START
	debug("RESET");
  #endif
	  gsm_transmit("AT+CFUN=0\r");
	  delay(2);
	  if(!check_response_command())
		{
				  			memset(response_temp,0,200);
	        buffer_counter = 0;
	      gsm_transmit("AT+CFUN=1\r");
			  check_response_command();
			RESET = ON;
		}
			  			memset(response_temp,0,200);
	        buffer_counter = 0;
	  
}
*/
UINT32 strstr_mod(const char *strmain, const char *strsub)
{
	INT8 i=0,l=0,temp=0,match=0,main_len=0,sub_len=0;
	main_len = strlen_mod(strmain);
	sub_len = strlen_mod(strsub);
	for (i=0;i<main_len;i++)
	{
		if(strmain[i] == strsub[0])
		{
			temp = i;
			for (l=0;l<sub_len;l++,i++)
			{
				if (strmain[i] == strsub[l])
				{
					match++;
					continue;
				}
				else
				{
					i=temp;
					break;
				}
			}
			if (match == sub_len)
			{
				return 0;
			}
			else
			{
				match = 0;
				continue;
			}
		}
	}
  return 1;	
}

/********************************End of File*******************************/
