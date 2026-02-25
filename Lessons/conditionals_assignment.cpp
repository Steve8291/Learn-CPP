# include <Arduino.h>

void clearBuffer() {
    while(Serial.available() > 0) Serial.read(); 
}

void setup() {
    Serial.begin(115200);
    delay(1000);
    clearBuffer();
    Serial.println("Enter your grade (0-100): ");
}


void loop() {
if (Serial.available() > 0) {
    String letterGrade;
    int grade = Serial.parseInt();









    // Print the new grade
    // Clear Serial Buffer
    // Ask for new grade
}