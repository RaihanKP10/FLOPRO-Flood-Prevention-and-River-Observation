#include <WiFi.h>
#include <MQTT.h>
#include <ESP32_Servo.h>

// Konfigurasi WiFi dan MQTT
const char ssid[] = "helloguys"; //SSID WiFi
const char pass[] = "11111111";  //Password WiFi
const char* mqtt_server = "broker.hivemq.com"; //MQTT Broker
const char* client_id = "Flopro IOT"; //Client ID

#define Echo 16
#define Trigger 17
#define pServo 23
#define Sound 18
#define Batt 35

Servo servo;

float rBatt, vBatt;
float Durasi, Jarak;
int jMin = 7, jMid = 15, jMax = 140;
unsigned long mSonik, mSerial, mSound;

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void connect() {
  Serial.print("Checking WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nConnecting to MQTT...");
  while (!client.connect(client_id)) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nConnected to MQTT!");
}

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Sound, OUTPUT);
  pinMode(Batt, INPUT);
  digitalWrite(Sound, LOW);
  
  servo.attach(pServo);
  servo.write(0);

  WiFi.begin(ssid, pass);

  client.begin(mqtt_server, net);
  connect();
}

void loop() {
  client.loop();

  rBatt= (analogRead(Batt) + 88) * 3.33 / 4095;
  vBatt= rBatt * (560 + 220) / 560;
  Serial.print(vBatt);
  client.publish("odypens/vbatt", String(vBatt));
  
  if (millis() - mSonik >= 50) {
    mSonik = millis();
    BacaSensor();
  }

  if (millis() - mSerial >= 1000) {
    mSerial = millis();
    Serial.println("Jarak: " + String(Jarak) + " cm");
    client.publish("odypens/jarak", String(Jarak));
  }

  if (Jarak < jMin) {
    servo.write(180);
    Serial.println("Servo aktif: 180 derajat");
    digitalWrite(Sound, HIGH);
    Serial.println("Sound aktif");
    client.publish("odypens/servo", "180");
    delay(100);
    digitalWrite(Sound, LOW);
    Serial.println("Sound mati");
  } else if (Jarak >= jMin && Jarak <= jMid) {
    if (millis() - mSound >= 5000) {
      mSound = millis();
      digitalWrite(Sound, HIGH);
      Serial.println("Sound aktif");
      client.publish("odypens/sound", "HIGH");
      delay(100);
      digitalWrite(Sound, LOW);
      Serial.println("Sound mati");
    }
  } else {
    servo.write(0);
    Serial.println("Servo mati: 0 derajat");
    client.publish("odypens/servo", "0");
    digitalWrite(Sound, LOW);
    Serial.println("Sound mati");
  }

  if (!client.connected()) {
    connect();
  }

  delay(10);
}

void BacaSensor() {
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  Durasi = pulseIn(Echo, HIGH);
  Jarak = Durasi * 0.034 / 2;
  if (Jarak > jMax) Jarak = jMax;
}
