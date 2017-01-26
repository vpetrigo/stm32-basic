/*
Author: Vladimir Petrigo

USART2 module that implements functions for performing input/output
operations with standard library printf()/scanf() functions
*/

#include <limits.h>
#include "usart2_io.h"
#include "main.h"

#define LF '\n'
#define CR '\r'
#define ONE_BYTE_PKG 1
#define UART_TIMEOUT 5

// Handy macro that use predefined values for the last
// two parameters of HAL_UART_Transmit function
#define HAL_OneByte_Transmit(uart, data) \
  HAL_UART_Transmit((uart), (data), ONE_BYTE_PKG, UART_TIMEOUT)

int uart2_putc(int ch, __printf_t *ctx) {
  while (HAL_OneByte_Transmit(&huart2, (uint8_t *) &ch) != HAL_OK) {
  }

  return ch;
}

int uart2_printf(const char *fmt, ...) {
  int n;
  va_list ap;
  __printf_t iod;

  va_start(ap, fmt);
  iod.string = 0;
  iod.maxchars = INT_MAX;
  iod.output_fn = uart2_putc;
  n = __vfprintf(&iod, fmt, ap);
  va_end(ap);

  return n;
}