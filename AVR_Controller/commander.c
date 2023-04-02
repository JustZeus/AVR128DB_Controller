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
	starting_char == '$' ? command_switcher(command) : send_help_info();
}

void send_help_info()
{
	printf("Not recognized command, type \"$ help\" to get the complete command set.\r\n");
}

void command_switcher(char *command)
{
	char main_command[MAIN_COMMAND_LENGTH];
	const int pound_sign_offset = 2;

	for (int i = 0; i < MAIN_COMMAND_LENGTH; i++)
	{
		main_command[i] = command[pound_sign_offset + i];
	}
	main_command[4] = '\0';

	if (strcmp(main_command, "ctrl") == 0)
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

void clear_command_buffer(char *command)
{
	for (int i = 0; i < MAIN_COMMAND_LENGTH; i++)
	{
		command[i] = 0x00;
	}
}

void set_relay_states(char *command)
{

	int cursor = MAIN_COMMAND_LENGTH + 2;
	int index = 1;
	int operation = get_operation(command);
	char current_char[2];
	char number_buffer[3];

	do
	{
		current_char[0] = command[cursor];
		current_char[1] = '\0';

		if (current_char[0] == ',' || current_char[0] == ' ')
		{

			number_buffer[0] = '0';
			number_buffer[1] = command[cursor - 1];
			number_buffer[2] = '\0';

			printf("Delimiter noticed, relay number encountered  ");
			printf(number_buffer);
			printf(RETURN_CARRIAGE);
			printf(NEW_LINE);
			index = 0;
		}

		if (index == 2 && current_char[0] != ' ')
		{
			printf("Two digit relay not supported yet, Exiting now.");
			printf(RETURN_CARRIAGE);
			printf(NEW_LINE);
			break;
		}

		cursor++;
		index++;

		if (cursor > (20))
		{
			printf("ERROR 01: No state selected, try \"$ ctrl [RELAY NUMBERS] TGL\" ");
			printf(RETURN_CARRIAGE);
			printf(NEW_LINE);
			break;
		}

	} while (current_char[0] != ' ');
}

int get_operation(char *command)
{
	char current_char[2];
	int cursor = MAIN_COMMAND_LENGTH + 2;

	while (current_char[0] != '-')
	{

		current_char[0] = command[cursor];
		cursor++;

		if (cursor > 20)
		{
			printf("ERROR 02: No state operation detected");
			printf(RETURN_CARRIAGE);
			printf(NEW_LINE);
			break;
		}
	}

	printf("Change state operation detected at cursor: %d", cursor);
	printf(RETURN_CARRIAGE);
	printf(NEW_LINE);

	read_operation(command, cursor);
};

int read_operation(char *command, int cursor)
{
	char operation[] = "   ";

	for (int index = 0; index < 4; index++)
	{
		operation[index] = command[index + cursor];
	}

	operation[3] = '\0';

	if (strcmp(operation, "tgl") == 0)
	{
		printf("OK, TOGGLE\r\n");
	}
	else if (strcmp(operation, "on ") == 0)
	{
		printf("OK, ON STATE");
	}
	else if (strcmp(operation, "off") == 0)
	{
		printf("OK OFF STATE");
	}
	else
	{
		send_help_info();
		clear_command_buffer(command);
	}
	printf("Change state operation: ");
	printf(operation);
	printf(RETURN_CARRIAGE);
	printf(NEW_LINE);
}
