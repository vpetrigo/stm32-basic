/* 
Author: Vladimir Petrigo

Basic functionality for LED blinking functionality 
*/

#include "main.h"
#include "stm32l4xx_hal.h"
#include "simple_delay.h"

// set up hardcoded delay value to 1000 ms
#define STD_DELAY_VALUE 1000

void LED_Toggle_Timeout(void) {
  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
  Delay(STD_DELAY_VALUE);
}
