#ifndef _LED_H
#define _LED_H
#include "sys/sys.h"

#define LED0 PCout(0) //LED0
#define LED1 PCout(1) //LED1
#define LED2 PCout(2) //LED2
#define LED3 PCout(3) //LED3
#define LED4 PCout(4) //LED4
#define LED5 PCout(5) //LED5
#define LED6 PCout(6) //LED6
#define LED7 PCout(7) //LED7

void LED_Init(void);
#endif
