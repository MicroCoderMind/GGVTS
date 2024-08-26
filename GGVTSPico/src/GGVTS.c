#include "common.h"

#undef DEBUG_START

char * GSM_INIT[]={"AT\r","AT+CMGF=1\r","AT+CMGD=1,4\r","AT+CPMS=\"SM\"\r"};
char * alpha[] = {"0","1","2","3","4","5","6","7","8","9","10"};
char * GSM_READ_MSG[]={"AT+CMGR="};
char * GPS_LOCATION[]={"AT+CGNSINF\r"};
char * GPS_STATUS[]={"AT+CGPSSTATUS?\r"};
char * GSM_DELETE_MSG[]={"AT+CMGD="};
char * GPS_INIT[1] = {"AT+CGPSPWR=1\r"};
char * OWNER_NUMBER[1]={"+919915990657"};
char USER_NUMBER[14] ={"+919915990657"};
char * SEND_MESSAGE[1] = {"AT+CMGS=\""};
char * MAP_LINK[1] = {"maps.google.com/maps/place/"};
//uint32_t user_info_stored = ON;
int8_t response_temp_diag[50];
uint32_t buffer_counter_diag=0;
char USER_NAME[20];
uint8_t IGNORE = OFF;
uint8_t SEND_LOCATION = OFF;
int8_t extracted_message[50];
int8_t extracted_number[14];
int8_t extracted_location[50];
char joined_string[200];
uint32_t RESET = OFF;
uint8_t ERROR = 0;
uint8_t ENTER = 0x0D;
uint8_t ESCAPE = 0x1B;
uint8_t DATA_SEND = 0x1A;
uint32_t PARK_MODE = 0;
int8_t response_temp[500];
uint32_t REC= OFF;
uint32_t receiving = 0;
uint32_t buffer_counter=0;
uint32_t SYSTEM_STRUCT = 0;
uint32_t Ignore_Char;
uint8_t ATTEMPTS = 0;
uint32_t new_mes=0,comp=1;
volatile uint32_t new_message=0;
uint32_t Received_Message_Count=0;
int8_t LOCATION = OFF;
int8_t TIMER = OFF;
int8_t TIMER0 = OFF;
int8_t TIMER0_OVER = ON;
uint8_t Read_Message_Count = 0;
int32_t message = 0;
int8_t DELETE_MESSAGES = OFF;
uint8_t DIAGNOSE = OFF;
int8_t diagnose_data;
int8_t diagnoseDataSent;
uint8_t CmdSentCount = 0;
int8_t response_temp_debug[500];
uint8_t dataRecieved = false;
const uint LED_PIN = 25;
int8_t Message_Frequency = 0;
struct repeating_timer timer0,timer1;

int main(void)
{
	initModule();
}

void initModule(void)
{
	stdio_init_all();
	gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
	initUart();
	initUartDebug();
	initGSM();
	initGPS();
	if (!ERROR)
	{
		wait_for_message();
	}
}

uint8_t checkResponse(void)
{
	while(1)
	{
        sleep_ms(200);	 
#ifdef DEBUG_START
	sendDataOverDebug(response_temp);
#endif
	    if (!(strstr_mod(response_temp,"OK")))			/* If response from GPS/GSM module contains OK */
	    {
			ERROR = 0;
#ifdef DEBUG_START
	sendDataOverDebug("Command response checked Without Error");
#endif
	      	return ERROR;      /* Return 0 if command sent successfully and OK received from module */
	    }
	    else if(!(strstr_mod(response_temp,"ERROR")))	/* If response from GPS/GSM module contains ERROR */
	    {
			ERROR=1;
#ifdef DEBUG_START
	sendDataOverDebug("Command response checked With Error");
#endif
	      	return ERROR;      /* Return 1 if command was not sent successfully and ERROR received from module */
	    }
		else
		{
#ifdef DEBUG_START
	sendDataOverDebug(response_temp);				/* For debug purpose */
	sendDataOverDebug("\n");
	sendDataOverDebug("No Response\n");
#endif
		}
	}
}

void init(void)
{
	while(1)
	{
		sendDataOverUART("AT\r");
		sleep_ms(1000);
		sendDataOverDebug(response_temp);				/* For debug purpose */
		clear_buffer();
	}
}


void clear_buffer(void)
{
	sendDataOverDebug("Emptying Buffer..");
	dataRecieved = false;
	buffer_counter = 0;
	memset(response_temp,'\0',500);
	sleep_ms(500);
}