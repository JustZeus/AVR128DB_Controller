/** @file commander.h
* 
* @brief Header file for the USART commander CLI 
* @par Author: Ricardo Zamudio C.
*/ 

#include <avr/io.h>
#include <stdio.h>
#include "global_configs.h"
#include "SHT21_driver.h"

#ifndef COMMANDER_H_
#define COMMANDER_H_


void executeCommand(char *command);
void send_help_info();
void command_switcher(char *command);
void clear_command_buffer(char *command);

// Control functions:
void set_relay_states(char *command);
void relay_state_changer(char relay_id, char state, int cursor);
int get_operation(char *command);
int read_operation(char *command, int cursor);
void tgl_relay(char *relay_number);
void turn_on_relay(char *relay_number);
void turn_off_relay(char *relay_number); 


// Informative functions
void show_temperature(char *command);

#endif /* COMMANDER_H_ */