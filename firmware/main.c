/* Name: main.c
 * Author: evesan
 * Email: everardo.ipn@gmail.com
 * Copyright: CC 
 * License: Atribución-NoComercial 4.0 Internacional
 */

#include <avr/io.h>
#include <util/delay.h>
#include "communications/usart.h"
#include "camera/camera.h"

// Signal geths the data received by bluetooth
char signal;

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

