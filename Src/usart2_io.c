/*
Author: Vladimir Petrigo

USART2 module that implements functions for performing input/output
operations with standard library printf()/scanf() functions
*/

#include "usart2_io.h"
#include "main.h"
#include <limits.h>

#define LF '\n'
#define CR '\r'
#define ONE_BYTE_PKG 1
#define UART_TIMEOUT 5

// Handy macro that use predefined values for the last
// two parameters of HAL_UART_Transmit function
#define HAL_OneByte_Transmit(uart, data) \
  HAL_UART_Transmit((uart), (data), ONE_BYTE_PKG, UART_TIMEOUT)

#define HAL_OneByte_Receive(uart, data) \
  HAL_UART_Receive((uart), (data), ONE_BYTE_PKG, UART_TIMEOUT)

static int uart2_ungot = EOF;

int uart2_putc(int ch, __printf_t *ctx) {
  if (ch == LF) {
    char carriage_ret = CR;

    while (HAL_OneByte_Transmit(&huart2, (uint8_t *) &carriage_ret) != HAL_OK) {
    }
  }
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

int uart2_ungetc(int ch) {
  uart2_ungot = ch;
}

int uart2_getc(void) {
  int ch = '\0';

  if (uart2_ungot != EOF) {
    ch = uart2_ungot;
    uart2_ungot = EOF;

    return ch;
  }
  else {
    while (HAL_OneByte_Receive(&huart2, (uint8_t *)&ch) != HAL_OK) {
    }

    return ch;
  }
}

int uart2_scanf(const char *fmt, ...) {
  __HAL_UART_DISABLE_IT(&huart2, UART_IT_RXNE);
  __stream_scanf_t iod;
  va_list a;
  int n;

  va_start(a, fmt);
  iod.is_string = 0;
  iod.getc_fn = uart2_getc;
  iod.ungetc_fn = uart2_ungetc;
  n = __vfscanf((__scanf_t *)&iod, (const unsigned char *)fmt, a);
  va_end(a);
  __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);

  return n;
}
