/** @file I2C_driver.h
* 
* @brief Header file for the compact API for the TWI peripheral in the AVR128DBXX Microcontroller
* @par Author: Ricardo Zamudio C.
*/ 

#include <avr/io.h>

#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_


/*!
* @brief Preprocessor Macro to estimate the BAUD register value to define 
* the I2C's operation frequency. 
*/
#define CLK_FREQ 16000000 // Selected main clock frequency (Configured at the clock_config.c file)
#define TWI_BAUD_CALCULATOR(FREQ_SCL, T_RISE)  ((((((float)CLK_FREQ / (float)FREQ_SCL)) - 10 - ((float)CLK_FREQ * T_RISE))) / 2)
#define I2C_SCL_FREQ 100000 // Selected frequency of 100 KHz for the I2C Bus.

/*!
* @brief TWI - Two Wire Interface register Bits set-up for a standard
* Phillips I2C communication.
*/
void i2c_init();

/*!
* @brief After the TWI initialization this function sends the data to the selected address, you must specify the data length
* @param address 7-bit device address
* @param pData uint8_t array with the 8 bits commands
* @param len Length of the commands array
*/
uint8_t i2c_0_WriteData(uint8_t address, uint8_t *pData, uint8_t len); // returns how many bytes have been sent, -1 means NACK at address

/*!
* @brief After the TWI initialization this function reads the data from the selected address, you must specify the data length expected
* @param address 7-bit device address
* @param pData uint8_t array to store the recieved data 
* @param len Length of the expected bytes
*/
uint8_t i2c_0_GetData(uint8_t address, uint8_t *pData, uint8_t len); // returns how many bytes have been received, -1 means NACK at address

/*!
* @brief End the I2C Session by executing Acknowledge Action followed by issuing a Stop condition
*/
void i2c_EndSession(void);



#endif /* I2C_DRIVER_H_ */