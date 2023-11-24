#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

int dist = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop()
{
  lcd.clear();
  dist = 0.01723 * readUltrasonicDistance(A0, A0);
  Serial.println(dist);
  if (dist < 300) {
    lcd.print("Perigo");
    digitalWrite(7, HIGH);
  } else {
    lcd.print("Seguro");
    digitalWrite(7, LOW);
  }
  delay(500);
}
