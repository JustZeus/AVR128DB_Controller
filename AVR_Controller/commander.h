/*
 * commander.h
 *
 * Created: 11/02/2023 10:13:49 p. m.
 *  Author: Ricardo Zamudio C.
 */ 

#include <avr/io.h>


#ifndef COMMANDER_H_
#define COMMANDER_H_

#define MSG_OK "\r\nOK\r\n"
#define MAIN_COMMAND_LENGTH 5

void executeCommand(char *command);
void send_help_info();
void command_switcher(char *command);
void clear_command_buffer(char *command);



#endif /* COMMANDER_H_ */