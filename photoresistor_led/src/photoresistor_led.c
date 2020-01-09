#include "pcf8591.h"
#include "softPwm.h"
#include "wiringPi.h"
#include <stdio.h>

#define address 0x48
#define pinbase 64
#define A0 pinbase + 0
#define A1 pinbase + 1
#define A2 pinbase + 2
#define A3 pinbase + 3

#define ledPin 0

int main(void) {
  int value;
  float voltage;
  if (wiringPiSetup() == -1) {
    printf("setup wiringPi falied!\n");
    return 1;
  }

  softPwmCreate(ledPin, 0, 100);
  pcf8591Setup(pinbase, address);

  while (1) {
    value = analogRead(A0);
    softPwmWrite(ledPin, value * 100 / 255);
    voltage = (float)value / 255.0 * 3.3;
    printf("ADC value: %d,\tVoltage: %.2fV\n", value, voltage);
    delay();
  }

  return 0;
}
