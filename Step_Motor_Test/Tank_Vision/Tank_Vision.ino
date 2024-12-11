#include <Servo.h>
#include <Pixy2.h> // Pixy2 camera library
#include "Global_Variables.h"

void setup(){
  // Setup vision sensor and pitch/yaw servos
  TurretSetup();
  Serial.begin(9600);
  pinMode(relay_pin, OUTPUT);
  pinMode(drive_pin, OUTPUT);
  digitalWrite(drive_pin, LOW);
  delay(5000);
}

void loop(){
  TurretAction();
}
