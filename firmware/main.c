/* Name: main.c
 * Author: evesan
 * Email: everardo.ipn@gmail.com
 * Copyright: CC 
 * License: Atribución-NoComercial 4.0 Internacional
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
