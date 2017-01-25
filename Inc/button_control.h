/*
Author: Vladimir Petrigo

Button control functionality for controlling LED toggling rate.
That module overrides HAL_GPIO_EXTI_Callback

Example:

uint16_t led_blinks_delay_ms[] = {100, 250, 500, 1000}
...
ButtonControl_SetUpRateRange(sizeof(led_blinks_delay_ms) / sizeof(led_blinks_delay_ms[0]))
...
// somewhere in main application
uint8_t led_blink_rate = ButtonControl_GetRate();
// use that variable somewhere to toggle LED with received rate
...
*/

#ifndef _BUTTON_CONTROL_H_
#define _BUTTON_CONTROL_H_

#include <stdint.h>

// Set up LED blinking rate range [0 ... rate_range) that will
// be updated by Button interrupt handler
void ButtonControl_SetUpRateRange(const uint8_t rate_range);
// Return current LED blinking rate
uint8_t ButtonControl_GetRate(void);

#endif // _BUTTON_CONTROL_H_