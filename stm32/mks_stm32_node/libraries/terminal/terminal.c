#include "terminal.h"
#include "uart_print.h"

static const CommandEntry commands_list[] =
{
	/*00*/ {"help",			command_help_handler},
	/*01*/ {"version",		command_version_handler},
	/*02*/ {"nrfpwr",		command_nrfpwr_handler},
};

char *help =
{
	"Controller List of valid commands:\n\r"
	"help - Print help content\n\r"
};

uint8_t* ptr_message_buffer = &message_buffer[2];

void terminal(uint8_t input) {
	if (input == 13) {
		uart_out_ch("\n");
		uart_out_ch("\r");
		*ptr_message_buffer = 0;
		// Execute command
		controller_commands(&message_buffer[2]);
		uart_out_ch(">");
		uart_out_ch(" ");
		memset(message_buffer, 0, 80);
		ptr_message_buffer = &message_buffer[2];
	} else if (input == 127) {
		if (&message_buffer[2] != ptr_message_buffer) {
			ptr_message_buffer--;
			*ptr_message_buffer = 0;
			uart_out_ch((char *)&input);
		}
	} else {
		*ptr_message_buffer = input;
		ptr_message_buffer++;
		uart_out_ch((char *)&input);
	}
}

#define MAX_ARGS 16
int 	args[MAX_ARGS] = { -1 };
uint8_t args_count = 0;
uint8_t delimiters_index_counter = 0;
uint8_t delimiters_index[MAX_ARGS];

void controller_commands(uint8_t* buffer) {
	char cmd[32];
	uint8_t value[16];
	uint8_t buffer_len = strlen((char*)buffer);

	if (strlen((char*)buffer) < 1) {
		return;
	}

	// Looking for delimiter
	args_count = 0;
	delimiters_index_counter = 0;
	for (uint8_t i = 0; i < 32; i++) {
		if (delimiters_index_counter == MAX_ARGS) {
			break;
		}

		if (buffer[i] == ' ') {
			delimiters_index[delimiters_index_counter] = i;
			delimiters_index_counter++;
		}
	}

	// Parsing arguments
	memset(cmd, 0, 32);
	if (!delimiters_index_counter) {
		memcpy(cmd, buffer, buffer_len);
	} else {
		// First delimiter is command
		memcpy(cmd, buffer, delimiters_index[0]);
		// Find ARGS
		for (uint8_t i = 1; i < delimiters_index_counter; i++) {
			memset(value, 0, 16);
			memcpy(value, &buffer[delimiters_index[i-1]+1], (delimiters_index[i]) - (delimiters_index[i-1]+1));
			args[i-1] = atoi((char*)value);
			args_count++;
		}

		// Get last argument (between last delimiter and cartridge return)
		memcpy(cmd, buffer, delimiters_index[0]);
		memset(value, 0, 16);
		memcpy(value, &buffer[delimiters_index[delimiters_index_counter-1]+1], buffer_len - (delimiters_index[delimiters_index_counter-1]+1));
		args[args_count] = atoi((char*)value);
		args_count++;
	}

	// Find the requested command
	if (cmd[0] == '?') {
		commands_list[0].handler();
	} else {
		uint8_t command_index;
		for (command_index = 0; command_index < ELEMENTS_COUNT(commands_list); command_index++) {
			if (!strcmp(cmd, (char *)commands_list[command_index].name)) {
				break;
			}
		}

		if (command_index >= ELEMENTS_COUNT(commands_list)) {
		} else {
			commands_list[command_index].handler();
		}
	}
}

void command_help_handler(void) {
	uart_out(help);
}

void command_version_handler(void) {
	uart_out("0.0.1\n\r");
}

void command_nrfpwr_handler(void) {
	if (args_count != 1) {
		uart_out("No arguments provided\n\r");
		return;
	}

	if (!args[0]) {
		uart_out("NRF device OFF\n\r");
	} else if (1 == args[0]) {
		uart_out("NRF device ON\n\r");
	} else {
		uart_out("Unsupported state\n\r");
	}
}
