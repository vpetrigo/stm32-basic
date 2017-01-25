/* 
Author: Vladimir Petrigo

Basic functionality for LED blinking functionality 
*/

#ifndef _LED_BLINK_H_
#define _LED_BLINK_H_

#include <stdint.h>

void LED_Toggle_Timeout(const uint32_t ms_delay);

#endif // _LED_BLINK_H_