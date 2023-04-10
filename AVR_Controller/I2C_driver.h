/*
 * I2C_driver.h
 *
 * Created: 09/04/2023 09:04:46 p. m.
 *  Author: Ricardo Zamudio
 */ 

#include <avr/io.h>

#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_


/*!***********************************************************************
* @brief Preprocessor Macro to estimate the BAUD register value to define 
* the I2C's operation frequency. 
* 
**************************************************************************
*/
#define CLK_FREQ 16000000 // Selected main clock frequency (Configured at the clock_config.c file)
#define TWI_BAUD_CALCULATOR(FREQ_SCL, T_RISE)  ((((((float)CLK_FREQ / (float)FREQ_SCL)) - 10 - ((float)CLK_FREQ * T_RISE))) / 2)
#define I2C_SCL_FREQ 100000 // Selected frequency of 100 KHz for the I2C Bus.

/*!
*************************************************************************
* @brief TWI - Two Wire Interface register Bits set-up for a standard
* Phillips I2C communication.
*************************************************************************
*/
void i2c_init();



#endif /* I2C_DRIVER_H_ */