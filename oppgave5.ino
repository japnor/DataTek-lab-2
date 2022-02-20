const int EN1 = 11;
const int IN1 = 12;
const int IN2 = 13;
const int tiltPin = 2;

int read_value = 0;

void setup() {
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(tiltPin, INPUT);
}

void loop() {
  if (digitalRead(tiltPin) == HIGH){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(EN1, 55);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(EN1, 0);
  }
}
