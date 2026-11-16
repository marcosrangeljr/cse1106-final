#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#define PIN 17

int main()
{
	float temp;
	int choice;
	int exit = 0;
	int LOWER = 68;
	int UPPER = 76;
	
	gpioInitialise();
	gpioSetMode(PIN,PI_OUTPUT);
	
	while (exit == 0) {
		
	printf("Choice 1- Tempature Change\nChoise 2- Tempature Input\nChoice 3- Exit\nChoice: ");
	scanf("%d", &choice);
	
	
	if (choice == 2){
	
	printf ("Enter Tempature: ");
	scanf("%f", &temp);
	
	if (temp < 68 || temp > 76)
	{
		puts("WARNING!");
		gpioWrite(PIN, 1); //LED ON & Warning
	}
	else
	{
		puts("NORMAL!");
		gpioWrite(PIN, 0); //Led off & Normal
	}		
	}
	else if (choice == 1) {
		printf("Enter lower range: ");
		scanf("%d", &LOWER);
		printf("Enter upper range: ");
		scanf("%d", &UPPER);
	} else if (choice == 3) {
		exit = 1;
	} else {
		puts("Wrong choice!");
	}
} 
	gpioWrite(PIN, 0);
	gpioTerminate();
	
	return 0;
	
}
	
