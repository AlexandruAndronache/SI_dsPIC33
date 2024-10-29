#include "p33Fxxxx.h"

// Function declarations
void delay(int amount);

void delay(int amount)
{
	int i = 0;
	for (i; i < amount; i++){}
}
	


int main()
{
	TRISB = 0;
	int a = 7;
	
	while(1)
	{
		_LATB7 ^= 1;	
		delay(10);

		a = _RB7;
	}		
	
	
	
	return 0;
}