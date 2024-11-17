/*
 * alarm.c
 *
 *  Created on: May 29, 2024
 *      Author: hitmachut
 */
#include "alarm.h"
#include "distance_sensor.h"
#include "temperature_sensor.h"
#include "led_control.h"
#include "sync_manager.h"

void init_alarm(){
	init_led();
}

void calc_status_led(){

take_temp();
float temp = Temperature;
give_temp();

take_dis();
float dis = Distance;
give_dis();

int stat;

if(Temperature>30)//blink
	stat=4;
else if(Temperature<15)//analog
	stat=3;
else if(Distance<100)//alight
	stat=2;
else//off
	stat=1;

take_status();
Status=stat;
give_status();


}

void turn_on_by_status(TIM_HandleTypeDef *htim3){
take_status();
	switch (Status) {
		case 1:
			led_off();
			break;
		case 2:
			led_on();
			break;
		case 3:
			led_pwm(htim3);
			break;
		case 4:
			if(Distance<50)
				led_blink(250);
			else
				led_blink(500);
			break;

}
give_status();

}

void task_measure_calc()
{
	while(1)
	{
		calc_status_led();
		//vTaskDelay(1000);
	}
}

void task_measure_turn_on(TIM_HandleTypeDef *htim3)
{
	while(1)
	{
		turn_on_by_status(htim3);
		//vTaskDelay(1000);
	}
}
