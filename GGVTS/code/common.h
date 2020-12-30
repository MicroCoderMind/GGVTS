/***************************************************************************
*  File Name: common.h                                                     *
*--------------------------------------------------------------------------*
*  Description: This file includes all the required header files.          *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                               *
*                                                                          *
***************************************************************************/
#ifndef __COMMON__
#define __COMMON__
	  #include<LPC214X.h>	    /*This file contains all processor related addresses*/
	  #include<string.h>	    /*This file contains all the string related C library functions*/
	  #include<stdlib.h>	    /*This file contains all the standard C library functions*/
	  #include"datatypes.h"	    /*This file contains all the typedefed data types*/
	  #include"global_data.h"   /*This file contains declaration of all global variables*/
	  #include"uart.h"	    /*This file contains declaration of UART related functions and variables*/
	  #include"timer.h"	    /*This file contains declaration of TIMER related functions and variables*/
	  #include"gsm.h"	    /*This file contains declaration of GSM related functions and variables*/
	  #include"gps.h"	    /*This file contains declaration of GPS related functions and variables*/
	  #include"functionality.h" /*This file contains declaration of various functionality functions and variables*/
	  #include"response.h"	    /*This file contains declaration of functions and variables used to respond to user*/
	  #include"debug.h"	    /*This file contains declaration of functions used to debug the program*/

#endif

/***********************End of File****************************************/
