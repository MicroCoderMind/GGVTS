/***************************************************************************
*  File Name: common.h                                                     *
*--------------------------------------------------------------------------*
*  Description: This file includes all the required header files.          *
*  Author: Arora Motor Works                                               *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/
#ifndef __COMMON__
#define __COMMON__
#undef DEBUG_START
	#include"LPC214X.h"	        		 /* Contains all processor related addresses */
	#include<string.h>	        		 /* Contains all the string related C library functions */
	#include<stdlib.h>	        		 /* Contains all the standard C library functions */
	#include"datatypes.h"	        		 /* Contains all the typedefed data types */
	#include"global_data.h"       		 /* Contains declaration of all global variables */
	#include"uart.h"	            		 /* Contains declaration of UART related functions and variables */
	#include"timer.h"	            		 /* Contains declaration of TIMER related functions and variables */
	#include"gsm.h"	            		 /* Contains declaration of GSM related functions and variables */
	#include"gps.h"	            		 /* Contains declaration of GPS related functions and variables */
	#include"functionality.h"     		 /* Contains declaration of various perform_functionality functions and variables */
	#include"response.h"	        	 	 /* Contains declaration of functions and variables used to respond to user */
	#include"debug.h"	                 	 /* Contains declaration of functions used to debug the program */
	#include"message_handler.h"            /* Contains declaration of functions used to authenticate user information */
    #include"Strings_Mod_functionality.h"  /* Contains declaration of functions used to operate on strings */
#endif

/********************************End of File*******************************/
