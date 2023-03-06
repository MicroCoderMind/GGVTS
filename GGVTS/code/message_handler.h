/***************************************************************************
*  File Name: message_handler.h                                            *
*--------------------------------------------------------------------------*
*  Description: This file contains all the declarations for functions and  *
*               global parameters used to handle a message.                *
*  Author: Arora Motor Works                                               *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/

/***************************************************************************
*  Funtion Name: check_authentication                                      *
*--------------------------------------------------------------------------*
*  Description: This function will check if message receives from          *
*               USER/OWNER                                                 *
*--------------------------------------------------------------------------*
*  Input Parameters: String which contains extracted number                 *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern void check_authentication(const int8_t *);
