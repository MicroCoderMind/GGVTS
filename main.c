#include "common.h"
UINT8* commands[]={"AT+CMGF=1\r","AT+CPMS=\"SM\"\r","AT+CMGR=1\r","AT+CMGS=9915990657"};
UINT8 characters[]={12,40};
UINT8 ENTER = 0x0D;
UINT8 DATA_SEND = 0x1A;
UINT8 PARK_MODE = 0;
UINT8 response[30];
UINT8 response_temp[50];
UINT8 OK_FLAG=FALSE;
unsigned char x=0;
UINT8 i=0;
void main()
{
	init();
	while(1);
}
