/*
Author: Vladimir Petrigo

USART2 module that implements functions for performing input/output
operations with standard library printf()/scanf() functions
*/

#include "usart2_io.h"
#include "main.h"
#include "stm32l4xx_hal.h"

#define LF '\n'
#define CR '\r'
#define ONE_BYTE_PKG 1
#define UART_TIMEOUT 5

#define HAL_OneByte_Transmit(uart, data) \
  HAL_UART_Transmit((uart), (data), ONE_BYTE_PKG, UART_TIMEOUT)

int uart2_putc(int ch, __printf_t *ctx) {
  if (ch == LF) {
    uint8_t to_send = CR;

    while (HAL_OneByte_Transmit(&huart2, &to_send) != HAL_OK) {
    }
  }

  while (HAL_OneByte_Transmit(&huart2, (uint8_t *) &ch) != HAL_OK) {
  }

  return ch;
}