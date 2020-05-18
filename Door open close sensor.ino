#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(6, 7);  // Trig Pin to 6 & Echo Pin to 7
int distance;
int buzzer = 2;                                 // Connect Buzzer to Pin 2
int greenPin = 3;                               // Connect Green Leg of RGB LED to Pin 3
int redPin = 4;                                 // Connect Red Leg of RGB LED to Pin 4
int bluePin = 5;                                // Connect Blue Leg of RGB LED to Pin 5
int minDistance = 5;                            // Define minimum distnace in cm to turn ON the buzzer and RED LED
boolean alarm = false;
int i = 0;


void setup() {
  Serial.begin(9600);
  pinMode (buzzer, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (redPin, OUTPUT);
  pinMode (bluePin, OUTPUT);
}

void loop() {

  distance = (distanceSensor.measureDistanceCm());      //Measure distance from Ultrasonic sensor and assign distance value to int "distance"
  Serial.println (distance);                            //Print Distance to Serial Monitor
  delay (100);

  if (distance <= minDistance) {                         // If door is closed, Light = Green & Buzzer = ON
    digitalWrite(buzzer, LOW);
    digitalWrite (redPin, LOW);
    digitalWrite (greenPin, HIGH);
    digitalWrite (bluePin, LOW);
    i = 0;
  }

  if (distance > minDistance && i == 0) {                // If door is open, Light = Red & Alarm = ON
    alarm = true;
  }

  if (alarm == true) {                   
    digitalWrite (redPin, HIGH);
    digitalWrite (greenPin, LOW);
    digitalWrite (bluePin, LOW);
    
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    
    alarm = false;
    i = 1;
  }


  else {
  }

}
