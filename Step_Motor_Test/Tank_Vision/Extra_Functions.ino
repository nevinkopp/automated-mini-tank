// Turret vision and servo setup
void TurretSetup(){
  pixy.init();
  pixy.changeProg("color_connected_components");
  CAMERA_CENTER_X = (int)pixy.frameWidth/2 - 30;
  
  PITCH_SERVO.attach(pitch_pin);
  PITCH_SERVO.write(PITCH_POS);

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

// Update the pitch and yaw servos constrained to 0-180
void UpdateServos(){
  PITCH_POS = constrain(PITCH_POS, CENTER-30, CENTER+30);
  PITCH_SERVO.write(PITCH_POS);
}

// Turret action
void TurretAction(){
  pixy.ccc.getBlocks(); // Look for target
  Serial.println(PITCH_POS);
  UpdateServos();

  // If target found enter alignment
  if(pixy.ccc.getBlocks() > 0){
    AlignTurret();
    if(TARGET_CENTERED){
      Fire();
    }
  }
  // If no target found, re-center the turret
  else{
    PITCH_POS = CENTER;
  }
}

// Align turret with detected target
void AlignTurret(){
  // Determine location of target
  TARGET_X = pixy.ccc.blocks[0].m_x;
  int dx = TARGET_X - CAMERA_CENTER_X;

  // Target is to the right
  if(dx > 0){
    PITCH_POS -= 1;
  }
  // Target is to the left
  else if(dx < 0){
    PITCH_POS += 1;
  }

  // If within error margin box for the target
  if(abs(dx) < VISION_ERROR_MARGIN){
    Serial.println("CENTERED");
    TARGET_CENTERED = true;
  }
  else{
    TARGET_CENTERED = false;
  }
}

void Fire(){
  // FIRE A ROUND (1.5 second delaying function)
  Serial.println("FIRE");
  TARGET_CENTERED = false;

  // STOP DRIVETRAIN
  digitalWrite(drive_pin, HIGH);

  // TURN ON FLYWHEEL HERE
  digitalWrite(relay_pin, HIGH);

  // Rechamber round
  digitalWrite(dirPin, HIGH);
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
  }
  
  // Load ball into flywheel
  digitalWrite(dirPin, LOW);
  for(int x = 0; x < stepsPerRevolution*2; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
  }

  
  // STOP FLYWHEEL HERE
  digitalWrite(relay_pin, LOW);


  // Reset loading mechanism
  digitalWrite(dirPin, HIGH);
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
  }

  // RESTART DRIVETRAIN
  digitalWrite(drive_pin, LOW);
}
