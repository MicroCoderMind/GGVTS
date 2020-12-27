#include "common.h"
void get_gps_location(void)
{
		unsigned int k;
		for (k=0;k<strlen_mod(GPS_LOCATION[0]);k++)
		{
				IO0SET = 0x00000008;
				U0THR = GPS_LOCATION[0][k];
				delay(9);
		}
		delay(1);
		IO0CLR = 0x00000008;
	#ifdef DEBUG_START
		debug(response_temp);
	#endif
}

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
void send_location(void)
{
		join_strings(SEND_MESSAGE[0],USER_NUMBER[0]);
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
		memset(extracted_location,0,100);
		memset(extracted_message,0,100);
		memset(response_temp,0,100);
		buffer_counter = 0;
}

void gps_init(void)
{
		unsigned int k;
		for (k=0;k<strlen_mod(GPS_INIT[0]);k++)
		{
				IO0SET = 0x00000008;
				U0THR = GPS_INIT[0][k];
				delay(9);
		}
		delay(1);
		IO0CLR = 0x00000008;
}
