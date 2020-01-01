#include <wiringPi.h>
#include <signal.h>
#include <stdio.h>

#define ledPin 0

/* Signal Handler for SIGINT */
void sigintHandler(int signal) 
{ 
    digitalWrite(ledPin, LOW);
	printf("Turning off diode\n"); 
} 

int main(void)
{
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed!\n");
		return 1;
	}
	
	printf("wiringPi initialize successfully, GPIO %d(wiringPi pin)\n", ledPin);
	
	if(signal(SIGINT, sigintHandler) == SIG_ERR){
		printf("setup signal handler for Ctrl-C failed!\n");
		return 1;
	}
	
	printf("Setup signal handler for Ctrl-C succeded!\n");
	
	pinMode(ledPin, OUTPUT);
	
	while(1){
		digitalWrite(ledPin, HIGH);
		printf("led on...\n");
		delay(1000);
		digitalWrite(ledPin, LOW);
		printf("... led off\n");
		delay(1000);
	}
	
	return 0;
}
