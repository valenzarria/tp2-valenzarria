#include <Arduino.h>
#include <util/delay.h>

#define prender(PORT, PIN) (PORT |= 1 << PIN)
#define apagar(PORT, PIN) (PORT &= ~(1 << PIN))

#define bot1 (PIND & (1 << PD7)) // LEER BOTON 1 (INICIO)
#define bot2 (PIND & (1 << PD6)) // LEER BOTON 2 (PARAR DADO)
#define bot3 (PIND & (1 << PD5)) // LEER BOTON 3 (REINICIAR)
#define bot4 (PIND & (1 << PD4)) // LEER BOTON 4 (REINICIAR)

void mostrar_led(char num);

char cont = 0;
char FLAG_BT1;

int main(void)
{

  DDRD |= (1 << PD2);
  DDRD |= (1 << PD3);
  DDRB |= (1 << PB0);
  DDRB |= (1 << PB1);
  DDRB |= (1 << PB2);
  DDRB |= (1 << PB3);
  DDRB |= (1 << PB4);

  DDRD &= ~(1 << PD4);
  DDRD &= ~(1 << PD5);
  DDRD &= ~(1 << PD6);
  DDRD &= ~(1 << PD7);

  while (1)
  {
    if (bot1 == 0)
    {
      FLAG_BT1 = 1; // (bandera)
    }

    if (FLAG_BT1 == 1)
    {
      cont++;

      if (cont == 7)
      {
        cont = 1;
      }

      mostrar_led(cont);
      _delay_ms(500);
    }
    _delay_ms(100);
    if (bot2 == 0)
    {

      FLAG_BT1 = 0;
    }
    if (bot3 == 0 || bot4 == 0)
    {

      apagar(PORTD, 2);
      apagar(PORTD, 3);
      apagar(PORTB, 0);
      apagar(PORTB, 1);
      apagar(PORTB, 2);
      apagar(PORTB, 3);
      apagar(PORTB, 4);
    }
    /* code */
  }
}

void mostrar_led(char num)
{
  apagar(PORTD, 2);
  apagar(PORTD, 3);
  apagar(PORTB, 0);
  apagar(PORTB, 1);
  apagar(PORTB, 2);
  apagar(PORTB, 3);
  apagar(PORTB, 4);

  switch (num) // secuencias
  {
  case 1:
    prender(PORTB, 4);
    break;
  case 2:
    prender(PORTB, 0);
    prender(PORTB, 1);
    break;

  case 3:
    prender(PORTB, 4);
    prender(PORTB, 0);
    prender(PORTB, 1);
    break;

  case 4:
    prender(PORTD, 2);
    prender(PORTB, 0);
    prender(PORTB, 1);
    prender(PORTB, 3);
    break;

  case 5:
    prender(PORTD, 2);
    prender(PORTB, 0);
    prender(PORTB, 1);
    prender(PORTB, 3);
    prender(PORTB, 4);
    break;

  case 6:
    prender(PORTD, 2);
    prender(PORTD, 3);
    prender(PORTB, 0);
    prender(PORTB, 1);
    prender(PORTB, 2);
    prender(PORTB, 3);
    break;
  }
}
