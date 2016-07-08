/*
 * Author: Michael Hamann
 * Date: 08 July 2016
 * Purpose: Buzzer & LED output depending on distance detected
 * 
 */

const int trigPin = 7; //Sonar Out
const int echoPin = 6; //Sonar In
const int led_1 = 8; //green LED
const int led_2 = 9; //orange LED
const int led_3 = 10; //red LED
const int buzz = 11; //Buzzer

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  tone(buzz, 0);
  int dist = getDistance();

  if (dist > 40) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    tone(buzz, 500, 500);

  }

  if (dist > 20 && dist < 40) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);
    tone(buzz, 1500, 500);

  }

  if (dist < 20) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    tone(buzz, 2500, 500);
  }

}

int getDistance() {

  long duration, distance;

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) / 29.1;

  return distance;

}
