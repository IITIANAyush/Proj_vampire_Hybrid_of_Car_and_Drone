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

double ch1=6;
int a=8; int b=9;
 
double ch2=7;
int c=10; int d=11;

double ch6=12;
bool flag;

void setup() {
    Serial.begin(9600);
  pinMode(6,INPUT);
  pinMode(8,OUTPUT); pinMode(9,OUTPUT);
  
  pinMode(7,INPUT);
  pinMode(10,OUTPUT); pinMode(11,OUTPUT);

  pinMode(12,INPUT);
  
  // Set pin modes for servos
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // Set pin mode for switch

  // Detach all servos initially
  chassy1.detach();
  chassy2.detach();
  wheel1.detach();
  wheel2.detach();

  if(pulseIn(12,HIGH)<1100 && pulseIn(12,HIGH)>900){
    flag=0;
  }
  else{
    flag=1;
  }
  // Read initial switch state
  currentstate = flag;
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
    if(pulseIn(12,HIGH)<1100){
    flag=0;
  }
  else{
    flag=1;
  }
  currentstate = flag;

if(flag==1){
    ch1 = pulseIn(6,HIGH);
    ch2 = pulseIn(7,HIGH);

  if((ch1==0)&&(ch2==0))
  {     
  digitalWrite(a,LOW); digitalWrite(b,LOW);
  digitalWrite(c,LOW);digitalWrite(d,LOW);
  }

  else if((ch1>1530)&&(ch2>1530))
  {     
  digitalWrite(a,HIGH); digitalWrite(b,LOW);
  digitalWrite(c,LOW);digitalWrite(d,HIGH);    
  }

  else if((ch1>1530)&&(ch2<1460))
  { 
   digitalWrite(a,HIGH); digitalWrite(b,LOW);
  digitalWrite(c,HIGH);digitalWrite(d,LOW);    
  }

  else if((ch1<1460)&&(ch2>1530))
  {     
  digitalWrite(a,LOW); digitalWrite(b,HIGH);
  digitalWrite(c,LOW);digitalWrite(d,HIGH);
  }

  else if((ch1<1460)&&(ch2<1460))
  {  digitalWrite(a,LOW); digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);digitalWrite(d,LOW);
  
  }

else
{     
 digitalWrite(a,LOW); digitalWrite(b,LOW);
 digitalWrite(c,LOW);digitalWrite(d,LOW);
}
  }

  // Detect state change
if (currentstate != previousstate) {
    previousstate = currentstate;

    // Perform actions based on the new state
    if (currentstate == 0) { // Switch pressed, go to drone mode
      droneMode();
    } else { // Switch not pressed, go to car mode
      carMode();
      
     }
  }
}

void droneMode() {
  // Attach servos
  chassy1.attach(2);
  wheel1.attach(3);
  chassy2.attach(4);
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
  chassy1.attach(2);
  wheel1.attach(3);
  chassy2.attach(4);
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
