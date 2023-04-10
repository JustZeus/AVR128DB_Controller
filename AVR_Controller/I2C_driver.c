/** @file I2C_driver.c
* 
* @brief Compact API for the TWI peripheral in the AVR128DBXX Microcontroller
* @par Author: Ricardo Zamudio C.
*/ 
#include "I2C_driver.h"


/*!
* @brief TWI - Two Wire Interface register Bits set-up for a standard 
* Phillips I2C communication.                                                                
*/
void i2c_init(){
	
	 TWI0.MBAUD = (uint8_t)TWI_BAUD_CALCULATOR(I2C_SCL_FREQ, 0);

	 TWI0.MCTRLA = TWI_ENABLE_bm;
	 
	 TWI0.MSTATUS = TWI_BUSSTATE_IDLE_gc;
}