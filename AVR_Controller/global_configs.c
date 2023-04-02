/*
 * global_configs.c
 *
 * Created: 18/02/2023 09:19:22 p. m.
 *  Author: Ricardo Zamudio C.
 */
#include "global_configs.h"

void set_io_pins()
{
	PORTD.DIRSET = PIN4_bm; // RELAY 1
	PORTD.DIRSET = PIN6_bm; // RELAY 2
	PORTA.DIRSET = PIN7_bm; // RELAY 3
	PORTD.DIRSET = PIN0_bm; // RELAY 4
	

	PORTD.OUTCLR = PIN4_bm; // RELAY 1
	PORTD.OUTCLR = PIN6_bm; // RELAY 2
	PORTA.OUTCLR = PIN7_bm; // RELAY 3
	PORTD.OUTCLR = PIN0_bm; // RELAY 4


	PORTB.DIRSET = PIN3_bm; // ON BOARD LED (PB3) set as an output.
	PORTB.OUTSET = PIN3_bm; // Set the default state (HIGH).
}

void global_configs()
{
	set_io_pins();
	ENABLE_INTERRUPTS();
}