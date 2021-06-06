#include "C:/Users/Youssef/Downloads/tm4c123gh6pm.h"
#include "stdint.h"
#include "math.h"

// Declaring Functions
int distance_Inc(void);
void delay_milli(int n);
void delay_micro(int n);
void LCD_PORT_A_B(void);
void LCD_Cmd(unsigned char command);
void LCD_Data(unsigned char data);
void Display_at_100(void);

// initializing Distance with 1
int D=1;

// Increcment function for Distance 
 int distance_Inc(){
	D = D+10;
	return D;
	}
 
	
 // Port A and B unlock for LCD
void LCD_PORT_A_B(void){
SYSCTL_RCGCGPIO_R |= 0x03; //PORT A and B clock activate
GPIO_PORTA_DIR_R |=0xE0;   //PORTA controls RS,E, and RW is connected to ground.
GPIO_PORTA_DEN_R |=0xE0;   //PORTA digital enable
GPIO_PORTB_DIR_R |=0xFF;   //PORTB D0-D7 output for data
GPIO_PORTB_DEN_R |=0xFF;   //PORTB D0-D7 Digital enable
delay_milli(20);
LCD_Cmd(0x30); // initializing sequence
delay_milli(5);
LCD_Cmd(0x30); 
delay_micro(100);
LCD_Cmd(0x30); 
LCD_Cmd(0x38); //adjusting 8-bits,2 display lines, 5x7 font for LCD
LCD_Cmd(0x06); //increments automatically
LCD_Cmd(0x01); //Turning on display
LCD_Cmd(0x0F); //clearing display
}
