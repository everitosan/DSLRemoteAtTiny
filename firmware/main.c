/* Name: main.c
 * Author: evesan
 * Email: everardo.ipn@gmail.com
 * Copyright: CC 
 * License: Atribución-NoComercial 4.0 Internacional
 */

#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"

// Signal geths the data received by bluetooth
char signal;

void triggerOff(void);
void takePhoto(void);
void makeFocus(void);

int main(void)
{
  signal = '0';
  triggerOff();

  PORTB = 0b11111100; //se high state to interrupt connection with ground

  //BAUD RATE 9600, UBRR -> 6
  initUSART();

  for(;;){
    signal = read_c();

    if (signal == '1' ) { // FOCUS
      // triggerOff();
      makeFocus();
    } else if (signal == '2') {//TRIGGER
      // triggerOff();
      takePhoto();
    } else if (signal == '0') { //OFF
      triggerOff();
    }
  }

  return 0;   /* never reached */
}

void triggerOff(void) {
  DDRB &= (0 << DDB0); //set as input focus
  DDRB &= (0 << DDB1); //set as input trigger
  PORTB = 0b00000000;
}

void takePhoto(void) {
  DDRB |= (1 << DDB0); //set as input pin0 of PORTB
  PORTB = 0b11111110; //set ground pin0 of PORTB
}

void makeFocus(void) {
  DDRB |= (1 << DDB1); //set as input pin1 of PORTB
  PORTB = 0b11111101; //set ground pin1 of PORTB
}
