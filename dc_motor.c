/*
 * dc_motor.c
 *
 *  Created on: Oct 6, 2022
 *      Author: fatima
 */
#include"dc_motor.h"
#include"pwm.h"   /*to use pwmtimer0*/

/*********************************************************
 *              functions definitions    *
 ******************************************************
 *******************************************************/
/*
 * Description :
 * Initialize the DC motor:
 * 1. Setup the motor's pins directions by use the GPIO driver.
 * 2. Stop motor at first.
 */
void DcMotor_Init(void)
{
/* set the dc-motor two pins direction    */
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN0,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN1,PIN_OUTPUT);
/*make motor stopped at first  */
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN0,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){

		PWM_Timer0_Start(speed);

	switch(state)
   {
   /*pin0 0 pin1 0 in case of stop */
      case stop :
    	  GPIO_writePin(DC_MOTOR_PORT , DC_MOTOR_PIN0,LOGIC_LOW);
    	  GPIO_writePin(DC_MOTOR_PORT  , DC_MOTOR_PIN1,LOGIC_LOW);
    	  break;
    	  /*in case of clock wise pin0 1 pin1 0 */
      case CW :
    	  GPIO_writePin(DC_MOTOR_PORT , DC_MOTOR_PIN1,LOGIC_LOW);
    	  GPIO_writePin(DC_MOTOR_PORT , DC_MOTOR_PIN0,LOGIC_HIGH);
    	  break;
    	  /*in case of clock wise pin0 0 pin1 1 */
      case A_CW :
    	  GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOGIC_HIGH);
    	  GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN0,LOGIC_LOW);
          break;
   }


}

