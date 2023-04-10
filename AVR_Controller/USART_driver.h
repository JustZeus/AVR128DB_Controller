/** @file USART_driver.h
* 
* @brief Header file for the csompact API for the third USART peripheral in the AVR128DBXX Microcontroller
* @par Author: Ricardo Zamudio C.
*/ 

#define F_CPU (16000000UL) /* using default clock 4MHz*/
#define MAX_COMMAND_LEN 20
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define USART3_BAUD_RATE(BAUD_RATE) ((float)(64 * 16000000 / (16 * (float)BAUD_RATE)) + 0.5)

#ifndef USART_DRIVER_H_
#define USART_DRIVER_H_

void USART3_sendChar(char c);
int USART3_printChar(char c, FILE *stream);
void USART3_init(void);
uint8_t USART3_readCommand(void);

#endif /* USART_DRIVER_H_ */