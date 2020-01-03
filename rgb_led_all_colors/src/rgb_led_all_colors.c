#include "softPwm.h"
#include "wiringPi.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#define ledPinRed 0
#define ledPinGreen 1
#define ledPinBlue 2

/* Signal Handler for SIGINT */
void sigintHandler(int signal) {
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  digitalWrite(ledPinRed, HIGH);
  digitalWrite(ledPinGreen, HIGH);
  digitalWrite(ledPinBlue, HIGH);
  printf("Turning off diode\n");
  exit(1);
}

void setupLedPin(void) {
  softPwmCreate(ledPinRed, 0, 255);
  softPwmCreate(ledPinGreen, 0, 255);
  softPwmCreate(ledPinBlue, 0, 255);
}

void setLedColor(int r, int g, int b) {
  softPwmWrite(ledPinRed, r);
  softPwmWrite(ledPinGreen, g);
  softPwmWrite(ledPinBlue, b);
}

int main(void) {
  int r, g, b;

  printf("Program is starting...\n");

  if (wiringPiSetup() == -1) {
    printf("setup wiringPi failed!\n");
    return 1;
  }

  if (signal(SIGINT, sigintHandler) == SIG_ERR) {
    printf("setup signal handler for Ctrl-C failed!\n");
    return 1;
  }

  setupLedPin();

  while (1) {
    for (r = 0; r < 255; ++r) {
      for (g = 0; g < 255; ++g) {
        for (b = 0; b < 25; ++b) {
          setLedColor(r, g, b);
          printf("r=%d, g=%d, b=%d\n", r, g, b);
          delay(300);
        }
      }
    }
  }

  return 0;
}
