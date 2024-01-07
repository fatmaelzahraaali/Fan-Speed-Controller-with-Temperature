/*
 * pwm.h
 *
 *  Created on: Oct 7, 2022
 *      Author: fatima
 */

#ifndef PWM_H_
#define PWM_H_
#include"std_types.h"
/**************************************************
 *             definitions
 */
#define PWM_PORT        PORTB_ID
#define PWM_PIN         PIN3_ID
/***************************************************
 *           functions prototypes
 ****************************************************/
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
