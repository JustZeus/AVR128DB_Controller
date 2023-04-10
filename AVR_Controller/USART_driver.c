/** @file USART_driver.c
* 
* @brief Compact API for the third USART peripheral in the AVR128DBXX Microcontroller
* @par Author: Ricardo Zamudio C.
*/ 

#include "USART_driver.h"


/*!
* @brief Initial register configurations to start the USART3 peripheral.
* Set-up for a 9600 Baud rate.
*
*/
void USART3_init(void)
{
	PORTB.DIR |= PIN0_bm;  // Set PORTB_PIN0 (TX_USART2) as an output, setting the DIR registry
	PORTB.DIR &= ~PIN1_bm; // Set the PORTB_PIN1 as an input

	USART3.BAUD = (uint16_t)USART3_BAUD_RATE(9600); // Config the Buad rate to 9600 using the MACRO

	USART3.CTRLB |= USART_TXEN_bm; // Enable the transmition TX
	USART3.CTRLB |= USART_RXEN_bm; // Enable Reception

	USART3.CTRLA = 0x90; // RXCIE enabled; TXCIE disabled; DREIE disabled; RXSIE enabled; LBME disabled; ABEIE disabled; RS485 DISABLE;

	stdout = &USART_stream;
}

/*!
* @brief Send a Char variable to the third USART peripheral 
* @param[in] c Char variable to be sent.
*/
void USART3_sendChar(char c)
{
	while (!(USART3.STATUS & USART_DREIF_bm)) // Check if the SATUTS register indicates we are ready to write new data
	{
		;
	}
	USART3.TXDATAL = c; // Write the c char variable in the TXDATAL buffer register.
}

/*!
* @brief Setup function to allow serial printing in the standard IO stream.
* @param[in] c Char variable to be sent.
* @param[in] stream FILE Stream object
* 
*/
int USART3_printChar(char c, FILE *stream)
{
	USART3_sendChar(c);
	return 0;
}


/*!
* @brief Read a Char variable from the third USART peripheral 
* @return The vairable read from the USART3 buffer register
*/
uint8_t USART3_read()
{
	while (!(USART3.STATUS & USART_RXCIF_bm)) // Check if the STATUS register indicates we are ready to read a new value
	{
		;
	}
	return USART3.RXDATAL; 
}

FILE USART_stream = FDEV_SETUP_STREAM(USART3_printChar, NULL, _FDEV_SETUP_WRITE); // File stream object declaration
