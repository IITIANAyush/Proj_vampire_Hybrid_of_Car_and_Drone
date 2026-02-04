
// Pin definitions
const int ch1Pin = 2; // CH1 signal pin
const int ch2Pin = 3; // CH2 signal pin
const int ENA = 5;
const int ENB = 6;
const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 9;
const int IN4 = 10;

// Variables to store pulse duration
volatile int ch1Value = 1500;
volatile int ch2Value = 1500;

void setup() {
  // Initialize motor control pins
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialize receiver input pins
  pinMode(ch1Pin, INPUT);
  pinMode(ch2Pin, INPUT);

  // Attach interrupts for channel signals
  attachInterrupt(digitalPinToInterrupt(ch1Pin), ch1ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ch2Pin), ch2ISR, CHANGE);
}

void loop() {
  // Map receiver values to motor speed and direction
  int speed = map(ch1Value, 1000, 2000, -255, 255);
  int turn = map(ch2Value, 1000, 2000, -255, 255);

  // Calculate motor speeds
  int leftMotorSpeed = speed + turn;
  int rightMotorSpeed = speed - turn;

  // Constrain motor speeds to -255 to 255
  leftMotorSpeed = constrain(leftMotorSpeed, -255, 255);
  rightMotorSpeed = constrain(rightMotorSpeed, -255, 255);

  // Control motors
  setMotorSpeed(leftMotorSpeed, rightMotorSpeed);

  delay(20);
}

void setMotorSpeed(int leftSpeed, int rightSpeed) {
  // Left motor control
  if (leftSpeed >= 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, leftSpeed);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, -leftSpeed);
  }

  // Right motor control
  if (rightSpeed >= 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, rightSpeed);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, -rightSpeed);
  }
}

// Interrupt Service Routine for CH1
void ch1ISR() {
  static unsigned long startTime;
  if (digitalRead(ch1Pin) == HIGH) {
    startTime = micros();
  } else {
    ch1Value = micros() - startTime;
  }
}

// Interrupt Service Routine for CH2
void ch2ISR() {
  static unsigned long startTime;
  if (digitalRead(ch2Pin) == HIGH) {
    startTime = micros();
  } else {
    ch2Value = micros() - startTime;
  }
}
