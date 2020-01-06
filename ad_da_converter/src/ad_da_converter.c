#include "pcf8591.h"
#include "wiringPi.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#define address 0x48
#define pinbase 64
#define A0 pinbase + 0
#define A1 pinbase + 1
#define A2 pinbase + 2
#define A3 pinbase + 3

/* Signal Handler for SIGINT */
void sigintHandler(int signal) {
  analogWrite(pinbase + 0, 0);
  printf("Turning off diode\n");
  exit(1);
}

int main(void) {
  int value;
  float voltage;

  if (wiringPiSetup() == -1) {
    printf("setup wiringPi failed!\n");
    return 1;
  }

  if (signal(SIGINT, sigintHandler) == SIG_ERR) {
    printf("setup signal handler for Ctrl-C failed!\n");
    return 1;
  }

  pcf8591Setup(pinbase, address);

  while (1) {
    value = analgRead(A0);
    analogWrite(pinbase + 0, value);
    voltage = (float)value / 255.0 * 3.3;
    printf("ADC value: %d, \tVoltage: %.2fV\n", value, voltage);
    delay(100);
  }

  return 0;
}
