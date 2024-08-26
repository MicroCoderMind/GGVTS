/***************************************************************************
*  File Name: gps.h                                                        *
*--------------------------------------------------------------------------*
*  Description: This file contains all the declarations for functions and  *
*               global parameters used for GPS functionality.              *
*                                                                          *
*--------------------------------------------------------------------------*
*  Comments:	                                                           *
*                                                                          *
***************************************************************************/
#ifndef __GPS__
#define __GPS__

/***************************************************************************
*  Below are the global variable(s) used in this file                      *
***************************************************************************/
extern char * GPS_INIT[1];
extern char * GPS_LOCATION[1];
extern char * GPS_STATUS[1];
extern int8_t extracted_location[50];
extern uint8_t glbColdStartDone;
extern uint8_t glbWarmStartDone;
extern uint8_t glbWarmStartVar;
extern uint8_t glbCheckLocation;
extern uint8_t glbLocationFixed;

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
*  Funtion Name: send_location                                             *
*--------------------------------------------------------------------------*
*  Description: This function will send the extracted current location     *
*               to USER/OWNER                                              *
*--------------------------------------------------------------------------*
*  Input Parameters: None                                                  *
*  Output Parameters: None                                                 *
*--------------------------------------------------------------------------*
*  Comments:                                                               *
*                                                                          *
***************************************************************************/
extern void send_location(void);

/***************************************************************************
*  Funtion Name: initialize_gps                                            *
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
extern void initGPS(void);
	
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
