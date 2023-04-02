/*
 * USART_driver.c
 *
 * Created: 11/02/2023 03:24:19 p. m.
 *  Author: Ricardo Zamudio C.
 *
 */

#include "USART_driver.h"

void USART3_sendChar(char c)
{
	while (!(USART3.STATUS & USART_DREIF_bm))
	{
		;
	}
	USART3.TXDATAL = c;
}

int USART3_printChar(char c, FILE *stream)
{
	USART3_sendChar(c);
	return 0;
}

FILE USART_stream = FDEV_SETUP_STREAM(USART3_printChar, NULL, _FDEV_SETUP_WRITE);

uint8_t USART3_read()
{
	while (!(USART3.STATUS & USART_RXCIF_bm))
	{
		;
	}
	return USART3.RXDATAL;
}

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
