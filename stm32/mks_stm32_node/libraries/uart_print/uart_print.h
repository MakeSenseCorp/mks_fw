#ifndef __UART_PRINT_H
#define __UART_PRINT_H

#include "stm32f1xx_hal.h"
#include "stdint.h"
#include "string.h"

#define MAS_UART_PRINT_BUFFER_LEN 64

char output_buffer[MAS_UART_PRINT_BUFFER_LEN];
char input_buffer[MAS_UART_PRINT_BUFFER_LEN];

void 	uart_out_ch	(char* ptr);
void 	uart_out	(char* ptr);
uint8_t uart_in_ch	();
void	uart_in		(char* ptr, uint8_t len);

#endif /* __UART_PRINT_H */
