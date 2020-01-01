#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0
#define buttonPin 1

int main(void)
{
	if(wiringPiSetup() == -1){
		printf("Setup wiringPi failed!\n");
		return 1;
	}
	
	pinMode(ledPin, OUTPUT);
	pinMode(buttonPin, INPUT);
	
	pullUpDnControl(buttonPin, PUD_UP);
	
	while(1){
		if(digitalRead(buttonPin) == LOW){
			digitalWrite(ledPin, HIGH);
			printf("led on...\n");
		}
		else{
			digitalWrite(ledPin, LOW);
			printf("...led off\n");
		}
	}
	
	return 0;
}