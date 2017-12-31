#include <SoftwareSerial.h>

int right_wheel_fwd = 11;
int right_wheel_bckwd= 10;
int left_wheel_bckwd = 9;
int left_wheel_fwd = 8;

SoftwareSerial bluetooth(2,3);

void setup() {
  Serial.begin(9600);
  pinMode(left_wheel_fwd, OUTPUT);
  pinMode(left_wheel_bckwd, OUTPUT);
  pinMode(right_wheel_fwd, OUTPUT);
  pinMode(right_wheel_bckwd, OUTPUT);
  bluetooth.begin(9600);
  
}

void loop() {
  if(bluetooth.available()){
    char _buffer = bluetooth.read();  
    Serial.println(_buffer);
    if(_buffer == 'F'){
      Serial.println("Forward");
     forward();
    }else if(_buffer == 'B'){
      Serial.println("Backwards");
      backward();
    }else if(_buffer == 'R'){
      Serial.println("Right");
      right();
    }else if(_buffer == 'L'){
      Serial.println("left");
      left();
    }else{
      brake();
    }
  }
  delay(10);

}

void brake(){
  digitalWrite(right_wheel_fwd, HIGH);
  digitalWrite(right_wheel_bckwd, HIGH);
  digitalWrite(left_wheel_fwd, HIGH);
  digitalWrite(left_wheel_bckwd, HIGH);
}


void forward(){
  digitalWrite(right_wheel_fwd, HIGH);
  digitalWrite(right_wheel_bckwd, LOW);
  digitalWrite(left_wheel_fwd, HIGH);
  digitalWrite(left_wheel_bckwd, LOW);
}


void backward(){
  digitalWrite(right_wheel_fwd, LOW);
  digitalWrite(right_wheel_bckwd, HIGH);
  digitalWrite(left_wheel_fwd, LOW);
  digitalWrite(left_wheel_bckwd, HIGH);
}


void right(){
  digitalWrite(right_wheel_fwd, LOW);
  digitalWrite(right_wheel_bckwd, HIGH);
  digitalWrite(left_wheel_fwd, HIGH);
  digitalWrite(left_wheel_bckwd, LOW);
}


void left(){
  digitalWrite(right_wheel_fwd, HIGH);
  digitalWrite(right_wheel_bckwd, LOW);
  digitalWrite(left_wheel_fwd, LOW);
  digitalWrite(left_wheel_bckwd, HIGH);
}

