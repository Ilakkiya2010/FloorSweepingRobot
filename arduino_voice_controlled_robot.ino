
#include <Servo.h>
#include <AFMotor.h>
#include <Servo.h>

String command;
// AF_DCMotor motor1(1 );
// AF_DCMotor motor2(2 );
// AF_DCMotor motor3(3 );
// AF_DCMotor motor4(4 );

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

Servo myservo;
int j;



void setup() {
  
Serial.begin(9600);
myservo.attach(10);
myservo.write(90);

}

void loop() {

 delay(10);
 while(Serial.available()) {
  command = "";  
  command = Serial.readString();
  
    Serial.print(command);
}
  if (command == "*start clean#" || command == "*Start clean#" || command == "*start Clean#") { 
    clean();
  
    }
  else 
  if(command == "*move forward#" || command == "*Move forward#" ){
    forward();
  }else if(command == "*move backward#" || command == "*Move backward#"){
    backward();
  }else if(command == "*turn left#" || command == "*Turn left#"){
    left();
  }else if(command == "*turn right#" || command == "*Turn right#"){
    right();
  }else if(command == "*stop#" ||command == "*Stop#" ) {
    stop();
 }
  command = "";
}
void clean(){
  j =0;
  while (j <5){
    j = j + 1 ;
  // move forward
  forward();
  backward();
  minibackward();
  // turn left 
  left();
  //turn right
  right();
  
  }
  forward();
  
  //turn right
  right();
  right();
  right();
  right();
  right();

   
}
void forward() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
}

void backward() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
}

void minibackward() {
  motor1.setSpeed(55);
  motor1.run(BACKWARD);
  motor2.setSpeed(55);
  motor2.run(BACKWARD);
  motor3.setSpeed(55);
  motor3.run(BACKWARD);
  motor4.setSpeed(55);
  motor4.run(BACKWARD);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
}


void left() {
  myservo.write(180);
  delay(500);
  myservo.write(90);
  delay(500);
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(500);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(500);
  motor4.run(FORWARD);
  delay(300);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void right() {
  myservo.write(0);
  delay(500);
  myservo.write(90);
  delay(500);
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(500);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(500);
  motor4.run(BACKWARD);
  delay(300);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);


}

void stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
