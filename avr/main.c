#include <avr/io.h>        					
#undef F_CPU
#define F_CPU 16000000L    											// Atmega is running @16MHz
#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <stdlib.h>

#include "delay.h"
#include "uart.h"

int main(void)
{
	int k = 0; 
	
	initUART();		
	stdout = &uart_output;
	stdin  = &uart_input;
	
	DDRB |= (1<<PB5);
	
	while(1)
	{
		PORTB ^=(1<<PB5);    
		delay_ms(500);
		printf("%d\r\n",rand() & (1024-1));
		k++;
	} 
}
