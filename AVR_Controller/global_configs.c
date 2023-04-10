/** @file global_configs.c
* 
* @brief Global microcontroller register configuration.
* @par Author: Ricardo Zamudio C.
*/ 

#include "global_configs.h"
/*!
* @brief set the I/O PORT registers for the relays
*/
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
/*!
* @brief Call the multiple functions to initialize the desired configurations, enable global interrupts.
*/
void global_configs()
{
	set_io_pins();
	ENABLE_INTERRUPTS();
}