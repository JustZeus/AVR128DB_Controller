/*
 * USART_driver.h
 *
 * Created: 11/02/2023 03:24:45 p. m.
 *  Author: Ricardo Zamudio C.
 */ 
#define F_CPU                           (16000000UL)         /* using default clock 4MHz*/
#define MAX_COMMAND_LEN 12
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>



#define USART3_BAUD_RATE(BAUD_RATE)     ((float)(64 * 16000000 / (16 * (float)BAUD_RATE)) + 0.5)

#ifndef USART_DRIVER_H_
#define USART_DRIVER_H_



void USART3_sendChar(char c);
int USART3_printChar(char c, FILE *stream);
void USART3_init(void);
uint8_t USART3_readCommand(void);



#endif /* USART_DRIVER_H_ */