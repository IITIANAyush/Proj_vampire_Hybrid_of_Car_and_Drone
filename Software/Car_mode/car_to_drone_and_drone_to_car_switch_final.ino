#include <Servo.h>

// Define servo objects
Servo chassy1;
Servo wheel1;
Servo chassy2;
Servo wheel2;

// Position variables
int poschassy1; // Position of servo of chassy
int poswheel1; // Position of servo of wheel

// State variables
bool previousstate = 0;
bool currentstate;

void setup() {
  // Set pin modes for servos
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);

  // Set pin mode for switch
  pinMode(1, INPUT_PULLUP); // Use internal pull-up resistor

  // Detach all servos initially
  chassy1.detach();
  chassy2.detach();
  wheel1.detach();
  wheel2.detach();

  // Read initial switch state
  currentstate = digitalRead(1);
  previousstate = currentstate;

  // Perform initial actions based on the initial state
  if (currentstate == LOW) { // Switch pressed, initial drone mode
    droneMode();
  } else { // Switch not pressed, initial car mode
    carMode();
  }
}

void loop() {
  // Read current switch state
  currentstate = digitalRead(1);

  // Detect state change
  if (currentstate != previousstate) {
    previousstate = currentstate;

    // Perform actions based on the new state
    if (currentstate == LOW) { // Switch pressed, go to drone mode
      droneMode();
    } else { // Switch not pressed, go to car mode
      carMode();
    }
  }
}

void droneMode() {
  // Attach servos
  chassy1.attach(9);
  wheel1.attach(10);
  chassy2.attach(3);
  wheel2.attach(5);

  // Perform actions for drone mode
  for (poswheel1 = 90; poswheel1 > 0; poswheel1--) {
    wheel1.write(poswheel1);
    wheel2.write(180 - poswheel1);
    delay(20);
  }
  for (poschassy1 = 90; poschassy1 < 135; poschassy1++) {
    chassy1.write(poschassy1);
    chassy2.write(180 - poschassy1);
    delay(20);
  }
  for (poswheel1 = 0; poswheel1 < 45; poswheel1++) {
    wheel1.write(poswheel1);
    wheel2.write(180 - poswheel1);
    delay(20);
  }
  for (poschassy1 = 135; poschassy1 <= 180; poschassy1++) {
    chassy1.write(poschassy1);
    chassy2.write(180 - poschassy1);
    delay(20);
  }

  // Detach servos
  chassy1.detach();
  chassy2.detach();
  wheel1.detach();
  wheel2.detach();
}

void carMode() {
  // Attach servos
  chassy1.attach(9);
  wheel1.attach(10);
  chassy2.attach(3);
  wheel2.attach(5);

  // Perform actions for car mode
  for (poschassy1 = 180; poschassy1 > 135; poschassy1--) {
    chassy1.write(poschassy1);
    chassy2.write(180 - poschassy1);
    delay(20);
  }
  for (poswheel1 = 45; poswheel1 > 0; poswheel1--) {
    wheel1.write(poswheel1);
    wheel2.write(180 - poswheel1);
    delay(20);
  }
  for (poschassy1 = 135; poschassy1 > 90; poschassy1--) {
    chassy1.write(poschassy1);
    chassy2.write(180 - poschassy1);
    delay(20);
  }
  for (poswheel1 = 0; poswheel1 < 90; poswheel1++) {
    wheel1.write(poswheel1);
    wheel2.write(180 - poswheel1);
    delay(20);
  }

  // Detach servos
  chassy1.detach();
  chassy2.detach();
  wheel1.detach();
  wheel2.detach();
}
