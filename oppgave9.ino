#include <Servo.h>

const int servoPin = 10;
const int potPin = A0;

const int EN1 = 11;
const int IN1 = 12;
const int IN2 = 13;

Servo servo;

int read_value = 0;

void setup() {
  servo.attach(servoPin);  
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  read_value = analogRead(potPin);
  if (read_value < 462){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(EN1, map(read_value, 461, 0, 100, 200));
    servo.write(map(read_value, 461, 0, 90, 0));
  } else if (read_value < 563){
    servo.write(90);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(EN1, 0);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(EN1, map(read_value, 563, 1023, 100, 200));
    servo.write(map(read_value, 563, 1023, 90, 180));
  }
}
