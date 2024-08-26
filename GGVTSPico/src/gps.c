/***************************************************************************
*  File Name: gps.c                                                        *
*--------------------------------------------------------------------------*
*  Description: This file contains definitions of all functions            *
*               which are performing GPS related functionality.            *
*                                                                          *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Below are the header files required to build project                    *
***************************************************************************/
#include "common.h"

/***************************************************************************
*  Below are the global variable(s) used in this file                      *
***************************************************************************/
uint8_t glbColdStartDone = 0;
uint8_t glbWarmStartDone = 0;
uint8_t glbWarmStartVar = 0;
uint8_t glbCheckLocation = 0;
uint8_t glbLocationFixed = 0;
const int8_t * glbWarmStart[1] = {"AT+CGPSRST=2\r"};
const int8_t * glbColdStart[1] = {"AT+CGPSRST=0\r"};

/***************************************************************************
*  Funtion Name: initialize_gps                                            *
*  Function prototype: void initialize_gps(void)                           *
*  Function return type: void                                              *
*  Function description: This function will perform gps initialization by  *
*  sending specfic commands from master device. also it will detect whether*
*  commands are proceeding or not by getting response.                     *
***************************************************************************/
void initGPS(void)
{
	if (!ERROR)
	{
		while(CmdSentCount < 5)
		{
	    	sendDataOverUART(GPS_INIT[0]);
#ifdef DEBUG_START
    sendDataOverDebug(GPS_INIT[0]);
#endif // DEBUG
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
			  	sleep_ms(500);
	    	}
			if (CmdSentCount >= 5)
			{
			  	reset_module(OFF);
				CmdSentCount = 0;
			}
	  	}
	}
	if (ERROR == 0)
	{
		//response_back(USER_NUMBER[0],"GPS Initialized, Collecting Location Info!!! Please Wait...");
	    check_gps_status();
	}
}

/***************************************************************************
*  Funtion Name: check_gps_status                                          *
*  Function prototype: void check_gps_status(void)                         *
*  Function return type: void                                              *
*  Function description: This function will check status of GPS, whether   *
*  it is ready to communicate.                                             *
***************************************************************************/
void check_gps_status(void)
{
    uint32_t i,j,lcStore = 0;
    if(!ERROR)
    {
        while(1)
		{		
			while(CmdSentCount < 5)
		    {
	          	memset(extracted_location,0,50);
		        sendDataOverUART(GPS_STATUS[0]);
#ifdef DEBUG_START
    sendDataOverDebug(GPS_STATUS[0]);
#endif // DEBUG
		        CmdSentCount++;
            if (!checkResponse())
	        {
		        CmdSentCount = 0;
		        break;
	        }
	        else
	        {
		        clear_buffer();       /* Clears the main buffer */
		        sleep_ms(500);
	        }
			if (CmdSentCount >= 5)
		    {
		        reset_module(OFF);
				CmdSentCount = 0;
		    }
			}					
	    	for (j=0,i=0;i<strlen_mod(response_temp);i++)
			{
			  	if (response_temp[i] == ':')
				{
				    lcStore++;
				}
				else if (lcStore>0)
				{
				    if (response_temp[i+1] != 'x')
				    {
				        extracted_location[j++] = response_temp[i+1];
				    }
				    else
				    {
				        extracted_location[j++] = response_temp[i+1];
				        lcStore=0;
				        break;
				    }
				}
				else
				{
				      continue;
				}
			}
			extracted_location[j] = '\0';
#ifdef DEBUG_START
	sendDataOverDebug(extracted_location);					/* For debug purpose */
#endif
			if (strcmp(extracted_location,"Location 3D Fix\0")==0)
			{
			    response_back(USER_NUMBER,"System is Healthy and Working...Location is 3D");
			    memset(extracted_location,0,50);
			    clear_buffer();       /* Clears the main buffer */
				glbCheckLocation = 0;
				glbLocationFixed = 1;
			    break;
			}
			else if(strcmp(extracted_location,"Location 2D Fix\0")==0)
			{
				response_back(USER_NUMBER,"System is Healthy and Working...Location is 2D");
				memset(extracted_location,0,50);
				clear_buffer();       /* Clears the main buffer */
			  	glbCheckLocation = 0;
			    glbLocationFixed = 1;
				break;
			}
			clear_buffer();       /* Clears the main buffer */
			glbCheckLocation++;
			sleep_ms(5000);
			if (glbCheckLocation < 25)
			{
			    continue;
			}
			else
			{
			    glbWarmStartVar++;
			    if (glbWarmStartVar < 2 && glbWarmStartDone == 0)
			    {
			    	//Do Nothing
			    }
			    else if(glbWarmStartDone == 0 || glbWarmStartDone == 1)
			    {
			    	response_back(USER_NUMBER,"Location not fixed, Performing Warm Start!!!");
					while(CmdSentCount < 5)
			    	{
			    		sendDataOverUART(glbWarmStart[0]);
			    		CmdSentCount++;
        				if (!checkResponse())
	    	  			{
	  		    		  	clear_buffer();     /* Clear the main buffer */
			    		    CmdSentCount = 0;
			    		    glbWarmStartDone++;
			    		    break;
	    	  			}
	    	  			else
	    	  			{
			    		    clear_buffer();       /* Clears the main buffer */
			    		    sleep_ms(500);
	    	  			}
			    		if (CmdSentCount >= 5)
			    		{
			    			reset_module(OFF);
			    		    CmdSentCount = 0;
			    		}
					}
					glbCheckLocation = 0;
				}
				else
				{
					glbColdStartDone++;
					if (glbColdStartDone == 3)
					{
					    response_back(USER_NUMBER,"GPS not responding!!! Hard reset required!!!");
					    glbColdStartDone = 0;
					    glbWarmStartDone = 0;
					    glbCheckLocation = 0;
					    glbLocationFixed = 0;
					    break;
					}	
					response_back(USER_NUMBER,"Location not fixed, Performing Cold Start!!!");
					while(CmdSentCount < 5)
					{
					    sendDataOverUART(glbColdStart[0]);
					    CmdSentCount++;
    			    	if (!checkResponse())
				      	{
				  	      	clear_buffer();     /* Clear the main buffer */
					        CmdSentCount = 0;
					        glbWarmStartDone = 0;
					        break;
				      	}
	    	  			else
	    	  			{
			    		    clear_buffer();       /* Clears the main buffer */
			    		    sleep_ms(500);
	    	  			}
			    		if (CmdSentCount >= 5)
			    		{
			    			reset_module(OFF);
			    		    CmdSentCount = 0;
			    		}
					}
					glbCheckLocation = 0;
				}
			}
		}
    }
}

/***************************************************************************
*  Funtion Name: extract_location                                          *
*  Function prototype: void extract_location(void)                         *
*  Function return type: void                                              *
*  Function description: This function will extract location sent by gps   *
*  gps_get_location function.                                              *
***************************************************************************/
void extract_location(void)
{
	uint32_t i,j=0,lcCommas=0;
	for (i=0;i<strlen_mod(response_temp);i++)
	{
		if (response_temp[i] == ',')
		{
			if(lcCommas == 3)
			{
				lcCommas++;
				extracted_location[j++] = ',';
			}
			else
			{
				lcCommas++;
			}
		}
		else if((lcCommas == 3 || lcCommas == 4) && (response_temp[i] != 0x0D || response_temp[i] != 0x0A))
		{
			extracted_location[j++] = response_temp[i];
		}
		else
		{
			continue;
		}
	}
	extracted_location[j] = '\0';
#ifdef DEBUG_START
	sendDataOverDebug(extracted_location);			/* For debug purpose */
#endif
	clear_buffer();       /* Clears the main buffer */
}

/***************************************************************************
*  Funtion Name: get_gps_location                                          *
*  Function prototype: void get_gps_location(void)                         *
*  Function return type: void                                              *
*  Function description: This function will send command to GPS to get     *
*                         current location                                 *
***************************************************************************/
void get_gps_location(void)
{
	if (!ERROR && glbLocationFixed == 1)
	{
		while(CmdSentCount < 5)
		{
		   	sendDataOverUART(GPS_LOCATION[0]);
		   	CmdSentCount++;
       		if (!checkResponse())
	    	{
			    CmdSentCount = 0;
			    extract_location();
			    break;
	    	}
	    	else
	    	{
			    clear_buffer();       /* Clears the main buffer */
			    sleep_ms(500);
	    	}
		}
		if (CmdSentCount >= 5)
		{
		    ERROR++;
		}
	}
	else
	{
		response_back(USER_NUMBER,"GPS not supported currently, Please Perform Hard Reset!!!");
	}
	if (ERROR > 0)
	{
		ERROR = 0;
		reset_module(OFF);
	}
#ifdef DEBUG_START
	sendDataOverDebug(response_temp);				/* For debug purpose */
#endif
	return;
}

/***************************************************************************
*  Funtion Name: send_location                                             *
*  Function prototype: void send_location(void)                            *
*  Function return type: void                                              *
*  Function description: This function will get location from gps function *
*  and extracted location will be send to user.                            *
***************************************************************************/
void send_location(void)
{
	char lcBuffer[200];
	sleep_ms(100);
	get_gps_location();
	join_strings(MAP_LINK[0],extracted_location);
	strcpy_mod(lcBuffer,joined_string);
	sleep_ms(400);
	memset(joined_string,0,200);
	response_back(USER_NUMBER,lcBuffer);
}
/********************************End of File*******************************/
