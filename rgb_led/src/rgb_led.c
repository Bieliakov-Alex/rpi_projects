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
  softPwmCreate(ledPinRed, 0, 100);
  softPwmCreate(ledPinGreen, 0, 100);
  softPwmCreate(ledPinBlue, 0, 100);
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
    r = random() % 100;
    g = random() % 100;
    b = random() % 100;
    setLedColor(r, g, b);
    printf("r=%d, g=%d, b=%d\n", r, g, b);
    delay(300);
  }

  return 0;
}
