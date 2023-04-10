/** @file clock_config.h
* 
* @brief Header file for the internal clock config.
* @par Author: Ricardo Zamudio C.
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