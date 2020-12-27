#include "common.h"
extern void gsm_ready(void)
{
	for (i=0;i<2;i++)
	{
      send(strlen(commands[i]),i);
			delay();
  delay();
  delay();
  delay();
  delay();
  delay();
  delay();
		  compare();
		while(!OK_FLAG);
		x=0;
		memset(response_temp,0,30);
	}
}