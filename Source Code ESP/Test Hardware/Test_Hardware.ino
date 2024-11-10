#include <ESP32_Servo.h>

#define Echo 16
#define Trigger 17
#define pServo 23
#define Sound 18
#define Batt 35

Servo servo;

float Durasi, Jarak, rBatt, vBatt;
int jMin= 10, jMid= 20, jMax= 350;
bool sBlink;
unsigned long mSonik, mSerial, mSound, mBlink;

void BacaSensor(){
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  Durasi = pulseIn(Echo, HIGH);
  Jarak = Durasi * 0.034 / 2;
  if(Jarak > jMax) Jarak= jMax;
}

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Sound, OUTPUT);
  pinMode(Batt, INPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(Sound, LOW);
  servo.attach(pServo);
  servo.write(0);
}

void loop() {
  rBatt= (analogRead(Batt) + 88) * 3.33 / 4095;
  vBatt= rBatt * (560 + 220) / 560;
    
  if(millis() - mBlink >= 1000){
    mBlink = millis();
    sBlink= !sBlink;
    digitalWrite(2, sBlink);
  }
  if(millis() - mSonik >= 50){
    mSonik = millis();
    BacaSensor();
  }
  if(millis() - mSerial >= 1000){
    mSerial = millis();
    Serial.println("Jarak: " + String(Jarak) + " cm");
    Serial.println("Baterai: " + String(vBatt) + " V");
  }
  if(Jarak < jMin){
    servo.write(180);
    digitalWrite(Sound, HIGH);
    digitalWrite(Sound, LOW);
    Serial.println("Alarm");
  }
  else if(Jarak >= jMin && Jarak <= jMid){
    if(millis() - mSound >= 5000){
      mSound = millis();
      digitalWrite(Sound, HIGH);
      digitalWrite(Sound, LOW);
    }
  }
  else{
    servo.write(0);
    digitalWrite(Sound, LOW);
  }
}
