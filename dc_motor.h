/*
 * dc_motor.h
 *
 *  Created on: Oct 6, 2022
 *      Author: fatima
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include"std_types.h"
#include "gpio.h"
/****************************************************************
 *                       Definitions                       *
 ****************************************************************/
#define DC_MOTOR_PORT   PORTB_ID
#define DC_MOTOR_PIN0   PIN0_ID
#define DC_MOTOR_PIN1   PIN1_ID

/*enum for motor state stop 0 ,clock-wise 1, anti-clock-wise 2*/
typedef enum{
stop,CW,A_CW
}DcMotor_State;
/*******************************************************
 *                   functions prototype                          *
 ******************************************************************/

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
