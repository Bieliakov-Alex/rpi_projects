#include <stdio.h>
#include <wiringPi.h>

#define buttonPin 7

int main(void) {
  if (wiringPiSetup() == -1) {
    printf("Setup wiringPi failed!\n");
    return 1;
  }

  pinMode(buttonPin, INPUT);

  pullUpDnControl(buttonPin, PUD_UP);

  while (1) {
    if (digitalRead(buttonPin) == HIGH) {
      printf("HIGH\n");
    } else {
      printf("Low\n");
    }
  }

  return 0;
}
