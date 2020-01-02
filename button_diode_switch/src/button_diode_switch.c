#include <stdio.h>
#include <wiringPi.h>

#define ledPin 0
#define buttonPin 1

int main(void) {
  int light, button_pressed;
  light = 0;
  button_pressed = 0;
  if (wiringPiSetup() == -1) {
    printf("Setup wiringPi failed!\n");
    return 1;
  }

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  pullUpDnControl(buttonPin, PUD_UP);
  digitalWrite(ledPin, LOW);

  while (1) {
    if (digitalRead(buttonPin) == LOW) { // button pressed
      delay(100);
      if (light == 0) { // if light off
        digitalWrite(ledPin, HIGH);
        printf("led on...\n");
      } else { // if light on
        digitalWrite(ledPin, LOW);
        printf("...led off\n");
      }
      button_pressed = 1;
    } else if (button_pressed == 1) { // button released
      if (light == 0) {
        light = 1;
      } else {
        light = 0;
      }
      button_pressed = 0;
    }
  }

  return 0;
}
