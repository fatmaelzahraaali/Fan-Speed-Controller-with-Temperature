/*
 * ADC.h
 *
 *  Created on: Oct 4, 2022
 *      Author: fatima
 */

#ifndef ADC_H_
#define ADC_H_
#include"std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
/*enum for reference voltage put in ADMUX register(bit6,bit7)
 *AREF=0            REFS1=0 , REFS0=0   Internal Vref turned off
 *Avcc=1            REFS1=0 , REFS0=1   5v reference
 *Reserved=2        REFS1=1 , REFS0=0
 *internal_verf=3   REFS1=1 , REFS0=1  Internal 2.56V Voltage
 */
typedef enum
{
	AREF,AVCC,Reserved,internal_vref
}ADC_ReferenceVolatge;
/*enum for prescalar put in ADCSRA register(bit0,1,2)
 *pre_2=1          ADPS2=0 ADPS1=0 ADPS0=1
 *pre_4=2          ADPS2=0 ADPS1=1 ADPS0=0
 *pre_8=3          ADPS2=0 ADPS1=1 ADPS0=1
 *pre_16=4         ADPS2=1 ADPS1=0 ADPS0=0
 *pre_32=5         ADPS2=1 ADPS1=0 ADPS0=1
 *pre_64=6         ADPS2=1 ADPS1=1 ADPS0=1
 *pre_128=7        ADPS2=1 ADPS1=1 ADPS0=1
 */
typedef enum{
pre_2=1,pre_4,pre_8,pre_16,pre_32,pre_64,pre_128
}ADC_Prescaler;
typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 ch_num);


#endif /* ADC_H_ */
