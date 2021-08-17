/*
 * serial_connection.c
 *
 * Created: 6/2/2019 2:27:57 PM
 * Author: Mahdi mosazadeh
 */

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <mega32.h>
#include <delay.h>

void main(void)
{
    char recive[1];
    int number;
    
    DDRB = 0b00001111;    
    //set serial connection on micro controller
    UCSRA = 0x00;
    UCSRB = 0x10; // if mircro is sender value 0x08 if reciver 0x10
    UCSRC = 0x86;
    //set serial speed on 9600
    UBRRH = 0x00;
    UBRRL = 0x33;
    
while (1)
    {
        gets(recive,1);
        number=atoi(recive);//atoi --> change char to int. itoa --> change int to char.
        
        //button 1
        if (number==1)
        {
            PORTB = 0b00000001; 
            delay_ms(1000);
            PORTB = 0b00000000;
            
        }
        
        //button 2
        if (number==2)
        {
            PORTB = 0b00000010;
            delay_ms(1000);
            PORTB = 0b00000000; 
        }
        
        //button 3
        if (number==3)
        {
            PORTB = 0b00000100; 
            delay_ms(1000);
            PORTB = 0b00000000; 
        }
        
        //button 4
        if (number==4)
        {
            PORTB = 0b00001000; 
            delay_ms(1000);
            PORTB = 0b00000000; 
        }          
    }
}
