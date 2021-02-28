/***************************************************************************
*  File Name: response.h                                                   *
*--------------------------------------------------------------------------*
*  Description: This file contains all the declarations for functions and  *
*               global parameters used to response to user.                *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
#ifndef __RESPONSE__
#define __RESPONSE__

/***************************************************************************
*  Funtion Name: check_response                                            *
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
  extern UINT32 check_response(void);
  
/***************************************************************************
*  Funtion Name: response_back                                         *
*--------------------------------------------------------------------------*
*  Description: This function will interact with owner(Rohan).             *
*--------------------------------------------------------------------------*
*  Input Parameters: String(Message which needs to be sent to user)        *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
  extern void response_back(const INT8 *,const INT8 *);
	
	  
/***************************************************************************
*  Funtion Name: response_to_user                                          *
*--------------------------------------------------------------------------*
*  Description: This function will interact with user provided by owner    *
*--------------------------------------------------------------------------*
*  Input Parameters: String(Message which needs to be sent to user)        *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
  extern void response_to_user(const INT8 *);
	
		
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
	void get_user_info(void);
		
#endif
/********************************End of File*******************************/
