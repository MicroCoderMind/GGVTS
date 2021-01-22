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
#define DEBUG_START
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
*  Funtion Name: functionality                                             *
***************************************************************************/
void functionality(void)
{
		if (strcmp(extracted_message,"Bulb ON\0") == 0)
		{
			IO0SET = IO0SET | 0x00000010;
			memset(extracted_message,0,20);
		}
		else if(strcmp(extracted_message,"Bulb OFF\0") == 0)
		{
			IO0CLR = 0x00000010;
			memset(extracted_message,0,20);
		}
		else if(strcmp(extracted_message,"LCTN\0") == 0)
		{
			get_gps_location();
			extract_location();
			send_location();
			delete_message();
		}
		else
		{
			response_to_owner("Unrecognised Command, Try Again!!!");
		}
}

/***************************************************************************
*  Funtion Name: wait_for_message                                          *
***************************************************************************/
void wait_for_message(UINT32 user_name_stored)
{
	if (!ERROR && user_name_stored)
	{
		memset(response_temp,0,200);
		buffer_counter = 0;
		REC = OFF;
		while(1)
		{
			if(REC == OFF && strlen_mod(response_temp) != 0 )
			{
			    delay(0.5);
	#ifdef DEBUG_START
			    debug(response_temp);
	#endif
			    read_message();
			    functionality();
			    delete_message();
			}
			else
			{
				continue;
			}
		}
	}
	else if(!ERROR)
	{
		memset(response_temp,0,200);
		buffer_counter = 0;
		REC = OFF;
		while(1)
		{
			if(REC == OFF && strlen_mod(response_temp) != 0 )
			{
			    delay(0.5);
	#ifdef DEBUG_START
			    debug(response_temp);
	#endif
			    read_message();
			    extract_user_name();
			    delete_message();
				  break;
			}
			else
			{
				continue;
			}
		}
	}
	else
  {
		//Do Nothing
	}
}


/***************************************************************************
*  Funtion Name: extract_user_name                                           *
***************************************************************************/
void extract_user_name(void)
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
	    USER_NUMBER[j++] = '+';
	    USER_NUMBER[j++] = '9';
	    USER_NUMBER[j++] = '1';
	}
	for (i++;extracted_message[i]!='\0';j++,i++)
	{
		USER_NUMBER[j] = extracted_message[i];
	}
	USER_NUMBER[j] = '\0';
#ifdef DEBUG_START
	debug(USER_NUMBER);
#endif
	memset(response_temp,0,200);
	buffer_counter = 0;
}

/********************************End of File*******************************/
