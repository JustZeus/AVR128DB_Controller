/** @file clock_config.c
* 
* @brief Internal clock config. functions
* @par Author: Ricardo Zamudio C.
*/ 

#include "clock_config.h"

void set_internal_clock()
{

	/*!
	 * We use the _PROTECTED_WRITE Function from the xmega.h library
	 * It's needed because we cannot directly write to the CLOCK registers
	 */
	_PROTECTED_WRITE(CLKCTRL.MCLKCTRLA, CLKCTRL.MCLKCTRLA | CLKSEL_OSCHF_gc);	    // Select the High Frequency Cristal Oscillator
	_PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0x00);						    // Clear the MCLKCTRLB register, NO prescaler.
	_PROTECTED_WRITE(CLKCTRL.OSCHFCTRLA, CLKCTRL.OSCHFCTRLA | CLKCTRL_FRQSEL_16M_gc); // Establish 16 MHz as the main CLOCK frequency
	_PROTECTED_WRITE(CLKCTRL.PLLCTRLA, CLKCTRL.PLLCTRLA | 0x00);			    // Establish 16 MHz as the main CLOCK frequency
}
