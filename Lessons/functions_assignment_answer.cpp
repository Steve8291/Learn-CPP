/* Assignment: Traffic Light
Build a traffic light controller using functions. 
The traffic light should cycle through green, yellow, and red lights with appropriate delays. 
Use functions to represent each light state and the transitions between them. For example:
    void greenLight() {
        // Code to turn on green light
        delay(5000); // Green light for 5 seconds
    }
*/

# include <Arduino.h>

// Define Pins
const int RED = 32;
const int YELLOW = 33;
const int GREEN = 25;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

// A function that activates the light with a 2 parameters: 'light_pin' and 'duration'
// This replaces repeating digitalWrite(pin, HIGH) everywhere
// It should have a delay for the duration of the light, then turn it off
// This function should be able to work for any light color and duration, so it needs parameters
void activateLight(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
}

// A caution flash function that flashes the yellow light a certain number of times, with a delay in between
// This function should call your previous function (Abstraction)
// It should take in a parameter for how many times to flash
// Use a for loop to repeat the flashing the correct number of times
//  for(int i = 0; i < flashes; i++)
void cautionFlash(int flashes) {
  for(int i = 0; i < flashes; i++) {
    digitalWrite(YELLOW, HIGH);
    delay(300);
    digitalWrite(YELLOW, LOW);
    delay(300);
  }
}

void loop() {
    // In your loop, call the function to activate each light in the correct order with the correct durations.
    // Then call the caution flash function before the loop repeats to add a blinking yellow light between cycles.
  // Now your loop is easy to read!
  activateLight(GREEN, 5000);  // Green for 5 seconds
  activateLight(YELLOW, 2000); // Yellow for 2 seconds
  activateLight(RED, 5000);    // Red for 5 seconds
  
  cautionFlash(3);             // Blink yellow 3 times before restarting
}