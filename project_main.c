/*
 * project_main.c
 *
 *  Created on: Oct 7, 2022
 *      Author: fatima
 */
#include"lcd.h"
#include"lm35_sensor.h"
#include"dc_motor.h"
uint8 g_temp=0;
int main(){
	LCD_init();
	DcMotor_Init();
	LCD_moveCursor(0,4);
	LCD_displayString("FAN IS ");
	LCD_moveCursor(1,4);
    LCD_displayString("TEMP =    C");
    while(1){
    	g_temp=LM35_getTemperature();
    	LCD_moveCursor(0,11);

        if( g_temp < 30)
        {

        	LCD_displayString("OFF");
        	LCD_moveCursor(1,11);
        	LCD_intgerToString(g_temp);
        	if( g_temp < 10){
        		LCD_displayString(" ");
        	}
        	DcMotor_Rotate(stop,0);
        }
        else{
        	LCD_displayString("ON");
        	LCD_displayString(" ");
        	LCD_moveCursor(1,11);
        	LCD_intgerToString(g_temp);
        }
         if(g_temp >= 30 && g_temp < 60)
        {
        	 LCD_displayString(" ");
        	 DcMotor_Rotate(CW,25);
        }
        else if(g_temp >= 60 && g_temp < 90)
        {
        	LCD_displayString(" ");
            DcMotor_Rotate(CW,50);
         }

        else if(g_temp >= 90 && g_temp < 120)
        {
        	if(g_temp < 100){
        		LCD_displayString(" ");
        	}
             DcMotor_Rotate(CW,75);

         }
        else if (g_temp >= 120 )
        {
            DcMotor_Rotate(CW,99.99);
        }
    }
}
