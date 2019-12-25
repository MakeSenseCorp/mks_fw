#ifndef __TERMINAL_H
#define __TERMINAL_H

#include "stdint.h"
#include "string.h"
#include <stdlib.h>

#define TRUE	0x1
#define FALSE	0x0

#define ELEMENTS_COUNT(array)  (sizeof (array) / sizeof ((array) [0]))

uint8_t message_buffer [80];

typedef void(*funcPtrCommandHandler)(void);

typedef struct {
	char*					name;
	funcPtrCommandHandler	handler;
} CommandEntry;

void terminal(uint8_t input);
void controller_commands(uint8_t* buffer);

void command_help_handler(void);
void command_version_handler(void);
void command_nrfpwr_handler(void);

#endif /* __TERMINAL_H */
