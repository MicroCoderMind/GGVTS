/************************************************************************
*     Below are the inclusion of required header files.                 *                                        *
************************************************************************/
#include "common.h"
/************************************************************************                                           *
*     Description: This function will compare the response              *
*                  from GSM Module.                                     *
************************************************************************/
extern void compare(void)
{
	#ifdef __DEBUG__       //This block is for debug purpose
    P1=response[1];
  #else
	  OK_FLAG = FALSE;        //Initialization of variable used to check response from GSM
	  response[0]=response_temp[characters[i]];      //For Debug Purpose
	  response[1]=response_temp[characters[i]+1];    //For Debug Purpose
	  OK_FLAG = TRUE;                                //To move to response for next command

	  if (response[0]=='O' && response[1] == 'K')
	  {
		  OK_FLAG = TRUE;       //Setting flag because response was as expected
	  }
	  else
	  {
		  OK_FLAG = FALSE;      //Not setting flag because ressponse was not as unexpected
	  }
		if (OK_FLAG==TRUE)      //Lighting green LED if response was OK
		{
			green = TRUE;
		  red = FALSE;
		}
		else                    //Lighting red LED if response is not OK
		{
			red = TRUE;
			green = FALSE;
		}
  #endif
}