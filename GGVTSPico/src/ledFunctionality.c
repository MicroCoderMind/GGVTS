#include "common.h"

void turnLEDon(void)
{
	gpio_put(LED_PIN, 1);
}
void turnLEDoff(void)
{
	gpio_put(LED_PIN, 0);
}
void toggleLED(void)
{
	turnLEDon();
	sleep_ms(500);
	turnLEDoff();
	sleep_ms(1000);
}

void blinkLED(void)
{
	turnLEDon();
	sleep_ms(100);
	turnLEDoff();
	sleep_ms(100);
	turnLEDon();
	sleep_ms(100);
	turnLEDoff();
	sleep_ms(100);
	turnLEDon();
	sleep_ms(100);
	turnLEDoff();
}