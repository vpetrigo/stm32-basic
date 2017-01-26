/*
Author: Vladimir Petrigo

USART2 module that implements functions for performing input/output
operations with standard library printf()/scanf() functions
*/

#ifndef _UART2_IO_H_
#define _UART2_IO_H_

#include <stdarg.h>
#include <stddef.h>
#include <__vfprintf.h>
#include "stm32l4xx_hal.h"

extern UART_HandleTypeDef huart2;

// CrossWorks definition for putchar function
int uart2_putc(int ch, __printf_t *ctx);
// CrossWorks definition for printf function
int uart2_printf(const char *fmt, ...);

// Function for getting/ungetting character
int uart2_ungetc(int ch);
int uart2_getc(void);

int uart2_scanf(const char *fmt, ...);

#endif // _USART2_IO_H_