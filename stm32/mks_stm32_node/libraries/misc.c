#include "misc.h"

void ftoa(float number, char * data, float precision) {
	__disable_irq();
	float 	abs_num = fabs(number);
	int 	log_num = log10(abs_num); // calculate magnitude (Ex. 100 -> 2, 10 -> 2, 1 -> 0)
	int 	digit = 0;
	uint8_t	safty_counter = 0;

	// Is negative number.
	if (number < 0) {
		*(data++) = '-';
		safty_counter++;
	}

	if (log_num < 1.0) {
		log_num = 0;
	}

	while ((abs_num > precision || log_num >= 0) && safty_counter < 7)
	{
		float weight = pow(10.0f, log_num);
		digit = floor(abs_num / weight);
		abs_num -= (digit*weight);
		*(data++) = '0' + digit;
		safty_counter++;
		if (log_num == 0) {
			*(data++) = '.';
			safty_counter++;
		}
		log_num--;
	}

	*(data) = '\0';
	__enable_irq();
}
