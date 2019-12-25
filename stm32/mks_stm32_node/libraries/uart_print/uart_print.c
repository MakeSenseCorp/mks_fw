#include "uart_print.h"

extern UART_HandleTypeDef huart1;

void uart_out_ch(char* ptr_msg) {
	HAL_UART_Transmit(&huart1, (uint8_t *)ptr_msg, 1, 10);
}

void uart_out(char* ptr_msg) {
	uint8_t len = strlen(ptr_msg);
	HAL_UART_Transmit(&huart1, (uint8_t *)ptr_msg, len, 10);
}

uint8_t uart_in_ch() {
	uint8_t ch = 0;
	HAL_UART_Receive(&huart1, (uint8_t*)&ch, 1, 0xffff);

	return ch;
}

void uart_in(char* ptr, uint8_t len) {
}
