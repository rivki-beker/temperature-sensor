/*
 * task_manager.h
 *
 *  Created on: May 10, 2024
 *      Author: hitmachut
 */

#ifndef INC_TASK_MANAGER_H_
#define INC_TASK_MANAGER_H_

#include "FreeRTOS.h"
#include "task.h"
#include "distance_sensor.h"
#include "temperature_sensor.h"
#include "led_control.h"
#include "alarm.h"

#define QUEUE_DEPTH 100

#define READ_DISTANCE_TASK_PRIORITY 10
#define MEASURE_TEMP_TASK_PRIORITY 10
#define ALARM_CALC_TASK_PRIORITY 10
#define ALARM_TURN_ON_TASK_PRIORITY 11

void create_tasks(TIM_HandleTypeDef *timer, ADC_HandleTypeDef *adc, TIM_HandleTypeDef *htim3);

void create_read_distance_task(TIM_HandleTypeDef *timer);
void create_measure_temperature_task(ADC_HandleTypeDef *adc);
void create_alarm_calc_task();
void create_alarm_turn_on_task();
#endif /* INC_TASK_MANAGER_H_ */
