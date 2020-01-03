#include "wiringPi.h"
#include <stdio.h>

#define busserPin 0
#define buttonPin 1

int main(void) {
  printf("Program is starting... \n");

  if (wiringPiSetup() == -1) {
    printf("setup wiringPi failed!\n");
    return 1;
  }

  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  pullUpDnControl(buttonPin, PUD_UP);
  while (1) {
    if (digitalRead(buttonPin) == LOW) {
      digitalWrite(buzzerPin, HIGH);
      printf("buzzer turned on >>>\n");
    } else {
      digitalWrite(buzzerPin, LOW);
      printf("buzzer turned off <<<\n");
    }
  }
}
