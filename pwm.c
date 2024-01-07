/*
 * pwm.c
 *
 *  Created on: Oct 7, 2022
 *      Author: fatima
 */
#include "avr/io.h"   /*to use pwm registers  */
#include"pwm.h"
#include"gpio.h"
/*************************************************************
 *                functions definitions               *
 ***********************************************************/
void PWM_Timer0_Start(uint8 duty_cycle)
{


	TCNT0=0;  /* initial value */

	OCR0= (uint8)( ( ((float32)duty_cycle/100)  ) *256 );  /* compare value duty*/

	/*set pwm_pin/PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.*/
	GPIO_setupPinDirection(PWM_PORT,PWM_PIN,PIN_OUTPUT);


	/* Configure timer control register
		 * 1. Fast PWM mode FOC0=0
		 * 2. Fast PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
		 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
		 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);



}

