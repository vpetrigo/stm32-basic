/*
Author: Vladimir Petrigo

That header defines some macro for using with USART2 printf function
*/

#ifndef _PRINT_H_
#define _PRINT_H_

#include "usart2_io.h"

#ifdef DEBUG
#define debug_uart_print(fmt, ...) uart2_printf((fmt), ##__VA_ARGS__)
#else
#define debug_uart_print(...)
#endif // DEBUG

#define user_uart_print(fmt, ...) uart2_printf((fmt), ##__VA_ARGS__)


#endif // _PRINT_H