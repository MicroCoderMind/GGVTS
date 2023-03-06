/***************************************************************************
*  File Name: functionality.h                                              *
*--------------------------------------------------------------------------*
*  Description: This file contains all the prototypes of functions used    *
*               for functionality performed on strings.                    *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                             *
***************************************************************************/

#ifndef __FUNCTIONALITY__
#define __FUNCTIONALITY__

/***************************************************************************
*  Funtion Name: reset_module                                              *
*--------------------------------------------------------------------------*
*  Description: This function is written to reset GSM/GPS module.          *
*               In this function Airplane mode will be switched on         *
* 							and then switched off                                      *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
***************************************************************************/
void reset_module(UINT8);
	
/***************************************************************************
*  Funtion Name: wait_for_message                                          *
*--------------------------------------------------------------------------*
*  Description: In this function processor will wait until user sends      *
*               some input.                                                *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
***************************************************************************/
	extern void wait_for_message(void);
	
/***************************************************************************
*  Funtion Name: functionality                                             *
*--------------------------------------------------------------------------*
*  Description: This function definition contains the main functionality   *
*               related to user input. Functionality inside end user's     *
*               message will be performed here.                            *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments: As of now this function contains only 3 functionalities which *
*            are below:                                                    *
*            1. Engine ON(To be done in future, currently LED is used)     *
*            2. Engine OFF(To be done in future, currently LED is used)    *
*            3. LCTN(After receiving this input, current location will be  *
*               extracted and sent to user via sms after converting        *
*               it to a web link)                                          *
***************************************************************************/
	extern void functionality(UINT32);

/***************************************************************************
*  Funtion Name: extract_user_name                                         *
*--------------------------------------------------------------------------*
*  Description: This function will extract user name and number            *
*--------------------------------------------------------------------------*
*  Input Parameters: two strings(str1 and str2)                            *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
***************************************************************************/	
  UINT32 extract_user_info(void);
#endif
/********************************End of File*******************************/
