/** @file I2C_driver.c
* 
* @brief Compact API for the TWI peripheral in the AVR128DBXX Microcontroller
* @par Author: Ricardo Zamudio C.
*/ 
#include "I2C_driver.h"

enum {
	I2C_INIT = 0,
	I2C_ACKED,
	I2C_NACKED,
	I2C_READY,
	I2C_ERROR
};


 uint8_t i2c_0_WaitR(void)
{
	uint8_t state = I2C_INIT;
	
	do
	{
		if(TWI0.MSTATUS & (TWI_WIF_bm | TWI_RIF_bm))
		{
			state = I2C_READY;
		}
		else if(TWI0.MSTATUS & (TWI_BUSERR_bm | TWI_ARBLOST_bm))
		{
			/* get here only in case of bus error or arbitration lost - M4 state */
			state = I2C_ERROR;
		}
	} while(!state);
	
	return state;
}

static uint8_t i2c_0_WaitW(void)
{
	uint8_t state = I2C_INIT;
	do
	{
		if(TWI0.MSTATUS & (TWI_WIF_bm | TWI_RIF_bm))
		{
			if(!(TWI0.MSTATUS & TWI_RXACK_bm))
			{
				/* client responded with ack - TWI goes to M1 state */
				state = I2C_ACKED;
			}
			else
			{
				/* address sent but no ack received - TWI goes to M3 state */
				state = I2C_NACKED;
			}
		}
		else if(TWI0.MSTATUS & (TWI_BUSERR_bm | TWI_ARBLOST_bm))
		{
			/* get here only in case of bus error or arbitration lost - M4 state */
			state = I2C_ERROR;
		}
	} while(!state);
	
	return state;
}

/* Returns how many bytes have been received, -1 means NACK at address */
uint8_t i2c_0_GetData(uint8_t address, uint8_t *pData, uint8_t len)
{
	uint8_t retVal = (uint8_t) - 1;
	
	/* start transmitting the client address */
	TWI0.MADDR = address | 0x01;
	if(i2c_0_WaitW() != I2C_ACKED){
	return retVal;
	}

	retVal = 0;
	if((len != 0) && (pData !=0))
	{
		while(len--)
		{
			if(i2c_0_WaitR() == I2C_READY)
			{
				*pData = TWI0.MDATA;
				TWI0.MCTRLB = (len == 0)? TWI_ACKACT_bm | TWI_MCMD_STOP_gc : TWI_MCMD_RECVTRANS_gc;
				retVal++;
				pData++;
				continue;
			}
			else
			break;
		}
	}
	
	return retVal;
}


/* Returns how many bytes have been sent, -1 means NACK at address, 0 means client ACKed to client address */
uint8_t i2c_0_SendData(uint8_t address, uint8_t *pData, uint8_t len)
{
	uint8_t retVal = (uint8_t) - 1;
	
	/* start transmitting the client address */
	TWI0.MADDR = address & ~0x01;
	if(i2c_0_WaitW() != I2C_ACKED)
	return retVal;

	retVal = 0;
	if((len != 0) && (pData != 0x00))
	{
		while(len--)
		{
			TWI0.MDATA = *pData;
			if(i2c_0_WaitW() == I2C_ACKED)
			{
				retVal++;
				pData++;
				continue;
			}
			else // did not get ACK after client address
			{
				break;
			}
		}
	}
	
	return retVal;
}

/*!
* @brief TWI - Two Wire Interface register Bits set-up for a standard 
* Phillips I2C communication.                                                                
*/
void i2c_init(){
	
	 TWI0.MBAUD = (uint8_t)TWI_BAUD_CALCULATOR(I2C_SCL_FREQ, 0); // Select the frequency for the TWI Bus

	 TWI0.MCTRLA = TWI_ENABLE_bm; // Enable the TWI Peripheral
	 
	 TWI0.MADDR = 0x00; // Clear the MADDR Register
	 
	 TWI0.MDATA = 0x00; // Clear the MDATA Register
	 
	 TWI0.MSTATUS = TWI_BUSSTATE_IDLE_gc; // Start the Bus state in IDLE mode
}

void i2c_EndSession(void){
	TWI0.MCTRLB = TWI_MCMD_STOP_gc; // Host Control B, Execute Acknowledge Action followed by issuing a Stop condition
}