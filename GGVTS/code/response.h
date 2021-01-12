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
*  Funtion Name: response_to_user                                          *
*--------------------------------------------------------------------------*
*  Description: This function will initialize GSM with appropriate         *
*               commands after checking any errors.                        *
*--------------------------------------------------------------------------*
*  Input Parameters: String(Message which needs to be sent to user)        *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
  extern void response_to_user(const INT8 *);
#endif
/********************************End of File*******************************/
