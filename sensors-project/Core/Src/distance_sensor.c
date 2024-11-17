/*
 * distance_sensor.c
 *
 *  Created on: May 10, 2024
 *      Author: hitmachut
 */

#include "distance_sensor.h"
#include "sync_manager.h"

uint32_t pMillis;
uint32_t time_start = 0;
uint32_t time_end = 0;

Status_t init_distance_sensor(TIM_HandleTypeDef *timer)
{
	HAL_TIM_Base_Start(timer);
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);  // pull the TRIG pin low
	return xSUCCESS; //TODO
}

float read_distance(TIM_HandleTypeDef *sensorTimer)
{

	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	__HAL_TIM_SET_COUNTER(sensorTimer, 0);
	while (__HAL_TIM_GET_COUNTER (sensorTimer) < TIMER_GAP);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);  // pull the TRIG pin low

	pMillis = HAL_GetTick(); // used this to avoid infinite while loop  (for timeout)
		// wait for the echo pin to go high
	while (!(HAL_GPIO_ReadPin (ECHO_PORT, ECHO_PIN)) && pMillis + TIMER_GAP >  HAL_GetTick());
	time_start = __HAL_TIM_GET_COUNTER (sensorTimer);

	pMillis = HAL_GetTick(); // used this to avoid infinite while loop (for timeout)
		// wait for the echo pin to go low
	while ((HAL_GPIO_ReadPin (ECHO_PORT, ECHO_PIN)) && pMillis + 50 > HAL_GetTick()); //TODO
	time_end = __HAL_TIM_GET_COUNTER (sensorTimer);

	return (float)(time_end - time_start) * SPEED_OF_SOUND ;
}

void task_periodic_measure_distance(void *timer)
{
	TIM_HandleTypeDef *sensorTimer = (TIM_HandleTypeDef*)timer;
	float dis;
	while(1)
		{

			dis = read_distance(sensorTimer);
//			vTaskDelay(100);
			take_dis();
			Distance=dis;
			give_dis();
		}

}

