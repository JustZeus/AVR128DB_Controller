/*
 * commander.c
 *
 * Created: 11/02/2023 10:14:04 p. m.
 *  Author: Ricardo Zamudio C
 */ 

#include "commander.h"
#include <stdio.h>

void executeCommand(char *command)
{
	 char starting_char = command[0];
	 starting_char == '$'? command_switcher(command) : send_help_info();
	
}


void send_help_info(){
	printf("Not recognized command, type \"$ help\" to get the complete command set.\r\n");
}

void command_switcher(char *command){
	char main_command[MAIN_COMMAND_LENGTH];
	const int pound_sign_offset = 2;
	
	for (int i = 0; i < MAIN_COMMAND_LENGTH; i++)
	{
		main_command[i] = command[pound_sign_offset + i];
	}
	main_command[4] ='\0'; 
	
	if(strcmp(main_command, "ctrl") == 0)
		{
			printf("OK, CONTROL\r\n");
			set_relay_states(command);
			clear_command_buffer(command);
		}
	else if (strcmp(main_command, "show") == 0)
		{
			printf("OK, SHOW\r\n");
			clear_command_buffer(command);
		}
	else if (strcmp(main_command, "help") == 0)
		{
			printf("\r\nAVR-CONTROLLER, Version: 0.0.1, Ricardo Zamudio C. \r\n Command list: \r\n [ctrl] -controls the relay's states \r\n [show] -displays the actual states \r\n");
			clear_command_buffer(command);
		} 
	else 
		{
			send_help_info();
			clear_command_buffer(command);
		}
}


void clear_command_buffer(char *command){
	for (int i =0; i<MAIN_COMMAND_LENGTH; i++)
	{
		command[i]=0x00;
	}
}


void set_relay_states(char *command){

	const char delimeter = ',';

	char cursor = MAIN_COMMAND_LENGTH + 1;
	char [2] number;
	int index = 0;
	int is_a_two_digit_number = 0;
	*char[] end_char;

	while(end_char == BLANK_SPACE || NEW_LINE || RETURN_CARRIAGE)
	{
		number[index] = command[cursor];
		cursor++;
		index++;

		if(index==1){
			is_a_two_digit_number=1;
		}	

		if(command[cursor] == delimeter || BLANK_SPACE)
		{		
			index=0;
			printf(number);
			printf("\r\n");
		}
		
		end_char=command[cursor];
	
	}
	
}
