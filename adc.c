/*
 * ADC.c
 *
 *  Created on: Oct 4, 2022
 *      Author: fatima
 */
#include"adc.h"
#include"common_macros.h"
#include "avr/io.h"
/************************************************************
 *              functitions defitions             *
 ********************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr){
	/*configure ADMUX with
	 *REFS1:0  reference voltage
	 *ADLAR=0  right adjusted
	 * MUX4:0 = 00000 to choose channel 0 as initialization  */
	ADMUX=(Config_Ptr->ref_volt <<6 );

	/*configure prescalar with first three bits
	 * ADEN (bit7)   = 1 Enable ADC
	 * ADIE          = 0 Disable ADC Interrupt
	 * ADATE         = 0 Disable Auto Trigger
	 */
	ADCSRA=(Config_Ptr->prescaler & 0x07)|(1<<7);
}
uint16 ADC_readChannel(uint8 ch_num){
	ADMUX=(ADMUX & 0XE0)|(ch_num & 0x07);
	SET_BIT(ADCSRA,ADSC); /*start conversion write '1' to ADSC*/
    while(BIT_IS_CLEAR(ADCSRA,ADIF));  /*polling wait till conversion is completed */
   SET_BIT(ADCSRA,ADIF); /*clear falg by writing '1'*/
    return ADC;
}


