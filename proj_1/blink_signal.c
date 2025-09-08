/* TODO
** Based on the Frenove tutorials, items subject to change
*/
#include <signal.h> // For handling ^C to end
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define ledPin 0 // LED PIN DEFINITION

// Handle signals
static void handler(int signum) {
  printf("Catching %d\n", signum);
  printf("Exiting program turning signal low!\n");
  digitalWrite(ledPin, LOW);
  exit(signum);
}

int main(void) {
  // Replace the signal handler with our own!
  signal(SIGINT, handler);
  printf("Program Starting!\n");
  wiringPiSetup();
  // Set pin to output
  pinMode(ledPin, OUTPUT);
  printf("Using pin:%d\n", ledPin);
  while (1) {
    digitalWrite(ledPin, HIGH);
    printf("led turned on!\n");
    delay(1000);
    digitalWrite(ledPin, LOW);
    printf("led turned off!\n");
    delay(1000);
  }

  return EXIT_SUCCESS;
}
