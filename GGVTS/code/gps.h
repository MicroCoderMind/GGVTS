/***************************************************************************
*  File Name: gps.h                                                        *
*--------------------------------------------------------------------------*
*  Description: This file contains all the declarations for functions and  *
*               global parameters used for GPS functionality.              *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                             *
*                                                                          *
***************************************************************************/
#ifndef __GPS__
#define __GPS__
	extern const INT8 * GPS_INIT[1];
	extern const INT8 * GPS_LOCATION[1];
	extern const INT8 * GPS_STATUS[1];
	extern char extracted_location[50];
/***************************************************************************
*  Funtion Name: get_gps_location                                          *
*--------------------------------------------------------------------------*
*  Description: This function will send command to gps module to get       *
*               current location                                           *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
	extern void get_gps_location(void);
/***************************************************************************
*  Funtion Name: gps_init                                                  *
*--------------------------------------------------------------------------*
*  Description: This function will initialize GPS with appropriate         *
*               commands after checking any errors.                        *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
	extern void gps_init(void);
	
/***************************************************************************
*  Funtion Name: extract_location                                          *
*--------------------------------------------------------------------------*
*  Description: This function will extract Longitude and latitude from     *
*               string received from GPS module after sending command to   *
*               get location.                                              *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
	extern void extract_location(void);

/***************************************************************************
*  Funtion Name: check_gps_status                                          *
*--------------------------------------------------------------------------*
*  Description: This function will send command to gps module to check     *
*               location status whether it is 2D fixed, 3D fixed or        *
*               not at all fixed                                           *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
	extern void check_gps_status(void);

#endif
/********************************End of File*******************************/
