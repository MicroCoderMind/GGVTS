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
	extern void gsm_init(void);

/***************************************************************************
*  Funtion Name: gsm_transmit                                              *
*--------------------------------------------------------------------------*
*  Description: This function will transmit input string to GSM module     *
*               via UART0.                                                 *
*--------------------------------------------------------------------------*
*  Input Parameters: string which needs to be transmit.                    *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
	extern void gsm_transmit(const INT8 *);
	
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
*  Funtion Name: delete_message                                            *
*--------------------------------------------------------------------------*
*  Description: This function will send command to delete all messages     *
*               present in selected memory of GSM module.                  *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments: Memory can be module itself or SIM, in this project SIM       *
*            memory is used. Message is always deleted after reading       *
*                                                                          *
***************************************************************************/
	extern void delete_message(UINT32);
	
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
	extern void read_message(UINT32);
#endif
/********************************End of File*******************************/
