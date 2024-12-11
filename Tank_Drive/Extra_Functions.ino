void BluetoothDrive(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Serial.println(command);
    switch(command){
      case 'F':  
        Serial.println("forward");
        L_motor1.run(FORWARD);
        L_motor2.run(FORWARD);
        R_motor1.run(FORWARD);
        R_motor1.run(FORWARD);
        break;
      case 'B':  
        L_motor1.run(BACKWARD);
        L_motor2.run(BACKWARD);
        R_motor1.run(BACKWARD);
        R_motor1.run(BACKWARD);
        break;
      case 'L':  
        L_motor1.run(BACKWARD);
        L_motor2.run(BACKWARD);
        R_motor1.run(FORWARD);
        R_motor1.run(FORWARD);
        break;
      case 'R':
        L_motor1.run(FORWARD);
        L_motor2.run(FORWARD);
        R_motor1.run(BACKWARD);
        R_motor1.run(BACKWARD);
        break;
      case 'S':
        L_motor1.run(RELEASE);
        L_motor2.run(RELEASE);
        R_motor1.run(RELEASE);
        R_motor1.run(RELEASE);
    }
  } 
}
