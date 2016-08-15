/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>
//#include <avr/interrupt.h>
#include "usart.h"

char signal;

int main(void)
{
  signal = '0';
  //Set port B1 and B0 as outputs
   DDRB = 1 << 0; //focus
   DDRB = 1 << 1;  //trigger
   DDRB = 1 << 2;  //test

  //BAUD RATE 9600, UBRR -> 6
  initUSART();
  //sei();

  //  for(;;){
  //   signal = uart_getc();
  //   if (signal == '1' ) { // FOCUS
  //     PORTD = 0 << 0; //set down trigger
  //     PORTD = 1 << 1;
  //     PORTB = 0 << 2;     

  //   } else if (signal == '2') {//TRIGGER
  //     PORTD = 0 << 1; //set down focus
  //     PORTD = 1 << 0;
  //     PORTB = 0 << 2;
           
  //   } else if (signal == '0') { //OFF
  //     PORTD = 0 << 0; //set down trigger
  //     PORTD = 0 << 1; //set down focus
  //     PORTB = 0 << 2;
  //   } else {
  //     PORTB = 1 << 2;    /* toggle the LED */   
  //   }
  //     _delay_ms(500);  /* max is 262.14 ms / F_CPU in MHz */
  // }
  for(;;){
    signal = read_c();
    sendChar(signal);

    if (signal == '1' ) { // FOCUS
      PORTB = 0 << 0; //set down trigger
      PORTB = 1 << 1;   
    } else if (signal == '2') {//TRIGGER
      PORTB = 0 << 1; //set down focus
      PORTB = 1 << 0;
    } else if (signal == '0') { //OFF
      PORTB = 0 << 0; //set down trigger
      PORTB = 0 << 1; //set down focus
    }
  }

  return 0;   /* never reached */
}
