/*
 * sync_manager.c
 *
 *  Created on: Jun 4, 2024
 *      Author: hitmachut
 */
#include "sync_manager.h"
void init_mutex(){
	mutex_temp = xSemaphoreCreateMutex();
	mutex_dis = xSemaphoreCreateMutex();
	mutex_status = xSemaphoreCreateMutex();
}
void take_temp(){
	xSemaphoreTake(mutex_temp, MAX_DELAY);
}
void take_dis(){
	xSemaphoreTake(mutex_dis, MAX_DELAY);
}
void take_status(){
	xSemaphoreTake(mutex_status, MAX_DELAY);
}

void give_temp(){
	xSemaphoreGive(mutex_temp);
}
void give_dis(){
	xSemaphoreGive(mutex_dis);
}
void give_status(){
	xSemaphoreGive(mutex_status);
}
