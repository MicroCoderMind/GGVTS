/***************************************************************************
*  File Name: message_handler.c				                               *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions used to    *
*				handle a message										   *
*  Author: Arora Motor Works                                               *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Below are the header files required to build project                    *
***************************************************************************/
#include "common.h"

/***************************************************************************
*  Funtion Name: check_authentication                                      *
*  Function prototype:  void check_authentication(const int8_t *)            *
*  Function return type: void                                              *
*  Function description: This function will check if message receives      *
*                        from USER/OWNER                                   *
***************************************************************************/
void check_authentication(const int8_t * str1)
{
	sleep_ms(50);
    clear_buffer();        /* Clears the main buffer */
	if (strcmp_mod(str1,USER_NUMBER))
	{
		IGNORE = ON;
	}
	else
    {
#ifdef DEBUG_START
	sendDataOverDebug("Access Granted!!");					/* For debug purpose */
#endif
		IGNORE = OFF;
	}
	sleep_ms(100);
	clear_buffer();        /* Clears the main buffer */
}
