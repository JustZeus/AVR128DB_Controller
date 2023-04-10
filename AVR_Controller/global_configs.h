/** @file global_configs.h
* 
* @brief Header file for the global microcontroller register configuration.
* @par Author: Ricardo Zamudio C.
*/ 

#include <avr/io.h>
#include <avr/xmega.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

#ifndef GLOBAL_CONFIGS_H_
#define GLOBAL_CONFIGS_H_

#define ENABLE_INTERRUPTS() __asm__ __volatile__("sei" ::: "memory")

// Define the TURN ON Relay directives to the preprocessor.
#define TURN_ON_RELAY1() PORTD.OUTSET = PIN4_bm
#define TURN_ON_RELAY2() PORTD.OUTSET = PIN6_bm
#define TURN_ON_RELAY3() PORTA.OUTSET = PIN7_bm
#define TURN_ON_RELAY4() PORTD.OUTSET = PIN0_bm

// Define the TURN OFF Relay directives to the preprocessor.
#define TURN_OFF_RELAY1() PORTD.OUTCLR = PIN4_bm
#define TURN_OFF_RELAY2() PORTD.OUTCLR = PIN6_bm
#define TURN_OFF_RELAY3() PORTA.OUTCLR = PIN7_bm
#define TURN_OFF_RELAY4() PORTD.OUTCLR = PIN0_bm

// Define the TOGGLE Relay directives to the preprocessor.
#define TOGGLE_RELAY1() PORTD.OUTTGL = PIN4_bm
#define TOGGLE_RELAY2() PORTD.OUTTGL = PIN6_bm
#define TOGGLE_RELAY3() PORTA.OUTTGL = PIN7_bm
#define TOGGLE_RELAY4() PORTD.OUTTGL = PIN0_bm

/*!
* @brief set the I/O PORT registers for the relays
*/
void set_io_pins();
/*!
* @brief Call the multiple functions to initialize the desired configurations, enable global interrupts.
*/
void global_configs();

#endif /* GLOBAL_CONFIGS_H_ */