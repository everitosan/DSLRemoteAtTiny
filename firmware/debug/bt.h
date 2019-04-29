/* Name: main.c
 * Author: evesan
 * Email: everardo.ipn@gmail.com
 * Copyright: CC 
 * License: Atribución-NoComercial 4.0 Internacional

 This module helps in the development using leds to
 expose the correct functionality of the BT connection.
 */

#include <util/delay.h>

void init_debug_led()
{
/*
This function will initiate the PORTD
use it as output
*/
  DDRD &= (1 << 3);
  DDRD &= (1 << 5);

  PORTD = (0 << 3);
  PORTD = (0 << 5);

}

void log_recieved(char opt)
{
  if (opt == '1')
  {
    PORTD = (1 << 3);
  } else  if (opt == '2')
  {
    PORTD = (1 << 5);
  }
  else {
    PORTD = (0 << 3); 
    PORTD = (0 << 5); 
  }
}

void blink_D_PIN(int pin)
{
    PORTD = (1 << pin); 
    _delay_ms(500);
    PORTD = (0 << pin);
    _delay_ms(500); 
}

void turn(int pin, int level)
{
  PORTD = (level << pin); 
}