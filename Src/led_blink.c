/* 
Author: Vladimir Petrigo

Basic functionality for LED blinking functionality 
*/

#include "main.h"
#include "stm32l4xx_hal.h"
#include "simple_delay.h"

void LED_Toggle_Timeout(const uint32_t ms_delay) {
  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
  Delay(ms_delay);
}
