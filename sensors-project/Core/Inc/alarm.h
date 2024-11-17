/*
 * alarm.h
 *
 *  Created on: May 29, 2024
 *      Author: hitmachut
 */

#ifndef INC_ALARM_H_
#define INC_ALARM_H_
#include "main.h"
static int Status;

void init_alarm();
void calc_status_led();
void turn_on_by_status();
void task_measure_calc();
void task_measure_turn_on(TIM_HandleTypeDef *htim3);

#endif /* INC_ALARM_H_ */
