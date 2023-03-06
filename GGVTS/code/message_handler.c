#include "common.h"
#undef DEBUG_START

/***************************************************************************
*  Funtion Name: check_authentication                                      *
*  Function prototype:  void check_authentication(const INT8 *)            *
*  Function return type: void                                              *
*  Function description: This function will check if message receives      *
*                        from USER/OWNER                                   *
***************************************************************************/
void check_authentication(const INT8 * str1)
{
	delay(0.05);
  clear_buffer();        /* Clears the main buffer */
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
	clear_buffer();        /* Clears the main buffer */
}
