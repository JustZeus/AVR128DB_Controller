/*
 * AVR_Controller.c
 *
 * Created: 11/02/2023 02:49:44 p. m.
 * Author : Ricardo Zamudio
 * This is a demonstration code to prove the Bare metal
 * AVR micro controller programming from the Microchip Technology's
 * 8-bit AVRDB family
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "clock_config.h"
#include "USART_driver.h"
#include "commander.h"
#include "global_configs.h"

#define toggle_status_led() PORTB.OUTTGL |= PIN3_bm;

volatile char command[MAX_COMMAND_LEN];
static uint8_t index = 0;
volatile char c;





int main(void)
{
	set_internal_clock();
	USART3_init();
	global_configs();
	printf("\r\nAVR-CONTROLLER, Version: 0.0.1, Ricardo Zamudio C. \r\n Command list: \r\n [ctrl] -controls the relay's states \r\n [show] -displays the actual states \r\n");
    while (1) 
    {
	
    }
}


ISR(USART3_RXC_vect){
	toggle_status_led();
	c = USART3_read();
	if(c != '\n' && c != '\r')
	{
		command[index++] = c;
		if(index > MAX_COMMAND_LEN)
		{
			index = 0;
		}
	}
	if(c == '\n')
	{
		command[index] = '\0';
		index = 0;
		executeCommand(command);
	}
}

