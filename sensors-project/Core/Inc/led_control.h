/*
 * led_control.h
 *
 *  Created on: May 29, 2024
 *      Author: hitmachut
 */

#ifndef INC_LED_CONTROL_H_
#define INC_LED_CONTROL_H_
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

#define PWM_MAX_VALUE 1000

	void init_led(void);
	void led_on(void);
	void led_off(void);
	void led_pwm(TIM_HandleTypeDef *htim3);
	void led_blink(uint32_t frequency) ;
	void pwmSetValue(uint16_t pulseWidth, TIM_HandleTypeDef *htim3);

#endif /* INC_LED_CONTROL_H_ */
