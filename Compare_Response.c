#include "common.h"
extern void compare(void)
{
	OK_FLAG = FALSE;
	response[0]=response_temp[characters[i]];
	response[1]=response_temp[characters[i]+1];
	OK_FLAG = TRUE;
//  P1=response[1];
	if (response[0]=='O' && response[1] == 'K')
	{
		OK_FLAG = TRUE;
	}
	else
	{
		OK_FLAG = FALSE;
	}
		if (OK_FLAG==TRUE)
		{
			green = TRUE;
		  red = FALSE;
		}
		else
		{
			red = TRUE;
			green = FALSE;
		}
}