/*
 * task_manager.c
 *
 *  Created on: May 10, 2024
 *      Author: hitmachut
 */


#include "task_manager.h"
#include "main.h"

static TaskHandle_t * ReadDistanceTask;
static TaskHandle_t * MeasureTempTask;
static TaskHandle_t * AlarmCalcTask;
static TaskHandle_t * AlarmTurnOnTask;

void create_tasks(TIM_HandleTypeDef *timer, ADC_HandleTypeDef *adc, TIM_HandleTypeDef *htim3)
{
	create_read_distance_task(timer);
	create_measure_temperature_task(adc);
	create_alarm_calc_task();
	create_alarm_turn_on_task(htim3);
}

void create_read_distance_task(TIM_HandleTypeDef *timer)
{
	xTaskCreate(task_periodic_measure_distance, "Read Distance", QUEUE_DEPTH, timer, READ_DISTANCE_TASK_PRIORITY, ReadDistanceTask);
}

void create_measure_temperature_task(ADC_HandleTypeDef *adc)
{
	xTaskCreate(task_measure_temperature, "Read Temp", QUEUE_DEPTH, adc, MEASURE_TEMP_TASK_PRIORITY, MeasureTempTask);
}


void create_alarm_calc_task(){
	xTaskCreate(task_measure_calc, "Alarm_Calc", QUEUE_DEPTH, NULL, MEASURE_TEMP_TASK_PRIORITY, AlarmCalcTask);
}

void create_alarm_turn_on_task(TIM_HandleTypeDef *htim3){
	xTaskCreate(task_measure_turn_on, "Alarm_Turn_on", QUEUE_DEPTH, htim3, MEASURE_TEMP_TASK_PRIORITY, AlarmTurnOnTask);
}
