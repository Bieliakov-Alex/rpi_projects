#include "wiringPi.h"
#include <stdio.h>

#define ledPin 1

/* Signal Handler for SIGINT */
void sigintHandler(int signal) {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  printf("Turning off diode\n");
  exit(1);
}

int main(void) {
  int i;

  printf("Program is starting...\n");

  if (wiringPiSetup() == -1) {
    printf("setup wiringPi failed!\n");
    return 1;
  }

  if (signal(SIGINT, sigintHandler) == SIG_ERR) {
    printf("setup signal handler for Ctrl-C failed!\n");
    return 1;
  }

  pinMode(ledPin, PWM_OUTPUT)

  while (1) {
    for (i = 0; i < 100; ++i) {
      pwmWrite(ledPin, i*10);
      delay(20);
    }

    delay(300);

    for (i = 100; i >= 0; --i) {
      pwmWrite(ledPin, i*10);
      delay(20);
    }
    delay(300);
  }
}
