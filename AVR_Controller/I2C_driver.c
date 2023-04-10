/*
 * I2C_driver.c
 *
 * Created: 09/04/2023 09:05:18 p. m.
 *  Author: Ricardo Zamudio
 */ 
#include "I2C_driver.h"


/*!***********************************************************************
* @brief TWI - Two Wire Interface register Bits set-up for a standard 
* Phillips I2C communication.                                                                
**************************************************************************
*/
void i2c_init(){
	
	 TWI0.MBAUD = (uint8_t)TWI_BAUD_CALCULATOR(I2C_SCL_FREQ, 0);

	 TWI0.MCTRLA = TWI_ENABLE_bm;
	 
	 TWI0.MSTATUS = TWI_BUSSTATE_IDLE_gc;
}