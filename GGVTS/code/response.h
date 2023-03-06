/***************************************************************************
*  File Name: response.h                                                   *
*--------------------------------------------------------------------------*
*  Description: This file contains all the declarations for functions and  *
*               global parameters used to response to user.                *
*  Author: Arora Motor Works                                               *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
#ifndef __RESPONSE__
#define __RESPONSE__

/***************************************************************************
*  Below are the global variable(s) used in this file                      *
***************************************************************************/
extern uint8_t ESCAPE;

/***************************************************************************
*  Funtion Name: check_response_command                                    *
*--------------------------------------------------------------------------*
*  Description: This function will check for the response given by GSM/GPS *
*  module after sending commnad.                                           *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: Unsigned Int                                         *
*   1. Returns 0 if every thing is ok.                                     *
*   2. Returns 1 if there is and error.                                    *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern uint32_t check_response_command(void);

/***************************************************************************
*  Funtion Name: check_response_message                                    *
*--------------------------------------------------------------------------*
*  Description: This function will check for the response given by GSM/GPS *
*  module after sending message.                                           *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: Unsigned Int                                         *
*   1. Returns 0 if every thing is ok.                                     *
*   2. Returns 1 if there is and error.                                    *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern uint32_t check_response_message(void);
  
/***************************************************************************
*  Funtion Name: response_back                                             *
*--------------------------------------------------------------------------*
*  Description: This function will interact with owner(Rohan).             *
*--------------------------------------------------------------------------*
*  Input Parameters: String(Message which needs to be sent to user)        *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern void response_back(const int8_t *,const int8_t *);

/***************************************************************************
*  Funtion Name: get_user_info                                             *
*--------------------------------------------------------------------------*
*  Description: This function collects user name and contact number from   *
*               owner(Rohan).                                              *
*--------------------------------------------------------------------------*
*  Input Parameters: two strings(str1 and str2)                            *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern void get_user_info(void);
		
#endif
/********************************End of File*******************************/
