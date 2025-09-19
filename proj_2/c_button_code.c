#include "c_button.h"
#include <stdio.h>
#include <stdlib.h>
#include "wiringPi.h"

// This is how to fortran code operates in terms of C.
// Button is PRESSED on LOW, so define a clarity. PRESSED_LOW.
#define PRESSED LOW

int main(void){
  printf("Program Starting!\n");
  wiringPiSetup();
  // Board logic
  // Set ledPin to be output
  pinMode(ledPin, OUTPUT);
  // set button pin to be input
  pinMode(buttonPin, INPUT);
  printf("Using led pin:%d and button pin: %d\n", ledPin, buttonPin);
  while (1) {
      if(digitalRead(buttonPin) == PRESSED){
          // Turn on the LED
          digitalWrite(ledPin, HIGH);
          printf("Button was pressed, LED is ON!");
      }
      else{
          digitalWrite(ledPin, LOW);
          printf("Button was released, LED is OFF!");
      }
  }
  // Never reached
  // There is no signal handler in this code!
  return EXIT_SUCCESS;
}
