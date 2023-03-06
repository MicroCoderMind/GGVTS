/***************************************************************************
*  File Name: Strings_Mod_functionality.c                                  *
*--------------------------------------------------------------------------*
*  Description: This file contains all the function definitions used for   *
*               string related functionality.                              *
*  Author: Arora Motor Works                                               *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                             *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Below are the header files required to build project                    *
***************************************************************************/
#include"common.h"

/***************************************************************************
*  Funtion Name: join_strings                                              *
*  Function prototype:  void join_strings(const int8_t *,const int8_t *)       *
*  Function return type: void                                              *
*  Function description: This function will join two strings.              *
***************************************************************************/
void join_strings(const int8_t * str1,const int8_t *str2)
{
    uint32_t i=strlen_mod(joined_string),j;   /* Getting length of string which is in joined_string buffer */
    for (j=0;j<strlen_mod(str1);j++)        /* For loop */
    {                               
        joined_string[i++] = str1[j];       /* Copying string 1 in joined_string buffer */
    }
    i=strlen_mod(joined_string);            /* Getting length of string which is in joined string_buffer */
    for (j=0;j<strlen_mod(str2);j++)        /* for loop */
    {                                
        joined_string[i++] = str2[j];       /* Copying string 2 in joined_string buffer */
    }
    joined_string[i] = '\0';                /* Adding null charater to end of joined_string buffer */
}

/***************************************************************************
*  Funtion Name: strlen_mod                                                *
*  Function prototype:  uint32_t strlen_mod(const char *)                    *
*  Function return type: uint32_t                                            *
*  Function description: This function will count the length of string     *
***************************************************************************/
uint32_t strlen_mod(const char * ptr)
{
    int i;                          /* Local variable used as index */
    uint32_t characters=0;            /* Local variable used to count number of characters */
    for (i=0;ptr[i]!='\0';i++)      /* For Loop */
    {
        characters++;               /* Incrementing local variable to count charaters in string */
    }
    return characters;              /* Returning number of characters present in string */
}

/***************************************************************************
*  Funtion Name: strcpy_mod                                                *
*  Function prototype:  void strcpy_mod(char * ,char *)                    *
*  Function return type: void                                              *
*  Function description: This function will copy str2 into str1            *
***************************************************************************/
void strcpy_mod(char * str1,char * str2)
{
    uint32_t i;                        /* Local variable used as counter */
    for (i=0;str2[i]!='\0';i++)      /* For loop */
    {
        str1[i] = str2[i];           /* Copying string 2 in string 1 */
    }
    str1[i] = '\0';                  /* Appending null character in newly copied string i.e. string 1 */               
}

/***************************************************************************
*  Funtion Name: strcmp_mod                                                *
*  Function prototype:  int32_t strcmp_mod(void)                             *
*  Function return type: int32_t                                             *
*  Function description: This function will compare two strings            *
***************************************************************************/
int32_t strcmp_mod(const char * str1, const char * str2)
{
    uint32_t i;                                   /* Local variable used as index */
	  int32_t return_var=0;                         /* Local variable used as return value respectively */
    if (strlen_mod(str1) == strlen_mod(str2))   /* Checking if both strings have same length */
    {
        for(i=0; i<strlen_mod(str1); i++)       /* For loop */
        {
            if (str1[i] == str2[i])             /* Checking if both strings contain same character at same index */
            {
                continue;                       /* Continue checking if both strings contain same character */
            }
            else                                /* If character is not same, this part will execute */
            {
                return_var = -1;                /* set return value to -1 if there is mismatch between string q and string 2 */
                break;                          /* Stop checking further */
            }
        }
    }
    else                                        /* This part will execute if both strings are not same in length */
    {
        return_var = -1;                        /* Set return value as -1 if length of both strings is not same */
    }
    return return_var;                          /* Return return value */
}

/***************************************************************************
*  Funtion Name: strstr_mod                                                *
*  Function prototype:  uint32_t strstr_mod(void)                            *
*  Function return type: uint32_t                                            *
*  Function description: This function will check exitance of sub string   *
*                        into main string                                  *
***************************************************************************/
uint32_t strstr_mod(const char *strmain, const char *strsub)
{
    int8_t i=0,l=0,temp=0,match=0,main_len=0,sub_len=0;  /* Local variables used in further calculations */
    main_len = strlen_mod(strmain);                    /* storing length of main string */
    sub_len = strlen_mod(strsub);                      /* Storing length of sub string */
    for (i=0;i<main_len;i++)                           /* For loop */
    {
        if(strmain[i] == strsub[0])                    /* Checking whether first character of substring is present in main string */
        {
            temp = i;                                  /* If first character is present, storing index of main striing temporarily to use further */
            for (l=0;l<sub_len;l++,i++)                /* For loop */
            {
                if (strmain[i] == strsub[l])           /* Checking whether further characters of sub string are present in main string */
                {
                    match++;                           /* Incrementing count if character of sub string are present in main string */
                    continue;                          /* Continue if characters are present */
                }
                else                                   /* This block will exev=cute if further characters of sub string is not present in main string */
                {
                    i=temp;                            /* Storing back index of main string */
                    break;                             /* Break if further charaters are not oresent in main string */
                }
            }
            if (match == sub_len)                      /* If for loop is executed for length of main string and characters oof sub string are present, this block will execute */
            {
                return 0;                              /* Return 0 if sub string is present in main string */
            }
            else                                       /* If for loop is executed for length of main string and sub string is not present in main string, this block will execute */
            {
                match = 0;                             /* Setting matched character counter to 0 for further calculations */
                continue;                              /* Continue execution */
            }
        }
    }
    return 1;                                          /* Return non zero value if sub string is not present in main string */
}

/***************************************************************************
*  Funtion Name: clear_buffer                                              *
*  Function prototype:  void clear_buffer(void)                            *
*  Function return type: void                                              *
*  Function description: This function will clear the main buffer          *
***************************************************************************/
void clear_buffer(void)
{
	buffer_counter = 0;
	memset(response_temp,'\0',200);
	delay(0.5);
}
