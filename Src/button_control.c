/*
Author: Vladimir Petrigo

Button control functionality for controlling LED toggling rate.
That module overrides HAL_GPIO_EXTI_Callback
*/

#include "stm32l4xx_hal.h"
#include "button_control.h"
#include "main.h"

static uint8_t max_rate_range = 0;
static uint8_t cur_rate = 0;

void ButtonControl_SetUpRateRange(const uint8_t rate_range) {
  max_rate_range = rate_range;
}

uint8_t ButtonControl_GetRate(void) {
  return cur_rate % max_rate_range;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
  if (GPIO_Pin == B1_Pin) {
    ++cur_rate;
  }
}