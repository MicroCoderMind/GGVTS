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
#define DEBUG_START
/***************************************************************************
*  Funtion Name: gps_init                                                  *
***************************************************************************/
void gps_init(void)
{
	if (!ERROR)
	{
	  gsm_transmit(GPS_INIT[0]);
	}
	if (!check_response())
	{
	  //Do Nothing
	}
	else
	{
		ERROR++;
		//response_to_owner("Initialization Unsuccessfull!! Trying Again...");
	}
	if (ERROR == 0)
	{
		check_gps_status();
	}
}

/***************************************************************************
*  Funtion Name: get_gps_location                                          *
***************************************************************************/
void get_gps_location(void)
{
		unsigned int k;
		for (k=0;k<strlen_mod(GPS_LOCATION[0]);k++)
		{
				IO0SET = 0x00000008;
				U0THR = GPS_LOCATION[0][k];
				delay(9);
		}
		IO0CLR = 0x00000008;
	#ifdef DEBUG_START
		debug(response_temp);
	#endif
}

/***************************************************************************
*  Funtion Name: check_gps_status                                          *
***************************************************************************/
void check_gps_status(void)
{
	UINT32 i,j,store = 0;
	if(!ERROR)
	{
	  //response_to_owner("Collecting Location Info!!! Please Wait...");
    while(1)
		{				
			memset(response_temp,0,200);
			buffer_counter = 0;
			memset(extracted_location,0,50);
		  gsm_transmit(GPS_STATUS[0]);
			check_response();
	    for (j=0,i=0;i<strlen_mod(response_temp);i++)
		  {
		  	if (response_temp[i] == ':')
				{
					store++;
				}
				else if (store>0)
				{
					if (response_temp[i+1] != 'x')
					{
						extracted_location[j++] = response_temp[i+1];
					}
					else
					{
						extracted_location[j++] = response_temp[i+1];
						store=0;
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
		      debug(extracted_location);
			debug("\n");
	    #endif
			if (strcmp(extracted_location,"Location 3D Fix\0")==0)
			{
				response_to_owner("System is Healthy and Working...Location is 3D");
				break;
			}
			else if(strcmp(extracted_location,"Location 2D Fix\0")==0)
			{
				response_to_owner("System is Healthy and Working...Location is 2D");
				break;
			}
			delay(0.2);
	  }
  }
}

/***************************************************************************
*  Funtion Name: extract_location                                          *
***************************************************************************/
void extract_location(void)
{
		UINT32 i,j=0,commas=0;
		for (i=0;i<strlen_mod(response_temp);i++)
		{
			if (response_temp[i] == ',')
			{
				if(commas == 3)
				{
					commas++;
					extracted_location[j++] = ',';
				}
				else
				{
					commas++;
				}
			}
			else if((commas == 3 || commas == 4) && (response_temp[i] != 0x0D || response_temp[i] != 0x0A))
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
		debug(extracted_location);
	#endif
		memset(response_temp,0,200);
		buffer_counter = 0;
}

/***************************************************************************
*  Funtion Name: send_location                                             *
***************************************************************************/
void send_location(void)
{
		join_strings(SEND_MESSAGE[0],OWNER_NUMBER[0]);
		join_strings("","\"\r");
	#ifdef DEBUG_START
		debug(joined_string);
	#endif
		gsm_transmit(joined_string);
		memset(joined_string,0,100);
		join_strings(MAP_LINK[0],extracted_location);
	#ifdef DEBUG_START
		debug(joined_string);
	#endif
		gsm_transmit(joined_string);
		U0THR = DATA_SEND;
		delay(9);
		memset(joined_string,0,100);
		memset(extracted_location,0,50);
		memset(extracted_message,0,50);
		memset(response_temp,0,200);
		buffer_counter = 0;
}
/********************************End of File*******************************/
