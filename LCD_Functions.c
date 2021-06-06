//LCD Command Function
void LCD_Cmd(unsigned char command)
{
GPIO_PORTA_DATA_R = 0x00; //RS =0, E=0, RW is connected to ground
GPIO_PORTB_DATA_R =command;
GPIO_PORTA_DATA_R =0x80; //E=1 to secure command
delay_micro(0);
GPIO_PORTA_DATA_R =0x00;
if(command <4) delay_milli(2); 
else delay_micro(40); } //Delay For reading inputs of LCD

//LCD Data function
void LCD_Data(unsigned char data) {
GPIO_PORTA_DATA_R =0x20; //RS=1, E=0,RW connected to the ground
GPIO_PORTB_DATA_R =data;
GPIO_PORTA_DATA_R |= 0x80; //Setting cruser to the first line
delay_micro(0);
GPIO_PORTA_DATA_R =0x00; //Resetting
delay_micro(40);
 
}
