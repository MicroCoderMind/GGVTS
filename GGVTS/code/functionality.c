/***************************************************************************
*  File Name: functionality.c                                              *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions in which   *
*               different kind of functionalities are performed            *
*               for eg. join strings, counting string length etc.          *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                               *
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
    UINT32 i=strlen_mod(joined_string),j;   /* Getting length of string which is in joined_string buffer */
    for (j=0;j<strlen_mod(str1);j++)        /* For loop */
    {                               
        joined_string[i++] = str1[j];       /* Copying string 1 in joined_string buffer */
    }
    i=strlen_mod(joined_string);            /* Getting length of string which is in joined string_buffer */
    for (j=0;j<strlen_mod(str2);j++)        /* for loop */
    {                                
        joined_string[i++] = str2[j];       /* Copying string 2 in joined_string buffer */
    }
    joined_string[i] = '\0';                /* Adding null charater to end of joined_string buffer */
}

/***************************************************************************
*  Funtion Name: strlen_mod                                                *
***************************************************************************/
UINT32 strlen_mod(const char * ptr)
{
	int i;                          /* Local variable used as index */
	UINT32 characters=0;            /* Local variable used to count number of characters */
	for (i=0;ptr[i]!='\0';i++)      /* For Loop */
	{
		characters++;               /* Incrementing local variable to count charaters in string */
	}
	return characters;              /* Returning number of characters present in string */
}

/***************************************************************************
*  Funtion Name: strcpy_mod                                                *
***************************************************************************/
void strcpy_mod(char * str1,char * str2)
{
	UINT32 i;                        /* Local variable used as counter */
	for (i=0;str2[i]!='\0';i++)      /* For loop */
	{
		str1[i] = str2[i];           /* Copying string 2 in string 1 */
	}
	str1[i] = '\0';                  /* Appending null character in newly copied string i.e. string 1 */               
}
/***************************************************************************
*  Funtion Name: strcmp_mod                                                *
***************************************************************************/
INT32 strcmp_mod(const char * str1, const char * str2)
{
    INT32 i,return_var=0;                       /* Local variable used as index and return value respectively */
    if (strlen_mod(str1) == strlen_mod(str2))   /* Checking if both strings have same length */
    {
        for(i=0; i<strlen_mod(str1); i++)       /* For loop */
        {
            if (str1[i] == str2[i])             /* Checking if both strings contain same character at same index */
            {
                continue;                       /* Continue checking if both strings contain same character */
            }
            else                                /* If character is not same, this part will execute */
            {
                return_var = -1;                /* set return value to -1 if there is mismatch between string q and string 2 */
                break;                          /* Stop checking further */
            }
        }
    }
    else                                        /* This part will execute if both strings are not same in length */
    {
        return_var = -1;                        /* Set return value as -1 if length of both strings is not same */
    }
    return return_var;                          /* Return return value */
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
            {
                message=0;
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
*  Funtion Name: extract_user_info                                         *
***************************************************************************/
UINT32 extract_user_info(void)
{
    UINT32 i,j;                   /* Local variables used as index */
    char temp[200];               /* Local buffer for temporary use */
    for (i=0;extracted_message[i] != ' ';i++)   /* For loop */
    {
        USER_NAME[i]=extracted_message[i];      /* Storing name of user in USER_NAME buffer */
    }
    USER_NAME[i]='\0';                          /* Appending null character in USER_NAME buffer */
#ifdef DEBUG_START                              /* For debug purpose */
    debug(USER_NAME);                           /* For debug purpose */
#endif                                          /* For debug purpose */
    if(extracted_message[i+1]!='+')             /* Checking if number sent by owner contains country code? */
    {
        response_back(USER_NUMBER,"Invalid Format!!! Try again!! Pro Tip: Add Country code!!"); /* If country code is not mentioned user will be informed of that */
        memset(extracted_message,0,50);         /* Clearing buffer which is used to extract message */
        memset(extracted_number,0,14);          /* Clearing buffer which is used to extract user number */
        return ON;                              /* Informing GGVTS that valid user name and number is not received yet */
    }
    else                                        /* If number sent by owner this part will execute */
    {
        for (j=0,i++;j<14;j++)
        {
            USER_NUMBER[j] = extracted_message[i++];  /* Storing extracted number in USER_NUMBER buffer */
        }
    }
#ifdef DEBUG_START                 /* For debug purpose */
    debug(USER_NUMBER);            /* For debug purpose */
    debug(alpha[OFF]);             /* for debug purpose */
#endif                             /* For debug purpose */
    join_strings("Greetings!!!",USER_NAME);  /* Joining gtrrting message for user */  
    strcpy_mod(temp,joined_string);          /* Copying joined_string buffer in temporary buffer */
    memset(joined_string,0,200);             /* Emptying joined_string buffer for further use */
    response_back(USER_NUMBER,temp);         /* Sending greeting message to user */
    memset(extracted_message,0,50);          /* Emptying extracted_message buffer for further use */
    memset(extracted_number,0,14);           /* Emptying extracted number buffer for further use */
    return OFF;                              /* Informing processor that valid user name and number is received */
}

/***************************************************************************
*  Funtion Name: reset_module                                              *
***************************************************************************/
/*    To be implement in future
void reset_module(void)
{
    memset(response_temp,0,200);     /* Making main buffer empty */
    buffer_counter = 0;              /* Starting character counter of buffer from 0 */
    delay(0.1);                      /* delay of 0.1 seconds */
#ifdef DEBUG_START                   /* For debug purpose */
    debug("RESET");                  /* For debug purpose */
#endif                               /* For debug purpose */
    gsm_transmit("AT+CFUN=0\r");     /* Transmitting command of Airplane mode ON to GGVTS */
    if(!check_response_command())    /* Checking whether transmission of command happened successfully, if yes this block will execute */
    {
        memset(response_temp,0,200); /* Making main buffer empty */
        buffer_counter = 0;          /* Starting character counter of main buffer from zero */
        gsm_transmit("AT+CFUN=1\r"); /* Transmitting command of Airplane mode OFF to GGVTS */
        check_response_command();    /* Checking whether transmission of command happened successfully or not */
        RESET = ON;                  /* To be implement in future */
    }
    memset(response_temp,0,200);     /* Making main buffer empty */
    buffer_counter = 0;              /* Starting character counter of main buffer from 0 */
}
*/

/***************************************************************************
*  Funtion Name: strstr_mod                                                *
***************************************************************************/
UINT32 strstr_mod(const char *strmain, const char *strsub)
{
    INT8 i=0,l=0,temp=0,match=0,main_len=0,sub_len=0;  /* Local variables used in further calculations */
    main_len = strlen_mod(strmain);                    /* storing length of main string */
    sub_len = strlen_mod(strsub);                      /* Storing length of sub string */
    for (i=0;i<main_len;i++)                           /* For loop */
    {
        if(strmain[i] == strsub[0])                    /* Checking whether first character of substring is present in main string */
        {
            temp = i;                                  /* If first character is present, storing index of main striing temporarily to use further */
            for (l=0;l<sub_len;l++,i++)                /* For loop */
            {
                if (strmain[i] == strsub[l])           /* Checking whether further characters of sub string are present in main string */
                {
                    match++;                           /* Incrementing count if character of sub string are present in main string */
                    continue;                          /* Continue if characters are present */
                }
                else                                   /* This block will exev=cute if further characters of sub string is not present in main string */
                {
                    i=temp;                            /* Storing back index of main string */
                    break;                             /* Break if further charaters are not oresent in main string */
                }
            }
            if (match == sub_len)                      /* If for loop is executed for length of main string and characters oof sub string are present, this block will execute */
            {
                return 0;                              /* Return 0 if sub string is present in main string */
            }
            else                                       /* If for loop is executed for length of main string and sub string is not present in main string, this block will execute */
            {
                match = 0;                             /* Setting matched character counter to 0 for further calculations */
                continue;                              /* Continue execution */
            }
        }
    }
    return 1;                                          /* Return non zero value if sub string is not present in main string */
}

/********************************End of File*******************************/
