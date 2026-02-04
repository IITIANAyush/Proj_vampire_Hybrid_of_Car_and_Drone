#include <Servo.h>

Servo chassy1;
Servo chassy2;
Servo wheel1;
Servo wheel2;
int poschassy1;
int poschassy2=180-poschassy1;
int poswheel1;
int poswheel2=180-poswheel1;

void setup() {
  pinMode(9,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(A0,INPUT);
  chassy1.attach(9);
  chassy2.attach(3);
  wheel1.attach(10);
  wheel2.attach(5);//wheel1 and wheel2 are aligned
}

void loop() {
  //lets code for any orientation coming to drone 
  //initially carmode - every servo at 90 deg 
  for(poswheel1=90;poswheel1>0;poswheel1--){
    wheel1.write(poswheel1);
    wheel2.write(180-poswheel1);
    delay(20);
  }

  for(poschassy1=90;poschassy1<135;poschassy1++){
    chassy1.write(poschassy1);
    chassy2.write(180-poschassy1);
    delay(20);
  }
  for(poswheel1=0;poswheel1<45;poswheel1++){
    wheel1.write(poswheel1);
    wheel2.write(180-poswheel1);
    delay(20);
  }
  wheel1.detach();
  wheel2.detach();
  for(poschassy1=135;poschassy1<180;poschassy1++){
    chassy1.write(poschassy1);
    chassy2.write(180-poschassy1);
    delay(20);
  }
  chassy1.detach();
  chassy2.detach();
  
  return;
}
