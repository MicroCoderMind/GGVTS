/************************************************************************
*     Below are the inclusion of required header files.                 *
************************************************************************/
#include "common.h"
/************************************************************************
*     Below is the initialization of global parameters.                 *                                               *
************************************************************************/
UINT8* commands[]={"AT+CMGF=1\r","AT+CPMS=\"SM\"\r",
"AT+CMGR=1\r","AT+CMGS=9915990657"};  //Array which store all the necessary commands
UINT8 characters[]={12,40};    //Array which have length of message which contains extra information
UINT8 ENTER = 0x0D;            //To send any command
UINT8 MESSAGE_SEND = 0x1A;     //To send message
UINT8 PARK_MODE = 0;           //To detect whether vehicle is in Parking Mode
UINT8 response[50];            //To store necessary response received from GSM
UINT8 response_temp[50];       //To store full response received from GSM
UINT8 OK_FLAG=FALSE;           //Variable used to compare response from GSM
unsigned char x=0;
UINT8 i=0;

/************************************************************************
*     Function Name: Main                                               *
*     Description: This function starts project functionality and       *
*                  call initialization function.                        *
*     Function Return type: Void                                        *
*     Parameters Name and type: N/A(Void)                               *
************************************************************************/
void main()
{
	init();        //Call to initialization function.
	while(1);      //To stop controller from again and again executing code
}
