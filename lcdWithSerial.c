/*
 * serial_connection.c
 *
 * Created: 6/2/2019 2:27:57 PM
 * Author: pers
 */

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <lcd.h>
#include <mega32.h>
#include <delay.h>
#asm
.equ __lcd_port=0x1b
#endasm

void main(void)
{
    char recive[1];
    
    
    //set serial connection on micro controller
    UCSRA = 0x00;
    UCSRB = 0x10; // if mircro is sender value 0x08 if reciver 0x10
    UCSRC = 0x86;
    //set serial speed on 9600
    UBRRH = 0x00;
    UBRRL = 0x33; 
    
    lcd_init(16);
	lcd_clear();
    
while (1)
    {
        gets(recive,1);
        lcd_puts(recive);  
        delay_ms(200);  
        lcd_clear();     
    }
}
