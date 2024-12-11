// Vision Camera
static int CAMERA_CENTER_X;
static int CAMERA_CENTER_Y;
static int TARGET_X;
static int TARGET_Y;
bool TARGET_CENTERED = false;
#define VISION_ERROR_MARGIN 1
Pixy2 pixy; // Pixy2 camera object

// Turret Servos
#define pitch_pin 10
Servo PITCH_SERVO;
static int PITCH_POS = 60;
const int CENTER = 40;

// Loading Stepper Motor
#define dirPin 2
#define stepPin 3
const int stepsPerRevolution = 750;
int stepDelay=2000;

// Flywheel Motors
#define relay_pin 7
#define drive_pin 8
