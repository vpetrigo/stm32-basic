/*
Author: Vladimir Petrigo

Simple delay functionality based on the System Timer.
Utilize HAL_SYSTICK_Callback
*/

#include "simple_delay.h"

// Private variable for storing ms_ticks
static volatile uint32_t ms_tick = 0;

void HAL_SYSTICK_Callback(void) {
  ++ms_tick;
}

void Delay(const uint32_t ms_delay) {
  const uint32_t start = ms_tick;

  while (ms_tick - start < ms_delay) {
  }

  ms_tick = 0;
}
