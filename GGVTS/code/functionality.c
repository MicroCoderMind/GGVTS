/***************************************************************************
*  File Name: functionality.c                                              *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions in which   *
*               different kind og functionalities are performed            *
*               for eg. join strings, counting string length etc.          *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                               *
*                                                                          *
/**************************************************************************/

/***************************************************************************
*  Below are the header files required to build project                    *
***************************************************************************/
#include"common.h"

/***************************************************************************
*  Funtion Name: join_strings                                              *
*--------------------------------------------------------------------------*
*  Description: This function takes two strings as input and store them in *
                global array after joining.                                *
*--------------------------------------------------------------------------*
*  Input Parameters: two strings(str1 and str2)                            *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:	 Format will be joined_string = str1 followed by str2          *
*            for example:                                                  *
*            if str1 = "Hello" and str2 = "Rohan" then                     *
*            joined_string will be "Hello Rohan"                           *
/**************************************************************************/
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
*--------------------------------------------------------------------------*
*  Description: This function counts the number of charcters in input      *
*               string excluding NULL character.                           *
*--------------------------------------------------------------------------*
*  Input Parameters: string for which characters to be counted             *
*  Output Parameters: (Unsigned int)Numbers of charaqcters in string       * 
                      excluding NULL character.                            *
*--------------------------------------------------------------------------*
*  Comments:	 To use this function, input string must have NULL character   *
*            as last character, this fun cion has same functionality as    *
*            strlen library function                                       *
*            for example:                                                  *
*            if str1 = "Hello" then output from thi function will be 5     *
/**************************************************************************/
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
*--------------------------------------------------------------------------*
*  Description: This function definition contains the main functionality   *
*               related to user input. Functionality inside end user's     *
*               message will be performed here.                            *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:	 As of now this function contains only 3 functionalities which *
*            are below:                                                    *
*            1. Engine ON(To be done in future, currently LED is used)     *
*            2. Engine OFF(To be done in future, currently LED is used)    *
*            3. LCTN(After receiving this input, current location will be  *
*               extracted and sent to user via sms after converting        *
*               it to a web link)                                          *
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
}

/***************************************************************************
*  Funtion Name: wait_for_message                                          *
*--------------------------------------------------------------------------*
*  Description: In this function processor will wait until user sends      *
*               some input.                                                *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
***************************************************************************/
void wait_for_message(void)
{
	if (!ERROR)
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
}
/********************************End of File***************************/
