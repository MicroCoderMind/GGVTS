/***************************************************************************
*  File Name: Strings_Mod_Functionality.h                                              *
*--------------------------------------------------------------------------*
*  Description: This file contains all the prototypes of functions used    *
*               for operations needs to be performed on strings            *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                             *
***************************************************************************/

#ifndef __STRINGS_MOD_FUNCTIONALITY__
#define __STRINGS_MOD_FUNCTIONALITY__

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
	
/***************************************************************************
*  Funtion Name: strcmp_mod                                                *
*--------------------------------------------------------------------------*
*  Description: This function compares twominput strings                   *
*               string excluding NULL character.                           *
*--------------------------------------------------------------------------*
*  Input Parameters: Two strings which needs to be compared                *
*  Output Parameters: return 0 if matched, -1 otherwise                    *
*--------------------------------------------------------------------------*
*  Comments: To use this function, input string must have NULL character   *
*            as last character, this fun cion has same functionality as    *
*            strlen library function                                       *
*            for example:                                                  *
*            if str1 = "Hello" then output from thi function will be 5     *
***************************************************************************/
	extern INT32 strcmp_mod(const char *,const char *);
	
/***************************************************************************
*  Funtion Name: strcpy_mod                                               *
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
 extern void strcpy_mod(char *,char *);
 
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
*  Funtion Name: strstr_mod                                                *
*--------------------------------------------------------------------------*
*  Description: This function checks wether one string exists in another   *
*               string                                                     *
*--------------------------------------------------------------------------*
*  Input Parameters: String 1 which needs to be searched, String 2 where   *
                     string 1 needs to be searched                         *
*  Output Parameters: (Unsigned int)0 if sub string exist in main string   *
*                     and 1 otherwise                                      *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
***************************************************************************/
	extern UINT32 strstr_mod(const char *, const char *);
	
/***************************************************************************
*  Funtion Name: clear_buffer                                              *
*--------------------------------------------------------------------------*
*  Description: This function clears the main buffer "response_temp"       *
*               and it will set buffer_counter to 0                        *
*                                                                          *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
***************************************************************************/
	extern void clear_buffer(void);
	
#endif
