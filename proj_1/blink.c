/*
** Based on the Frenove tutorials, items subject to change
*/
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define ledPin 0 // LED PIN DEFINITION

int main(void) {
  printf("Program Starting!\n");
  wiringPiSetup();
  // Set pin to output
  pinMode(ledPin, OUTPUT);
  printf("Using pin:%d\n", ledPin);
  while (1) {
    digitalWrite(ledPin, HIGH);
    printf("led turned on >>>\n");
    delay(1000);
    digitalWrite(ledPin, LOW);
    printf("led turned off <<<\n");
    delay(1000);
  }

  return EXIT_SUCCESS;
}
