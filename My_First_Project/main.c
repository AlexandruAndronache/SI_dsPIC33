#include "p33Fxxxx.h"

// Function declarations
void delay(int amount);
void RB7_interrupt_Init(void);

void delay(int amount)
{
	int i = 0;
	for (i; i < amount; i++){}
}

// Globals
volatile unsigned int button_pressed = 0;
	


int main()
{
	TRISB = 0;
	int a = 7;
	
	RB7_interrupt_Init();
	
	while(1)
	{
		// Toggle the LED based on the interrupt
		(button_pressed == 1) ? (_LATB7 = 0) : (_LATB7 = 1);
		// _LATB7 ^= 1;	
		delay(10);

		a = _RB7;
	}			
	return 0;
}


// External interrupt service routine (ISR) for RB7
void __attribute__((__interrupt__, auto_psv)) _INT1Interrupt(void)
{
    // Clear the external interrupt flag
    _INT0IF = 0;

    // Handle button press (increment a counter, for example)
    button_pressed++;
    if (button_pressed == 2) button_pressed = 0;
}

void RB7_interrupt_Init(void)
{
	// RB7 as input
	_TRISB7 = 1;
	
	// Config interrupt
	_INT0EP = 0;   // iNTERRUPT ON RISING EDGE
	_INT0IE = 1;   // Enable INT0 interrupt
	_INT0IP = 5;   // Interrupt priority between 0-7 
	
	

}	