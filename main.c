#include "common.h"
const INT8 * GSM_INIT[]={"AT+CMGF=1\r","AT+CPMS=\"SM\"\r","AT+CMGD=1,4\r"};
const INT8 * GSM_READ_MSG[]={"AT+CMGR=1\r"};
const INT8 * GPS_LOCATION[]={"AT+CGNSINF\r"};
const INT8 * GSM_DELETE_MSG[]={"AT+CMGD=1,4\r"};
const INT8 * GPS_INIT[1] = {"AT+CGPSPWR=1\r"};
const INT8 * USER_NUMBER[1]={"+919915990657"};
const INT8 * SEND_MESSAGE[1] = {"AT+CMGS=\""};
const INT8 * MAP_LINK[1] = {"maps.google.com/maps/place/"};
char extracted_message[50];
char extracted_location[50];
char joined_string[100];
UINT8 ENTER = 0x0D;
UINT8 DATA_SEND = 0x1A;
UINT32 PARK_MODE = 0;
INT8 response_temp[200];
UINT32 REC= OFF;
UINT32 receiving = 0;
UINT32 buffer_counter=0;
UINT32 i=0;




int main(void)
{
		IO0DIR=0X0000FFFC;
		timer_init();
		pll_init();
		uart_init();
#ifdef DEBUG_START
		uart_init_debug();
#endif
		interrupt_init();
		gsm_init();
		gps_init();
		wait_for_message();
}
