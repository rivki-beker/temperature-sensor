/*
 * temperature_sensor.h
 *
 *  Created on: May 10, 2024
 *      Author: hitmachut
 */

#ifndef INC_TEMPERATURE_SENSOR_H_
#define INC_TEMPERATURE_SENSOR_H_

#include "main.h"

#define VOLT_SUPPLY 3300.0 //in miliVolt
#define ANALOG_RANGE 4096 //TODO
#define MILIVOLT_PER_DEGREE 10

static float Temperature;

Status_t init_temperature_sensor(ADC_HandleTypeDef *adc);
float read_temperature(ADC_HandleTypeDef *adc);
void task_measure_temperature(void *adc);


#endif /* INC_TEMPERATURE_SENSOR_H_ */
