/* Name: main.c
 * Author: evesan
 * Email: everardo.ipn@gmail.com
 * Copyright: CC 
 * License: Atribución-NoComercial 4.0 Internacional
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_OSC 1000000
#define BAUD 9600

#include "communications/usart.h"
#include "camera/camera.h"
#include "debug/bt.h"

#include <util/delay.h>


int main(void)
{

  triggerOff();
  PORTB = 0b11111100; //se high state to interrupt connection with ground

  init_debug_led();
  //BAUD RATE 9600, UBRR -> 6
  initUSART();

  sei();

  for(;;) {
  }

  return 0;   /* never reached */
}

ISR(USART_RX_vect)
{
  char signal = read_c();
  if (signal == '1')
  {
    turn(3, 1);
    takePhoto();
  } else if (signal == '2')
  {
    makeFocus();
    turn(5, 1);
  } else 
  {
    triggerOff();
    turn(3, 0);
    turn(5, 0);
  }

  UDR = signal;
}

