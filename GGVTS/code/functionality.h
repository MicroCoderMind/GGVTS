/***************************************************************************
*  File Name: functionality.h                                              *
*--------------------------------------------------------------------------*
*  Description: This file contains all the prototypes of functions used    *
*               for functionality performed on strings.                    *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                             *
*                                                                          *
***************************************************************************/
#ifndef __FUNCTIONALITY__
#define __FUNCTIONALITY__
	
/***************************************************************************
*  Funtion Name: strlen_mod                                                *
*--------------------------------------------------------------------------*
*  Description: This function counts the number of charcters in input      *
*               string excluding NULL character.                           *
*--------------------------------------------------------------------------*
*  Input Parameters: string for which characters to be counted             *
*  Output Parameters: (Unsigned int)Numbers of charaqcters in string       * 
                      excluding NULL character.                            *
*--------------------------------------------------------------------------*
*  Comments: To use this function, input string must have NULL character   *
*            as last character, this fun cion has same functionality as    *
*            strlen library function                                       *
*            for example:                                                  *
*            if str1 = "Hello" then output from thi function will be 5     *
***************************************************************************/
	extern UINT32 strlen_mod(const char * ptr);
	
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
	extern void functionality(void);
	
/***************************************************************************
*  Funtion Name: join_strings                                              *
*--------------------------------------------------------------------------*
*  Description: This function takes two strings as input and store them in *
                global array after joining.                                *
*--------------------------------------------------------------------------*
*  Input Parameters: two strings(str1 and str2)                            *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments: Format will be joined_string = str1 followed by str2          *
*            for example:                                                  *
*            if str1 = "Hello" and str2 = "Rohan" then                     *
*            joined_string will be "Hello Rohan"                           *
***************************************************************************/	
	extern void join_strings(const INT8 *,const INT8 *);
		
#endif
/********************************End of File*******************************/
