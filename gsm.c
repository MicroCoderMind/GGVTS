#include "common.h"
void gsm_init(void)
{
	unsigned int k;
	for (k=0;k<3;k++)
	{
	    gsm_transmit(GSM_INIT[k]);
	}
}

void gsm_transmit(const INT8 * str1)
{
	unsigned int k;
	for (k=0;k<strlen_mod(str1);k++)
	{
	    IO0SET = 0x00000008;
	    U0THR = str1[k];
	    delay(9);
	}
	delay(1);
	IO0CLR = 0x00000008;
}

void extract_message(void)
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
#ifdef DEBUG_START
	debug(extracted_message);
#endif
	memset(response_temp,0,200);
	buffer_counter = 0;
}


void read_message(void)
{
	unsigned int k;
	buffer_counter = 0;
	REC = OFF;
	if (strcmp(response_temp,"\r\n+CMTI: \"SM\",1\r\n")==0)
	{
		memset(response_temp,0,200);
		for (k=0;k<strlen_mod(GSM_READ_MSG[0]);k++)
		{
		    IO0SET = 0x00000008;
		    U0THR = GSM_READ_MSG[0][k];
		    delay(9);
		}
		delay(1);
	  IO0CLR = 0x00000008;
#ifdef DEBUG_START
		debug(response_temp);
#endif
		REC = OFF;
		buffer_counter = 0;
		extract_message();
	}
}

void delete_message(void)
{
		unsigned int k;
		for (k=0;k<strlen_mod(GSM_DELETE_MSG[0]);k++)
		{
		    IO0SET = 0x00000008;
		    U0THR = GSM_DELETE_MSG[0][k];
		    delay(9);
		}
		delay(1);
	  IO0CLR = 0x00000008;
		buffer_counter = 0;
		REC = OFF;
		memset(response_temp,0,200);
}
