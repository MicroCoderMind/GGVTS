/***************************************************************************
*  File Name: functionality.c                                              *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions in which   *
*               different kind of functionalities are performed            *
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
//#define DEBUG_START

/***************************************************************************
*  Funtion Name: functionality                                             *
***************************************************************************/
void functionality(UINT32 message)
{
    UINT32 in_message=0;                                         /* Local variable to determine whether message received is from functionalities GGVTS can perform */
    char temp_reply[200];                                        /* Local buffer to store a string temporary */
#ifdef DEBUG_START                                               /* For debug purpose */
    debug(extracted_message);                                    /* For debug purpose */
#endif                                                           /* For debug purpose */
    if (strcmp_mod(extracted_message,"Bulb on\0") == 0)          /* Check if message os Bulb ON */
    {
        if (IGNORE == OFF)                                       /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            IO0SET = IO0SET | 0x00000010;                        /* Switching ON bulb */
            delay(0.1);                                          /* Delay of 0.1 seconds */
            memset(extracted_message,0,50);                      /* Clearing buffer used to extract message */
            in_message=0;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
        else
        {
            in_message = 1;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"Bulb off\0") == 0)     /* Check if message os Bulb OFF */
    {
        if (IGNORE == OFF)                                       /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            IO0CLR = 0x00000010;                                 /* Switching OFF bulb */
            delay(0.1);                                          /* Delay of 0.1 seconds */
            memset(extracted_message,0,50);                      /* Clearing buffer used to extract message */
            in_message=0;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
        else
        {
            in_message = 1;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"Lctn\0") == 0)         /* Check if message os LCTN */
    {
        if (IGNORE == OFF && location_fixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            send_location();                                     /* Function call to send location */
            delay(0.1);                                          /* Delay of 0.1 seconds */
            in_message=0;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (location_fixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  in_message=0;
				}
        else
        {
            in_message = 1;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"LCTN FREQ 1\0") == 0)  /* Check if message os LCTN FREQ 1*/
    {
        if (IGNORE == OFF && location_fixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            set_location_frequency(1);                           /* Function call to set frequency of location messages as 1 minute */
            delay(0.1);                                          /* Delay of 0.1 seconds */
            in_message=0;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (location_fixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  in_message = 0;
				}
        else
        {
            in_message = 1;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"LCTN FREQ 3\0") == 0)  /* Check if message os LCTN FREQ 3*/
    {
        if (IGNORE == OFF && location_fixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            set_location_frequency(3);                           /* Function call to set frequency of location messages as 3 minute */
            delay(0.1);                                          /* Delay of 0.1 seconds */
            in_message=0;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (location_fixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  in_message = 0;
				}
        else
        {
            in_message = 1;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"LCTN FREQ 5\0") == 0)  /* Check if message os LCTN FREQ 5*/
    {
        if (IGNORE == OFF && location_fixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            set_location_frequency(5);                           /* Function call to set frequency of location messages as 5 minute */
            delay(0.1);                                          /* Delay of 0.1 seconds */
            in_message=0;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (location_fixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  in_message = 0;
				}
        else
        {
            in_message = 1;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"LCTN FREQ 7\0") == 0)  /* Check if message os LCTN FREQ 7 */
    {
        if (IGNORE == OFF && location_fixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            set_location_frequency(7);                           /* Function call to set frequency of location messages as 7 minute */
            delay(0.1);                                          /* Delay of 0.1 seconds */
            in_message=0;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (location_fixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  in_message = 0; 
				}
        else
        {
            in_message = 1;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"LCTN FREQ 10\0") == 0) /* Check if message os LCTN FREQ 10 */
    {
        if (IGNORE == OFF && location_fixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            set_location_frequency(10);                          /* Function call to set frequency of location messages as 10 minute */
            delay(0.1);                                          /* Delay of 0.1 seconds */
            in_message=0;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (location_fixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  in_message = 0;
				}
        else
        {
            in_message = 1;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"LCTN FREQ 0\0") == 0)  /* Check if message os LCTN FREQ 0 */
    {
        if (IGNORE == OFF && location_fixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            SEND_LOCATION = OFF;                                 /* Telling GGVTS to stop sending location */
            T1TCR = 0x02;        //Stop Timer                    /* Turmimg OFF timer which will generate interrupt to send location */
            delay(0.1);                                          /* Delay of 0.1 seconds */
            response_back(USER_NUMBER,"LCTN_FREQ stopped!!!");   /* Informing user that no more loaction messages will be snt by GGVTS */
            in_message=0;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (location_fixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  in_message = 0;
				}
        else
        {
            in_message = 1;                                      /* Telling GGVTS that perform in_message functionality */
        }
				LOCATION = OFF;
    }
    else
    {
        if (IGNORE == OFF)                                       /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            response_back(USER_NUMBER,"Unrecognised Command, Try Again!!!"); /* Informing user that message is unrecognised */
            delay(0.1);                                                      /* Delay of 0.1 seconds */
            memset(extracted_message,0,50);                                  /* Emptying buffer which is used to extract message */
            in_message=0;                                                    /* Telling GGVTS not to perform in_message functionality */
        }
    }
    if (IGNORE == ON && in_message == 1)                         /* If message is not from user and it is one of the functionality GGVTS can perform */
    {
        join_strings("Security Violation Alert!!!","\n");        /* Joining strings */
        join_strings(extracted_number,extracted_message);        /* Joining strings */
        strcpy_mod(temp_reply,joined_string);                    /* Copying joined_message in temporary buffer */
        delay(0.1);                                              /* Delay of 0.1 seconds */
        memset(joined_string,0,200);                             /* Emptying buffer used to join strings */
        response_back(USER_NUMBER,temp_reply);                   /* Infroming user about security violations */
        IGNORE = OFF;                                            /* Making message ignore off for further use */
        delay(0.1);                                              /* Delay of 0.1 seconds */
    }
    else if(IGNORE == ON && in_message == 0)                     /* If message is not from user and it is from the functionalities GGVTS can perform */
    {
        join_strings(extracted_number,extracted_message);        /* Joining strings */
        strcpy_mod(temp_reply,joined_string);                    /* Copying joined_message in temporary buffer */
        delay(0.1);                                              /* Delay of 0.1 seconds */
        memset(joined_string,0,200);                             /* Emptying buffer used to join strings */
        response_back(USER_NUMBER,temp_reply);                   /* Infroming user about new message */
        IGNORE = OFF;                                            /* Making message ignore off for further use */
        delay(0.1);                                              /* Delay of 0.1 seconds */
    }
    memset(temp_reply,0,200);                                    /* Emptying temporary buffer */
    memset(extracted_message,0,50);                              /* Emptying buffer used to extract message */
    memset(extracted_number,0,14);                               /* Emptying buffer used to extract number */
}

/***************************************************************************
*  Funtion Name: wait_for_message                                          *
***************************************************************************/
void wait_for_message()
{
    UINT32 user_info_stored = ON;                                      /* Local variable, used to determine whether user infor is stored or not */
    if (user_info_stored)                                              /* If user infor is not stored, this block will execute */
    {
			  if (new_message > 0)
				{
					response_back(USER_NUMBER,"Initialization in Progress, Please wait!!!");   /* Message to owner for user details */
					gsm_transmit("AT+CMGD=1,4\r");
					new_message = 0;
					Read_Message_Count = 0;
				}
        response_back(USER_NUMBER,"User Name and Number please!!!");   /* Message to owner for user details */
    }
    buffer_counter = 0;                                                /* Making characyer counter for main buffer as 0 */
    memset(response_temp,0,200);                                       /* Emptying main buffer */
    while(ON)                                                          /* Infinite Loop */
    {
        delay(0.1);                                                    /* Delay of 0.1 seconds */
        if (user_info_stored == OFF)                         /* If there is no error and user information is stored successfull, this block will execute */
        {
                delay(0.1);                                            /* delay of 0.1 seconds */
                while(new_message > 0)                                 /* Loop back untill there is no new message */
                {
                    message++;                                         /* Incrementing read message number */
                    delay(0.1);                                        /* delay of 0.1 seconds */
                    buffer_counter = 0;                                /* Making characyer counter for main buffer as 0 */
                    memset(response_temp,0,200);                       /* Emptying main buffer */
                    read_message(message);                         /* Function call to read message */
                    check_authentication(extracted_number);        /* Function call to check authentication of message */
                    functionality(message);                        /* Function call to perform required functionality */
#ifdef DEBUG_START                                                     /* for debug purpose */
    debug(alpha[new_message]);                                         /* for debug purpose */
    debug(alpha[message]); 
		debug(alpha[Received_Message_Count]); 										/* for debug purpose */
#endif                                                                 /* for debug purpose */
                }
                if (SEND_LOCATION == ON)                               /* Check if location has to be sent now due to interrupt */
                {
                    send_location();                                   /* Function call to send location */
                    SEND_LOCATION = OFF;                               /* Stopping processor from sending location continously */
                    T1TCR = 0x01;        //Start Timer
                }
								if (DELETE_MESSAGES == ON)
								{
											gsm_transmit("AT+CMGD=1,4\r");
		                  Read_Message_Count = 0;
		                  Received_Message_Count = 0;
		                  message = 0;
		                  TIMER = OFF;
									    DELETE_MESSAGES = OFF;
								}
#ifdef DEBUG_START                                                     /* for debug purpose */
    debug(alpha[new_message]);                                         /* for debug purpose */
    debug(alpha[message]); 
		debug(alpha[Received_Message_Count]); 										/* for debug purpose */
#endif
						if (Read_Message_Count == Received_Message_Count && TIMER == OFF && Read_Message_Count > 0)
						{							
				        delete_message_timer();
						}
        }
        else if(user_info_stored)                            /* If there is no error and user info is not stored */
        {
                if(new_message > 0)                                 /* Loop until there is no unread message */
                {
                    message++;                                         /* Incrementing number of read messages */
                    delay(0.5);                                        /* Delay of 0.5 seconds */
#ifdef DEBUG_START                                                     /* For debug purpose */
    debug(response_temp);                                              /* For debug purpose */
#endif                                                                 /* For debug purpose */
                    read_message(message);                             /* Function call to read new message */
                    user_info_stored = extract_user_info();            /* Function call to extract user info */                                             /* Exit loop when user info is extracted */
                }
        }
        else
        {
#ifdef DEBUG_START                                                     /* For debug purpose */
    debug(alpha[new_message]);                                         /* For debug purpose */
#endif                                                                 /* For debug purpose */
            continue;                                                  /* Continue if user info is not stored */
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
#ifdef DEBUG_START                           /* For debug purpose */
    debug(USER_NUMBER);                      /* For debug purpose */
    debug(alpha[OFF]);                       /* for debug purpose */
#endif                                       /* For debug purpose */
    join_strings("Greetings!!! Mr. ",USER_NAME);  /* Joining gtrrting message for user */  
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
///*    To be implement in future
//void reset_module(void)
//{
//    memset(response_temp,0,200);     /* Making main buffer empty */
//    buffer_counter = 0;              /* Starting character counter of buffer from 0 */
//    delay(0.1);                      /* delay of 0.1 seconds */
//#ifdef DEBUG_START                   /* For debug purpose */
//    debug("RESET");                  /* For debug purpose */
//#endif                               /* For debug purpose */
//    gsm_transmit("AT+CFUN=0\r");     /* Transmitting command of Airplane mode ON to GGVTS */
//    if(!check_response_command())    /* Checking whether transmission of command happened successfully, if yes this block will execute */
//    {
//        memset(response_temp,0,200); /* Making main buffer empty */
//        buffer_counter = 0;          /* Starting character counter of main buffer from zero */
//        gsm_transmit("AT+CFUN=1\r"); /* Transmitting command of Airplane mode OFF to GGVTS */
//        check_response_command();    /* Checking whether transmission of command happened successfully or not */
//        RESET = ON;                  /* To be implement in future */
//    }
//    memset(response_temp,0,200);     /* Making main buffer empty */
//    buffer_counter = 0;              /* Starting character counter of main buffer from 0 */
//}
//*/

/********************************End of File*******************************/
