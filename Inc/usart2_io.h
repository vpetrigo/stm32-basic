/*
Author: Vladimir Petrigo

USART2 module that implements functions for performing input/output
operations with standard library printf()/scanf() functions
*/

#ifndef _UART2_IO_H_
#define _UART2_IO_H_

#include <stdarg.h>
#include <__vfprintf.h>

extern UART_HandleTypeDef huart2;

// CrossWorks definition for putchar function
int uart2_putc(int ch, __printf_t *ctx);
// CrossWorks definition for printf function
int uart2_printf(const char *fmt, ...);

#endif // _USART2_IO_H_