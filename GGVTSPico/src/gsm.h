/***************************************************************************
*  File Name: gsm.h                                                        *
*--------------------------------------------------------------------------*
*  Description: This file contains all the declarations for functions and  *
*               global parameters used for GSM functionality.              *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/
#ifndef __GSM__
#define __GSM__

/***************************************************************************
*  Funtion Name: gsm_init                                                  *
*--------------------------------------------------------------------------*
*  Description: This function will initialize GSM with appropriate         *
*               commands after checking any errors.                        *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern void initGSM(void);
	
/***************************************************************************
*  Funtion Name: extract_message                                           *
*--------------------------------------------------------------------------*
*  Description: This function will extract the exact message sent by user. *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern void extract_message(void);
	
/***************************************************************************
*  Funtion Name: read_message                                              *
*--------------------------------------------------------------------------*
*  Description: This function will send command to read message whenever   *
*               a new message is received by GSM module.                   *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern void read_message(uint32_t);

extern void delete_message(void);

#endif
/********************************End of File*******************************/
