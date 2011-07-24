#include <hidef.h> 
#include "derivative.h" 

const byte port_config = 0x01; /* PTAD0 is test output, every other pins input */

void main(void) {
	EnableInterrupts;
	PTAPE = ~port_config; /* Pull-ups on inputs */
	PTAIFE = ~port_config; /* Low-pass filter on inputs */
	PTASE = port_config;
	PTADS = port_config;
	PTAD = port_config;
	PTADD = port_config;

	for (;;) {
		__RESET_WATCHDOG(); /* feeds the dog */
		PTAD = (PTAD & 2) >> 1; /* Read PTAD1 bit and write to PTAD0 */
	} 
}
