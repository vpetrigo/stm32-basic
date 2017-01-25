/*
Author: Vladimir Petrigo

Simple delay functionality based on the System Timer.
Utilize HAL_SYSTICK_Callback

WARNING: This is unoptimized delay as it causes CPU to stay awake
during all delay cycle
*/

#ifndef _SIMPLE_DELAY_H_
#define _SIMPLE_DELAY_H_

#include <stdint.h>

void Delay(const uint32_t ms_delay);

#endif // _SIMPLE_DELAY_H_