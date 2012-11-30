/*
 * Alpha.c
 *
 * Created: 29.11.2012 19:19:18
 *  Author: Fabi
 */ 

#include "bluecontroller.h"

uint8_t      i;

void md_wait(void);
int led(void);

int main(void)
{

	bt_init();
	/* write data persistent EEPROM/Flash => only necessary one time */
	bt_setut();
	
	// ... warten bis der Sendepuffer leer ist ...
	while ( !( UCSRA & (1<<UDRE)) )
	UDR = MCUSR;

	//bt_check_turn_off

	while(1) {
		bt_puts("Was\n");
		_delay_ms(1000);
		
		if ( !(PIND & (1<<PIND2)) ) {
			
			DIMMSTART:
			
			while (OCR0B>20) {
				for (i = 235-OCR0B; i> 1; i--) {
					_delay_us(250);		
				}
				--OCR0B;
			}
			
			md_wait();
			// _delay_ms(5000);
			
			while (OCR0B<235) {
				
				for (i = 235-OCR0B; i> 1; i--) {
					_delay_ms(2);	
				}
				
				//  _delay_ms(DELAY_fall);
				
				++OCR0B;
				if ( !(PIND & (1<<PIND2)) ) {
					goto DIMMSTART;	
				}			
			}
		}		
	}
}

// Dieser Interrupt wird ausgelöst sobald neue Daten im USART-Empfangspuffer liegen
ISR(USART_RX_vect)
{
	
	unsigned char buffer;

	// Daten aus dem Puffer lesen ...
	buffer = UDR;

	if ( buffer == 'x' ) {
		bt_puts("hallo\n");
		_delay_ms(3000);
	}
	
	
	// ... warten bis der Sendepuffer leer ist ...
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	// ... und gleich wieder zurück schicken
	UDR0 = buffer;//
}




#define DELAY_MS2  20
uint8_t      i;

void md_wait(void)
{


	for (i = 60; i> 1; i--)
	{
		
		_delay_ms(1000);
		if ( !(PIND & (1<<PIND2)) ) {
			if (i<600){
			i=i+10; }
			led();
			
		}
		
	}
	
}


///////////////////////////////////////////////////// LED

int led(void)
{
	/* enable pin as output by setting the data direction register */
	DDRB|= (1<<DDB6);
	PORTB|= (1<<PORTB6);
	_delay_ms(DELAY_MS2);
	PORTB &= ~(1<<PORTB6);
	_delay_ms(DELAY_MS2);
	/*for(i=0; i<10; i++) {
		// led on, pin=0
		PORTB &= ~(1<<PORTB6);
		_delay_ms(DELAY_MS);
		// set output to 5V, LED off
		PORTB|= (1<<PORTB6);
		_delay_ms(DELAY_MS2);
	}*/

	return(0);
}