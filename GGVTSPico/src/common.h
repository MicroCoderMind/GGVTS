#ifndef __COMMON__
#define __COMMON__

#define DEBUG_START

#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/irq.h"
#include "string.h"
//#include "pico/cyw43_arch.h"
#include "globaldata.h"
#include "uartinit.h"
#include "functionality.h"
#include "response.h"
#include "ledFunctionality.h"
#include "globalConsts.h"
#include "gsm.h"
#include "stringoperations.h"
#include "gps.h"
#include "authenticator.h"
#include "timer.h"

extern void initModule(void);
extern void clear_buffer(void);
extern uint8_t checkResponse(void);

#endif
