/***************************************************************************
*  File Name: perform_functionality.c                                              *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions in which   *
*               different kind of functionalities are performed            *
*               for eg. join strings, counting string length etc.          *
*  Author: Arora Motor Works                                               *
*--------------------------------------------------------------------------*
*  Comments:	                                                             *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Required header files                                                   *
***************************************************************************/
#include"common.h"
#undef DEBUG_START

/***************************************************************************
*  Below are the global variable(s) used in this file                      *
***************************************************************************/
static uint32_t user_info_stored = NO;

/***************************************************************************
*  Funtion Name: perform_functionality                                     *
*  Function prototype:  void perform_functionality(void)                   *
*  Function return type: void                                              *
*  Function description: This function contains all the functionalites     *
*                        which GSM/GPS can perform.                        *
***************************************************************************/
void perform_functionality(void)
{
    uint32_t lcInMessage=0;                                         /* Local variable to determine whether received message is from functionalities GGVTS can perform */
    char temp_reply[200];                                        /* Local buffer to store a string temporary */
#ifdef DEBUG_START                                               /* For sendDataOverDebug purpose */
    sendDataOverDebug(extracted_message);                                    /* For sendDataOverDebug purpose */
#endif                                                           /* For sendDataOverDebug purpose */
    if (strcmp_mod(extracted_message,"Bulb on\0") == 0)          /* Check if message os Bulb ON */
    {
        if (IGNORE == OFF)                                       /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            sleep_ms(100);                                          /* sleep_ms of 0.1 seconds */
            memset(extracted_message,0,50);                      /* Clearing buffer used to extract message */
            lcInMessage=FALSE;                                    /* Telling GGVTS that perform in_message functionality */
            turnLEDon();
        }
        else
        {
            lcInMessage = TRUE;                                   /* Telling GGVTS that dont perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"Bulb off\0") == 0)     /* Check if message os Bulb OFF */
    {
        if (IGNORE == OFF)                                       /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            sleep_ms(100);                                          /* sleep_ms of 0.1 seconds */
            memset(extracted_message,0,50);                      /* Clearing buffer used to extract message */
            lcInMessage=FALSE;                                    /* Telling GGVTS that dont perform in_message functionality */
            turnLEDoff();
        }
        else
        {
            lcInMessage = TRUE;                                   /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"Lctn\0") == 0)         /* Check if message os LCTN */
    {
        if (IGNORE == OFF && glbLocationFixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            send_location();                                     /* Function call to send location */
            sleep_ms(0.1);                                          /* sleep_ms of 0.1 seconds */
            lcInMessage=FALSE;                                    /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (glbLocationFixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  lcInMessage=FALSE;
				}
        else
        {
            lcInMessage = TRUE;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"Lctn freq 1\0") == 0)  /* Check if message os LCTN FREQ 1*/
    {
        if (IGNORE == OFF && glbLocationFixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            Message_Frequency = 1;
            set_location_frequency();                           /* Function call to set frequency of location messages as 1 minute */
            sleep_ms(0.1);                                          /* sleep_ms of 0.1 seconds */
            lcInMessage=FALSE;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (glbLocationFixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  lcInMessage = FALSE;
				}
        else
        {
            lcInMessage = TRUE;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"Lctn freq 3\0") == 0)  /* Check if message os LCTN FREQ 3*/
    {
        if (IGNORE == OFF && glbLocationFixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            Message_Frequency = 3;
            set_location_frequency();                           /* Function call to set frequency of location messages as 3 minute */
            sleep_ms(0.1);                                          /* sleep_ms of 0.1 seconds */
            lcInMessage=FALSE;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (glbLocationFixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  lcInMessage = FALSE;
				}
        else
        {
            lcInMessage = TRUE;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"Lctn freq 5\0") == 0)  /* Check if message os LCTN FREQ 5*/
    {
        if (IGNORE == OFF && glbLocationFixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            Message_Frequency = 5;
            set_location_frequency();                           /* Function call to set frequency of location messages as 5 minute */
            sleep_ms(0.1);                                          /* sleep_ms of 0.1 seconds */
            lcInMessage=FALSE;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (glbLocationFixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  lcInMessage = FALSE;
				}
        else
        {
            lcInMessage = TRUE;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"Lctn freq 7\0") == 0)  /* Check if message os LCTN FREQ 7 */
    {
        if (IGNORE == OFF && glbLocationFixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            Message_Frequency = 7;
            set_location_frequency();                           /* Function call to set frequency of location messages as 7 minute */
            sleep_ms(0.1);                                          /* sleep_ms of 0.1 seconds */
            lcInMessage=FALSE;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
				else if (glbLocationFixed == OFF)
				{
					  response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
					  lcInMessage = FALSE; 
				}
        else
        {
            lcInMessage = TRUE;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"Lctn freq 10\0") == 0) /* Check if message os LCTN FREQ 10 */
    {
        if (IGNORE == OFF && glbLocationFixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            Message_Frequency = 10;
            set_location_frequency();                          /* Function call to set frequency of location messages as 10 minute */
            sleep_ms(0.1);                                          /* sleep_ms of 0.1 seconds */
            lcInMessage=FALSE;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
		else if (glbLocationFixed == OFF)
		{
		    response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
			lcInMessage = FALSE;
		}
        else
        {
            lcInMessage = TRUE;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else if(strcmp_mod(extracted_message,"Lctn freq 0\0") == 0)  /* Check if message os LCTN FREQ 0 */
    {
        if (IGNORE == OFF && glbLocationFixed == ON)               /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            SEND_LOCATION = OFF;                                 /* Telling GGVTS to stop sending location */
            LOCATION = OFF;
            Message_Frequency = 0;
            cancel_repeating_timer(&timer1);        //Stop Timer                    /* Turmimg OFF timer which will generate interrupt to send location */
            sleep_ms(0.1);                                          /* sleep_ms of 0.1 seconds */
            response_back(USER_NUMBER,"LCTN_FREQ stopped!!!");   /* Informing user that no more loaction messages will be snt by GGVTS */
            lcInMessage=FALSE;                                        /* Telling GGVTS that dont perform in_message functionality */
        }
		else if (glbLocationFixed == OFF)
		{
			response_back(USER_NUMBER,"GPS is not functioning right now, Hard Reset Required!!!");  /* Informing user about GPS functionality not working */
			lcInMessage = FALSE;
		}
        else
        {
            lcInMessage = TRUE;                                      /* Telling GGVTS that perform in_message functionality */
        }
    }
    else
    {
        if (IGNORE == OFF)                                       /* Check if this message needds to be ignored?, Means it is received from other than user */
        {
            response_back(USER_NUMBER,"Unrecognised Command, Try Again!!!"); /* Informing user that message is unrecognised */
            sleep_ms(0.1);                                                      /* sleep_ms of 0.1 seconds */
            memset(extracted_message,0,50);                                  /* Emptying buffer which is used to extract message */
            lcInMessage=FALSE;                                                    /* Telling GGVTS not to perform in_message functionality */
        }
    }
    if (IGNORE == ON && lcInMessage == TRUE)                      /* If message is not from user and it is one of the functionality GGVTS can perform */
    {
        join_strings("Security Violation Alert!!!","\n");        /* Joining strings */
        join_strings(extracted_number,extracted_message);        /* Joining strings */
        strcpy_mod(temp_reply,joined_string);                    /* Copying joined_message in temporary buffer */
        sleep_ms(0.1);                                              /* sleep_ms of 0.1 seconds */
        memset(joined_string,0,200);                             /* Emptying buffer used to join strings */
        response_back(USER_NUMBER,temp_reply);                   /* Infroming user about security violations */
        IGNORE = OFF;                                            /* Making message ignore off for further use */
        sleep_ms(0.1);                                              /* sleep_ms of 0.1 seconds */
    }
    else if(IGNORE == ON && lcInMessage == FALSE)                 /* If message is not from user and it is from the functionalities GGVTS can perform */
    {
        join_strings(extracted_number,extracted_message);        /* Joining strings */
        strcpy_mod(temp_reply,joined_string);                    /* Copying joined_message in temporary buffer */
        sleep_ms(0.1);                                              /* sleep_ms of 0.1 seconds */
        memset(joined_string,0,200);                             /* Emptying buffer used to join strings */
        response_back(USER_NUMBER,temp_reply);                   /* Infroming user about new message */
        IGNORE = OFF;                                            /* Making message ignore off for further use */
        sleep_ms(0.1);                                              /* sleep_ms of 0.1 seconds */
    }
    memset(temp_reply,0,200);                                    /* Emptying temporary buffer */
    memset(extracted_message,0,50);                              /* Emptying buffer used to extract message */
    memset(extracted_number,0,14);                               /* Emptying buffer used to extract number */
}

/***************************************************************************
*  Funtion Name: wait_for_message                                          *
*  Function prototype:  void wait_for_message(void)                        *
*  Function return type: void                                              *
*  Function description: This is the function where processor waits for    *
*                        new message.                                      *
***************************************************************************/
void wait_for_message()
{
    uint32_t lcMessage = OFF;                                      /* Local variable, used to determine current reading message */
    if (user_info_stored == NO)                                              /* If user info is not stored, this block will execute */
    {
		if (new_message > 0)                                   /* Check if there is any new message in buffer */
		{
            response_back(USER_NUMBER,"Initialization in Progress, Please wait!!!");   /* Message to owner for initialization progress */
            while(CmdSentCount < 5)                            /* While there is less than 5 errors for sending any message/command */
            {
                sendDataOverUART("AT+CMGD=1,4\r");                 /* Delete all the messages in buffer */
                CmdSentCount++;                                /* Increment command sent counter to identify any error*/
                if (!checkResponse())                 /* If there is no error while sending any command */
                {
                    clear_buffer();     /* Clear the main buffer */
                    CmdSentCount = 0;   /* Clear the command sent counter */
                    break;              /* Break from the loop */
                }
                else                                           /* If there is any error while sending command */
                {
                    clear_buffer();       /* Clears the main buffer */
                    sleep_ms(0.5);           /* Wait for 500ms */
                }
                if (CmdSentCount >= 5)  /* If there was errors more than 5 times while sending any command */
                {
                    reset_module(OFF);  /* Initiate soft reset for GGVTS */
                    CmdSentCount = 0;   /* Clearing command sent buffer */
                }
            }
            new_message = 0;            /* Clearing new message counter */
            Read_Message_Count = 0;     /* Clearing read message counter */
            Received_Message_Count = 0;
		}
        get_user_info();   /* Message to owner for user details */
    }
    clear_buffer();                                                    /* Clear the main buffer */
    while(ON)                                                          /* Infinite Loop */
    {
        sleep_ms(0.1);
        if (user_info_stored == YES && DIAGNOSE == OFF)                /* If there is no error and user information is stored successfull, this block will execute */
        {
            sleep_ms(0.1);                                            /* sleep_ms of 0.1 seconds */
            while(new_message > 0)                                 /* Loop back untill there is no new message */
            {
                lcMessage++;                                         /* Message number being read */
                sleep_ms(0.1);
                clear_buffer();                                    /* Clear the main buffer */
                read_message(lcMessage);
                check_authentication(extracted_number);
                perform_functionality();                           /* Function call to perform required functionality */
#ifdef DEBUG_START
    sendDataOverDebug(alpha[new_message]);                                         /* for sendDataOverDebug purpose */
    sendDataOverDebug(alpha[lcMessage]); 
	sendDataOverDebug(alpha[Received_Message_Count]);
#endif
            }
            if (SEND_LOCATION == ON)                               /* If location has to be sent now due to interrupt */
            {
                send_location();                                   /* Function call to send location */
                SEND_LOCATION = OFF;                               /* Stopping processor from sending location continously */           /* Start Timer */
                add_repeating_timer_ms(Message_Frequency * 1000 * 60, timer1_isr, NULL, &timer1);
            }
			if (DELETE_MESSAGES == ON)
			{	
#ifdef DEBUG_START
    sendDataOverDebug("Entered in Delete Message");
#endif
                cancel_repeating_timer(&timer0);        //Stop Timer
		        while(CmdSentCount < 5)
		        {
	                sendDataOverUART("AT+CMGD=1,4\r");
		            CmdSentCount++;
                    if (!checkResponse())
	                {
	                    clear_buffer();     /* Clear the main buffer */
		              	CmdSentCount = 0;
		                break;
	                }
	                else
	                {
		                clear_buffer();       /* Clears the main buffer */
		              	sleep_ms(0.5);
	                }
					if (CmdSentCount >= 5)
		            {
		                reset_module(OFF);
						CmdSentCount = 0;
		            }
		        }
		        Read_Message_Count = 0;
		        Received_Message_Count = 0;
		        lcMessage = 0;
		        TIMER0 = OFF;
                DELETE_MESSAGES = OFF;
            }
#ifdef DEBUG_START
    sendDataOverDebug(alpha[new_message]);                                         /* for sendDataOverDebug purpose */
    sendDataOverDebug(alpha[Received_Message_Count]); 										/* for sendDataOverDebug purpose */
    sendDataOverDebug(alpha[Read_Message_Count]);
    sendDataOverDebug(alpha[TIMER0]);
    sendDataOverDebug("End Here");
#endif
            if (Read_Message_Count == Received_Message_Count && TIMER0 == OFF && Read_Message_Count > 0)
            {							
		        delete_message_timer();
		    }
        }
        else if(user_info_stored == NO && DIAGNOSE == OFF)                            /* If there is no error and user info is not stored */
        {
            if(new_message > 0)                                 /* Loop until there is no unread message */
            {
                lcMessage++;                                         /* Message number currently being read */
                sleep_ms(0.5);
#ifdef DEBUG_START
    sendDataOverDebug(response_temp);
#endif
                read_message(lcMessage);                             /* Read new message */
                user_info_stored = extract_user_info();            /* Extract user info */ 									
                delete_message_timer();
            }
/* Below block of code is to delete all the messages */
            if (DELETE_MESSAGES == ON)
			{
			    while(CmdSentCount < 5)
	            {
                    sendDataOverUART("AT+CMGD=1,4\r");
                    CmdSentCount++;
                    if (!checkResponse())
                    {
                        clear_buffer();     /* Clear the main buffer */
                        CmdSentCount = 0;
                        break;
                    }
                    else
                    {
                        clear_buffer();       /* Clears the main buffer */
                        sleep_ms(0.5);
                    }
                    if (CmdSentCount >= 5)
                    {
                        reset_module(OFF);
                        CmdSentCount = 0;
                    }
		        }
		        Read_Message_Count = 0;
		        Received_Message_Count = 0;
		        lcMessage = OFF;
		        TIMER0 = OFF;
				DELETE_MESSAGES = OFF;
			}
        }
		else if(DIAGNOSE == ON)             /* If diagnose mode is requested by owner */
		{
		    if (lcMessage == OFF)             /* If no message is being read and to confirm this block is executed once */
		    {
		        sendDataOverDebug("Diagnose mode entered!!!\n");    /* Message to owner that diagnose mode is started */
		        lcMessage = ON;
		        clear_buffer();             /* Clear the main buffer */
		    }
		    else
		    {
		        if (diagnoseDataSent == OFF)    /* If diagnose data is being sent for first time */
		        {
		            uart_putc(UART1_ID,diagnose_data);      /* Pass diagnostic commands to GSM/GPS board */
	                sleep_ms(100);
		        	if (diagnose_data == 0x0D)
		        	{
		        		sleep_ms(1);
		        		sendDataOverDebug(response_temp);
		        		clear_buffer();     /* Clear the main buffer */
		    		}									
		        	diagnoseDataSent = ON;      /* To stop sending same data again and again in diagnose mode */
		        }
		        else
		        {
		        	//Do Nothing
		        }
		    }
		}
		else if(DIAGNOSE == NA)                 /* To exit diagnose mode */
		{
		    if (lcMessage == ON)
		    {
		        sendDataOverDebug("Diagnose mode exit!!!\n");
		        lcMessage = OFF;
		    	DIAGNOSE = OFF;
		    	clear_buffer();     /* Clear the main buffer */
		    }
		}
        else
        {
#ifdef DEBUG_START
    sendDataOverDebug(alpha[new_message]);                                         /* For sendDataOverDebug purpose */
#endif
            continue;                                                  /* Continue if user info is not stored */
        }
    }
}

/***************************************************************************
*  Funtion Name: extract_user_info                                         *
*  Function prototype:  uint32_t extract_user_info(void)                     *
*  Function return type: uint32_t                                            *
*  Function description: This function will extract user info              *
***************************************************************************/
uint32_t extract_user_info(void)
{
#ifdef DEBUG_START                              /* For sendDataOverDebug purpose */
    sendDataOverDebug(extracted_message);
#endif
    uint32_t i,j,lcStringLength;                   /* Local variables used as index */
    char temp[200];               /* Local buffer for temporary use */
	lcStringLength = strlen_mod(extracted_message);
	memset(USER_NUMBER,'\0',14);
	if (lcStringLength > 13 && !(strstr_mod(extracted_message," ")))
	{
        for (i=0;i<lcStringLength ;i++)   /* For loop */
        {
	    	if (extracted_message[i] == ' ')
	    	{
	    		break;
	    	}
	    	else
	    	{
                USER_NAME[i]=extracted_message[i];      /* Storing name of user in USER_NAME buffer */
	    	}
        }
        USER_NAME[i]='\0';                          /* Appending null character in USER_NAME buffer */
#ifdef DEBUG_START
    sendDataOverDebug(USER_NAME);                               /* For sendDataOverDebug purpose */
#endif
		for (j=0,i++;(lcStringLength-i) > 0;j++)
        {
            USER_NUMBER[j] = extracted_message[i++];  /* Storing extracted number in USER_NUMBER */
        }
#ifdef DEBUG_START
    sendDataOverDebug(USER_NUMBER);                      /* For sendDataOverDebug purpose */
#endif  
		if(USER_NUMBER[0]!='+')             /* Checking if number sent by owner contains country code? */
        {
            response_back(OWNER_NUMBER[0],"Invalid Format!!! Try again!! Pro Tip: Add Country code!!"); /* If country code is not mentioned user will be informed of that */
            memset(extracted_message,0,50);         /* Clearing buffer which is used to extract message */
            memset(extracted_number,0,14);          /* Clearing buffer which is used to extract user number */
            return NO;                              /* Informing GGVTS that valid user name and number is not received yet */
        }
		if (strlen_mod(USER_NUMBER) != 13)
		{
			response_back(OWNER_NUMBER[0],"Invalid Number!!! Try again!! Pro Tip: Check Phone Number!!"); /* If country code is not mentioned user will be informed of that */
            memset(extracted_message,0,50);         /* Clearing buffer which is used to extract message */
            memset(extracted_number,0,14);          /* Clearing buffer which is used to extract user number */
			return NO;
		}
        join_strings("Greetings!!! Mr. ",USER_NAME);  /* Joining greeting message for user */  
        strcpy_mod(temp,joined_string);               /* Copying joined_string buffer in temporary buffer */
        memset(joined_string,0,200);                  /* Emptying joined_string buffer for further use */
        response_back(USER_NUMBER,temp);              /* Sending greeting message to user */
        memset(extracted_message,0,50);               /* Emptying extracted_message buffer for further use */
        memset(extracted_number,0,14);                /* Emptying extracted number buffer for further use */
        return YES;		/* Informing processor that valid user name and number is received */
	}
	else
    {
		response_back(OWNER_NUMBER[0],"Invalid Name/Number, Try Again!!!"); /* If there is format issue, user will be informed of that */
        memset(extracted_message,0,50);         /* Clearing buffer which is used to extract message */
        memset(extracted_number,0,14);          /* Clearing buffer which is used to extract user number */
        return NO;				/* Informing processor that valid user name and number is not received */
	}
}

/***************************************************************************
*  Funtion Name: reset_module                                              *
*  Function prototype:  void reset_module(UINT8_T)                           *
*  Function return type: void                                              *
*  Function description: This function will reset module if some error     *
*                        occurs in sending command or message              *
***************************************************************************/
void reset_module(uint8_t bypass_attempts)
{
	uint8_t lcCmdSentCount = 0;
    clear_buffer();                  /* Clears the main buffer */
    sleep_ms(0.1);                      /* sleep_ms of 0.1 seconds */
#ifdef DEBUG_START
	sendDataOverDebug("Attempts: ");             /* For sendDataOverDebug purpose */
	sendDataOverDebug(alpha[ATTEMPTS]);
	sendDataOverDebug("\n");
#endif
	if  (ATTEMPTS > 1 || bypass_attempts == ON)
	{
		if (ATTEMPTS > 2)
		{
			sendDataOverUART("AT+CFUN=0\r");     /* Transmitting command of Airplane mode ON to GGVTS */
			sleep_ms(10000);
 	        sendDataOverUART("AT+CFUN=1\r"); /* Transmitting command of Airplane mode OFF to GGVTS */
			sleep_ms(10000);
			sendDataOverUART("AT+CPOWD=1\r");        /* Transmitting command of Switch OFF to GSM/GPS module */
			ATTEMPTS = 0;
		    ERROR = 0;
			while(1);                            /* Wait here until manual reset is not done */
	    }
	    while (lcCmdSentCount < 5)
        {
            sendDataOverUART("AT+CFUN=0\r");     /* Transmitting command of Airplane mode ON to GGVTS */
	        lcCmdSentCount++;
            if(!checkResponse())    /* Checking whether transmission of command happened successfully, if yes this block will execute */
            {
                clear_buffer();              /* Clears the main buffer */
		  	    lcCmdSentCount = 0;
		  	    sleep_ms(5);                    /* sleep_ms of 5 Seconds */
				break;                       /* Exit from loop as command is already sent successfully */
            }
		}
		while (lcCmdSentCount < 5)
		{
            sendDataOverUART("AT+CFUN=1\r"); /* Transmitting command of Airplane mode OFF to GGVTS */
	        lcCmdSentCount++;
            if(!checkResponse())    /* Checking whether transmission of command happened successfully, if yes this block will execute */
            {
                clear_buffer();              /* Clears the main buffer */
		      	lcCmdSentCount = 0;
		      	sleep_ms(5);                    /* sleep_ms of 5 Seconds */
		    	ATTEMPTS++;
		    	initGSM();                  /* Initialize GSM again after module reset */
 	            initGPS();                  /* Initialize GPS again after module reset */
		    	ERROR = 0;
		    	if (user_info_stored == YES)
		    	{
		    		response_back(USER_NUMBER,"Module Reset Complete!!!!!");
		    	}
		    	else
		    	{
		    	    response_back(OWNER_NUMBER[0],"Module Reset Complete!!!!!");
		    	}
		    	break;                       /* Exit from loop as command is already sent successfully */
            }
		}
	}
	else
	{
		ATTEMPTS++;
		ERROR = 0;
		initGSM();                  /* Initialize GSM again after module reset */
 	    initGPS();                  /* Initialize GPS again after module reset */
	}
    clear_buffer();                  /* Clears the main buffer */
    sleep_ms(1);                        /* Wait for 1 second(s) */
}

/********************************End of File*******************************/
