#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000UL                                 // Define frequência da CPU para 1MHz para ajustar a função de delay
#define RESET_PIN PB3
#define OUT PB4

int MODE = 2;
int a = 0;

volatile uint8_t i = 0;

void setup() {
    DDRB |= (1 << OUT);                                 // Define OUT como output
    PORTB &= ~(1 << OUT);                               // Define OUT como LOW
    DDRB &= ~(1 << RESET_PIN);                          // Define RESET_PIN como input
    PORTB |= (1 << RESET_PIN);                          // Comando para ligar o resistor de pull-up (mesmo comando para definir um pino como HIGH, porém o pino está definido como input e não output)
}

// Função de que define o modo de forma automática
void SetMode (int mode) { 
  for (int i = 0; i > mode; i++) {
    PORTB |= (1 << OUT); // define OUT como HIGH
    _delay_ms(100);
    PORTB &= ~(1 << OUT);
    _delay_ms(500);
  }
}

void loop() {
// Rotina para definir o mode automaticamente
  if (a == 0){
    SetMode(MODE);
    a++;
  }

// Rotina para definir o modo manualmente 
  if(PINB & (1 << RESET_PIN) == 0) {                      // Isola a variável de PB3 e compara com 0 (LOW), indicando que o botão foi pressionado
    _delay_ms(100);
    PORTB |= (1 << OUT);
    _delay_ms(500);
    PORTB &= ~(1 << OUT);
  }     
}
