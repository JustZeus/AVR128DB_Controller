/** @file commander.c
 *
 * @brief USART commander CLI
 * @par Author: Ricardo Zamudio C.
 */

#include "commander.h"

void executeCommand(char *command)
{
	char starting_char = command[0];									 // Get the starting char.
	starting_char == '$' ? command_switcher(command) : send_help_info(); // Cherck for $ as the starting char, else send help info.
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
		show_temperature(command);
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
	volatile char relay_number[3];

	do
	{
		current_char[0] = command[cursor];
		current_char[1] = '\0';

		if (current_char[0] == ',' || current_char[0] == ' ')
		{

			relay_number[0] = '0';
			relay_number[1] = command[cursor - 1];
			relay_number[2] = '\0';

			printf("Delimiter noticed, relay number encountered  ");
			printf(relay_number);
			printf(RETURN_CARRIAGE);
			printf(NEW_LINE);

			if (operation == 0)
			{
				tgl_relay(relay_number);
			}
			if (operation == 1)
			{
				turn_on_relay(relay_number);
			}
			if (operation == 2)
			{
				turn_off_relay(relay_number);
			}
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

	return read_operation(command, cursor);
};

int read_operation(char *command, int cursor)
{
	char operation[] = "   ";
	for (int index = 0; index < 4; index++)
	{
		operation[index] = command[index + cursor];
		if (index == 1 && command[index + cursor] == 'n')
		{
			break;
		}
	}

	operation[3] = '\0';
	printf("Change state operation: ");
	printf(operation);
	printf(RETURN_CARRIAGE);
	printf(NEW_LINE);
	if (strcmp(operation, "tgl") == 0)
	{
		return 0;
	}
	else if (strcmp(operation, "on ") == 0)
	{
		return 1;
	}
	else if (strcmp(operation, "off") == 0)
	{
		return 2;
	}
	else
	{
		send_help_info();
		clear_command_buffer(command);
		return 3;
	}
}

void tgl_relay(char *relay_number)
{

	char local_relay_number_buffer[3];
	local_relay_number_buffer[0] = relay_number[0];
	local_relay_number_buffer[1] = relay_number[1];
	local_relay_number_buffer[2] = '\0';

	if (strcmp(local_relay_number_buffer, "01") == 0)
	{
		printf("Relay 1 toggled");
		printf(RETURN_CARRIAGE);
		printf(NEW_LINE);
		TOGGLE_RELAY1();
	}
	else if (strcmp(local_relay_number_buffer, "02") == 0)
	{
		printf("Relay 2 toggled");
		printf(RETURN_CARRIAGE);
		printf(NEW_LINE);
		TOGGLE_RELAY2();
	}
	else if (strcmp(local_relay_number_buffer, "03") == 0)
	{
		printf("Relay 3 toggled");
		printf(RETURN_CARRIAGE);
		printf(NEW_LINE);
		TOGGLE_RELAY3();
	}
	else if (strcmp(local_relay_number_buffer, "04") == 0)
	{
		TOGGLE_RELAY4();
	}
	else
	{
		send_help_info();
	}
}

void turn_on_relay(char *relay_number)
{
	if (strcmp(relay_number, "01") == 0)
	{
		TURN_ON_RELAY1();
	}
	else if (strcmp(relay_number, "02") == 0)
	{
		TURN_ON_RELAY2();
	}
	else if (strcmp(relay_number, "03") == 0)
	{
		TURN_ON_RELAY3();
	}
	else if (strcmp(relay_number, "04") == 0)
	{
		TURN_ON_RELAY4();
	}
	else
	{
		send_help_info();
	}
}

void turn_off_relay(char *relay_number)
{
	if (strcmp(relay_number, "01") == 0)
	{
		TURN_OFF_RELAY1();
	}
	else if (strcmp(relay_number, "02") == 0)
	{
		TURN_OFF_RELAY2();
	}
	else if (strcmp(relay_number, "03") == 0)
	{
		TURN_OFF_RELAY3();
	}
	else if (strcmp(relay_number, "04") == 0)
	{
		TURN_OFF_RELAY4();
	}
	else
	{
		send_help_info();
	}
}

//---------------------------------------------------------------
//- Show informative functions-----------------------------------

void show_temperature(char *command)
{
	uint8_t error;
	for (int i = 0; i < 25; i++)
	{
		error = measure_SHT21_temp_not_HM();
	}
}
