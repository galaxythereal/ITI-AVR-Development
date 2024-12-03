/*
 * motorInterface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mahmoud Ezzat
 */

#ifndef HAL_MOTOR_MOTORINTERFACE_H_
#define HAL_MOTOR_MOTORINTERFACE_H_
#define forwardPin 0
#define backwardPin 1
#define port 'C'

void motorInit(void);
void motorOn(void);
void motorStop(void);
#endif /* HAL_MOTOR_MOTORINTERFACE_H_ */
