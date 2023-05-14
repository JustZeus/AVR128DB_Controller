/** @file SHT21_driver.h
*
* @brief Header file for the compact API for the SHT21 I2C Temperature Sensor
* @par Author: Ricardo Zamudio C.
*/

#include "I2C_driver.h"
#include "global_configs.h"
#include "USART_driver.h"

#ifndef SHT21_DRIVER_H_
#define SHT21_DRIVER_H_

#define SHT21_ADDRESS 0x40
#define TRIG_T_MEASUREMENT_HM 0xE3 // command trig. temp meas. hold master
#define TRIG_RH_MEASUREMENT_HM  0xE5 // command trig. humidity meas. hold master
#define TRIG_T_MEASUREMENT_POLL  0xF3 // command trig. temp meas. no hold master
#define TRIG_RH_MEASUREMENT_POLL  0xF5 // command trig. humidity meas. no hold master

uint8_t SHT21_get_serial_number();
uint8_t measure_SHT21_temp_not_HM();
#endif /* SHT21_DRIVER_H_ */