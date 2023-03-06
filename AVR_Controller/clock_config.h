/*
 * clock_config.h
 *
 * Created: 11/02/2023 02:59:05 p. m.
 *  Author: ihade
 */ 

#include <avr/io.h>
#include <avr/xmega.h>

#ifndef CLOCK_CONFIG_H_
#define CLOCK_CONFIG_H_


/*!
* @brief Does the main clock configuration writing to protected registers.
*/
void set_internal_clock();

#endif /* CLOCK_CONFIG_H_ */