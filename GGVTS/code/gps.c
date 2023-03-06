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
UINT8 COLD_START_DONE = 0;
UINT8 WARM_START_DONE = 0;
UINT8 WARM_START = 0;
UINT8 check_location = 0;
UINT8 location_fixed = 0;
const INT8 * warm_start[1] = {"AT+CGPSRST=2\r"};
const INT8 * cold_start[1] = {"AT+CGPSRST=0\r"};
/***************************************************************************
*  Funtion Name: gps_init                                                  *
***************************************************************************/
void gps_init(void)
{
	if (!ERROR)
	{
	  gsm_transmit(GPS_INIT[0]);
    if (!check_response_command())
	  {
	  		  buffer_counter = 0;
	  	    memset(response_temp,0,200);
		      ERROR = 0;
	  }
	else
	{
		//response_back(USER_NUMBER,"Initialization Unsuccessfull!! Trying Again...");
				buffer_counter = 0;
	  	  memset(response_temp,0,200);
	}
	if (ERROR == 0)
	{
		//check_gps_status();
	}
}
}

/***************************************************************************
*  Funtion Name: get_gps_location                                          *
***************************************************************************/
void get_gps_location(void)
{
	if (!ERROR && location_fixed == 1)
	{
	  gsm_transmit(GPS_LOCATION[0]);
	  if (!check_response_command())
	  {			
	   	memset(extracted_location,0,50);
		  delay(0.1);
		  extract_location();
	  }
	}
	else if (ERROR != 0)
	{
		ERROR++;
		//response_back(USER_NUMBER,"Initialization Unsuccessfull!! Trying Again...");
		buffer_counter = 0;
	  memset(response_temp,0,200);
	}
	else
	{
		response_back(USER_NUMBER,"GPS not supported currently, Please Perform Hard Reset!!!");
	}
	IO0CLR = 0x00000008;
	#ifdef DEBUG_START
		debug(response_temp);
	#endif
	return;
}

/***************************************************************************
*  Funtion Name: check_gps_status                                          *
***************************************************************************/
void check_gps_status(void)
{
    UINT32 i,j,store = 0;
    if(!ERROR)
    {
        //response_back(USER_NUMBER,"Collecting Location Info!!! Please Wait...");
        while(1)
		    {							
		    	  memset(extracted_location,0,50);
		        gsm_transmit(GPS_STATUS[0]);
		    	  if(check_response_command())
		    	  {
		    		    memset(extracted_location,0,50);
		    		    memset(response_temp,0,200);
	              buffer_counter = 0;
		    		    //response_back(USER_NUMBER,"Initialization Unsuccessfull!! Trying Again...");
		    		    ERROR = 0;
		    		    continue;
		    	  }
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
#endif
		    	  if (strcmp(extracted_location,"Location 3D Fix\0")==0)
		    	  {
		    		    response_back(USER_NUMBER,"System is Healthy and Working...Location is 3D");
		    		    memset(extracted_location,0,50);
		    		    memset(response_temp,0,200);
	              buffer_counter = 0;
						    check_location = 0;
						    location_fixed = 1;
		    		    break;
		    	  }
		    	  else if(strcmp(extracted_location,"Location 2D Fix\0")==0)
		    	  {
		    	  	  response_back(USER_NUMBER,"System is Healthy and Working...Location is 2D");
		    	  	  memset(extracted_location,0,50);
		    	  	  memset(response_temp,0,200);
	              buffer_counter = 0;
					  	  check_location = 0;
					      location_fixed = 1;
		    	  	  break;
		    	  }
		    	  memset(response_temp,0,200);
	          buffer_counter = 0;
					  check_location++;
		    	  delay(5);
					  if (check_location < 25)
					  {
					      continue;
					  }
					  else
					  {
						    WARM_START++;
						    if (WARM_START < 2 && WARM_START_DONE == 0)
						    {
						    	//Do Nothing
						    }
						    else if(WARM_START_DONE == 0 || WARM_START_DONE == 1)
						    {
						    	response_back(USER_NUMBER,"Location not fixed, Performing Warm Start!!!");
						    	gsm_transmit(warm_start[0]);
						    	WARM_START_DONE++;
						    	check_location = 0;
						    }
						    else
						    {
						    	  COLD_START_DONE++;
									  if (COLD_START_DONE == 3)
		                {
		                    response_back(USER_NUMBER,"GPS not responding!!! Hard reset required!!!");
		                    COLD_START_DONE = 0;
		                    WARM_START_DONE = 0;
		                    check_location = 0;
		                    location_fixed = 0;
		                    break;
		                }	
									  response_back(USER_NUMBER,"Location not fixed, Performing Cold Start!!!");
						        gsm_transmit(cold_start[0]);
						    	  WARM_START_DONE = 0;
						    	  check_location = 0;
						    }
					  }
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
		char temp_reply[200];
	  delay(0.1);
		get_gps_location();
	  join_strings(MAP_LINK[0],extracted_location);
	  strcpy_mod(temp_reply,joined_string);
	  delay(0.4);
	  memset(joined_string,0,200);
	  response_back(USER_NUMBER,temp_reply);
}
/********************************End of File*******************************/
