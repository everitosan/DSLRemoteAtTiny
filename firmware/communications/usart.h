/* Name: main.c
 * Author: evesan
 * Email: everardo.ipn@gmail.com
 * Copyright: CC 
 * License: Atribución-NoComercial 4.0 Internacional
 */

#include <util/delay.h>
#define F_OSC 1000000
#define BAUD 9600
#define MYUBRR (6)

void initUSART(void);
void sendData (char *a);
void sendChar (char c); 
char read_c (void);

void initUSART(){
  UBRRH = ((unsigned char) (MYUBRR >> 8));
  UBRRL = ((unsigned char) (MYUBRR));

  /*
    Receiver ENABLED
    Transmiter ENABLED
    Receiver interruption ENABLED
  */
  UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
  /*
    Parity Mode: DISABLED
    Stop Bit: 1 bit
    Character Size: 8 bits
  */
  UCSRC = (1 << UCSZ1) | (1 << UCSZ0) | (0 << USBS) ;
}


void sendData(char *a) {
  int index = 0;
  while (a[index] != '\0') {
    _delay_ms(10);
    UDR=a[index];
    index++;
  }
  UDR = '\r';
  _delay_ms(20);
  UDR = '\n';
}

void sendChar (char c) {
  //while ( !( UCSRA & (1<<UDRE)) )
  UDR = c;
}

char read_c () {
  while ( !(UCSRA & (1<<RXC)) );
  return UDR;
}