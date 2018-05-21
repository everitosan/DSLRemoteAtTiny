/* Name: main.c
 * Author: evesan
 * Email: everardo.ipn@gmail.com
 * Copyright: CC 
 * License: Atribución-NoComercial 4.0 Internacional
 */

void triggerOff(void);
void takePhoto(void);
void makeFocus(void);


void triggerOff() {
  DDRB &= (0 << DDB0); //set as input focus
  DDRB &= (0 << DDB1); //set as input trigger
  PORTB = 0b00000000;
}

void takePhoto() {
  DDRB |= (1 << DDB0); //set as input pin0 of PORTB
  PORTB = 0b11111110; //set ground pin0 of PORTB
}

void makeFocus() {
  DDRB |= (1 << DDB1); //set as input pin1 of PORTB
  PORTB = 0b11111101; //set ground pin1 of PORTB
}
