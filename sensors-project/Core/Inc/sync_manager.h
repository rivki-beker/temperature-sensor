/*
 * sync_manager.h
 *
 *  Created on: Jun 4, 2024
 *      Author: hitmachut
 */

#ifndef INC_SYNC_MANAGER_H_
#define INC_SYNC_MANAGER_H_
#include "main.h"
#include "FreeRTOS.h"
#include "semphr.h"
static SemaphoreHandle_t mutex_temp;
static SemaphoreHandle_t mutex_dis;
static SemaphoreHandle_t mutex_status;

static int MAX_DELAY = 100;

void init_mutex();

void take_temp();
void take_dis();
void take_status();

void give_temp();
void give_dis();
void give_status();

#endif /* INC_SYNC_MANAGER_H_ */
