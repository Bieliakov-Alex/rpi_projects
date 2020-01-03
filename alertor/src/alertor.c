#include "softTone.h"
#include "wiringPi.h"
#include <math.h>
#include <stdio.h>

#define buzzerPin 0
#define buttonPin 1

void alertor(int pin) {
  int x;
  double sinVal, toneVal;
  for (x = 0; x < 360; ++x) {
    sinVal = sin(x * (M_PI / 180));
    toneVal = 2000 + sinVal * 500;
    softToneWrite(pin, toneVal);
    delay(1);
  }
}

void stopAlertor(int pin) { softToneWrite(pin, 0); }

int main(void) {
  printf("Program is starting...\n");

  if (wiringPiSetup() == -1) {
    printf("setup wiringPi failed!\n");
    return 1;
  }

  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  softToneCreate(buzzerPin);
  pullUpDnControl(buttonPin, PUD_UP);
  while (1) {
    if (digitalRead(buttonPin) == LOW) {
      alertor(buzzerPin);
      printf("alertor turned on >>>\n");
    } else {
      stopAlertor(buzzerPin);
      printf("alertor turned off <<<\n");
    }
  }

  return 0;
}
