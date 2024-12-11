#include <AFMotor.h>
#include "Global_Variables.h"

void setup() {
  // Set default speed of each motor (0-255)
  L_motor1.setSpeed(DRIVE_SPEED-50);
  L_motor2.setSpeed(DRIVE_SPEED-50);
  R_motor1.setSpeed(DRIVE_SPEED);
  R_motor2.setSpeed(DRIVE_SPEED);

  // Initialize bluetooth telemetry
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(drive_pin) == 0){
    BluetoothDrive();
  }
//
//BluetoothDrive();
}
