#include "common.h"
#undef DEBUG_START

void check_authentication(const INT8 * str1)
{
	delay(0.05);
	buffer_counter = 0;
	memset(response_temp,0,200);
	if (strcmp(str1,USER_NUMBER))
	{
		IGNORE = ON;
	}
	else
  {
		 #ifdef DEBUG_START
			 debug("Access Granted!!");
	   #endif
		IGNORE = OFF;
	}
	delay(0.1);
	buffer_counter = 0;
	memset(response_temp,0,200);
}
