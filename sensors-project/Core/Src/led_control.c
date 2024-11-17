/*
 * led_control.c
 *
 *  Created on: May 29, 2024
 *      Author: hitmachut
 */
#include "led_control.h"
#include "main.h"

void init_led(){
  led_off();
}

void led_on(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,GPIO_PIN_SET);
}
void led_off(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,GPIO_PIN_RESET);
}
void led_blink(uint32_t frequency){
	led_on();
	vTaskDelay(frequency);
	led_off();
}

void led_pwm(TIM_HandleTypeDef *htim3){
	int* data = (int*)malloc(sizeof(int));
	*data = (int)(rand() % PWM_MAX_VALUE) + 1;
	pwmSetValue(*data,htim3);
	if (data)
		free(data);
	vTaskDelay(500);
}


void pwmSetValue(uint16_t pulseWidth, TIM_HandleTypeDef *htim3)
{
	TIM_OC_InitTypeDef sConfigOC = {0};
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = pulseWidth;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(htim3, &sConfigOC, TIM_CHANNEL_1);//config the channel with the new pulse width
	HAL_TIM_PWM_Start(htim3, TIM_CHANNEL_1);//start the PWM signal
}
