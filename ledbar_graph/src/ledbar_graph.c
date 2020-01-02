#include "wiringPi.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#define ledCounts 10
int pins[ledCounts] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10};

/* Signal Handler for SIGINT */
void sigintHandler(int signal) {
  int i;
  for(i = 0; i < ledCounts; ++i) {
    digitalWrite(pins[i], LOW);
  }
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

  for (i = 0; i < ledCounts; ++i) {
    pinMode(pins[i], OUTPUT);
  }

  while (1) {
    for (i = 0; i < ledCounts; ++i) {
      digitalWrite(pins[i], LOW);
      delay(100);
      digitalWrite(pins[i], HIGH);
    }

    for (i = ledCounts - 1; i > -1; --i) {
      digitalWrite(pins[i], LOW);
      delay(100);
      digitalWrite(pins[i], HIGH);
    }
  }

  return 0;
}
