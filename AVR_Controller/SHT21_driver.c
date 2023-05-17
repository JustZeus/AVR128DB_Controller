/** @file SHT21_driver.c
*
* @brief Compact API for the SHT21 I2C Temperature Sensor
* @par Author: Ricardo Zamudio C.
*/

#include "SHT21_driver.h"

uint8_t SHT21_get_serial_number(){
	
}

uint8_t measure_SHT21_temp_not_HM(){
	char temperature_string[7];
	temperature_string[7] = '\0';
	uint8_t sensor_data[3]; 
	uint8_t checksum;
	uint16_t result;
	int sent_bytes = 0;
	int recieved_bytes = 0;
	float f_celcius_temperature;
	uint8_t command[1] = {TRIG_T_MEASUREMENT_POLL};
	
	sent_bytes = i2c_0_WriteData((SHT21_ADDRESS << 1), command, 1);
	_delay_ms(85);
	recieved_bytes = i2c_0_GetData((SHT21_ADDRESS << 1), sensor_data, 3);
	i2c_EndSession();
	
	printf("Sent bytes");
	printf(RETURN_CARRIAGE);
	printf(NEW_LINE);
	
	printf("result: %i", sent_bytes);
	printf(RETURN_CARRIAGE);
	printf(NEW_LINE);
	
	printf("Received bytes");
	printf(RETURN_CARRIAGE);
	printf(NEW_LINE);
	
	printf("result: %i", recieved_bytes);
	printf(RETURN_CARRIAGE);
	printf(NEW_LINE);
	
	printf("result byte 1: %i", sensor_data[0]);
	printf(RETURN_CARRIAGE);
	printf(NEW_LINE);
	printf("result byte 1: %i", sensor_data[1]);
	printf(RETURN_CARRIAGE);
	printf(NEW_LINE);
	printf("result byte 1: %i", sensor_data[2]);
	printf(RETURN_CARRIAGE);
	printf(NEW_LINE);
	
	result = (sensor_data[0] << 8);
	result += sensor_data[1];
	checksum = sensor_data[3];
	
	result &= ~0x0003;
	
	f_celcius_temperature = (-46.85 + 175.72/65536 * (float)result);
	
	dtostrf(f_celcius_temperature, 6, 3, temperature_string);
	printf(temperature_string);
	printf(RETURN_CARRIAGE);
	printf(NEW_LINE);
	
	return 1;
}