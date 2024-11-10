#include <ESP32_Servo.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ElegantOTA.h>
#include <WiFiManager.h>
#include <MQTT.h>

#define Echo 16
#define Trigger 17
#define pServo 23
#define Sound 18
#define Batt 35
#define SetWifi 22

char ssid[32], pass[64];
const char* mqtt_server = "broker.hivemq.com";
const char* client_id = "Flopro IOT";

WiFiClient net;
MQTTClient client;
WebServer server(80);
Servo servo;

float Durasi, Jarak, rBatt, vBatt;
int jMin= 10, jMid= 20, jMax= 350;
int timeout = 120;
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

void getSSIDPASW(){
  WiFiManager wm;
  String sssid = wm.getWiFiSSID(true);
  String spass = wm.getWiFiPass(true);
  sssid.toCharArray(ssid, sizeof(ssid));
  spass.toCharArray(pass, sizeof(pass));
}

void configurasiWIFI(){
  if(digitalRead(SetWifi) == LOW){
    digitalWrite(2, HIGH);
    WiFiManager wm;
    wm.resetSettings();
    wm.setConfigPortalTimeout(timeout);
    if (!wm.startConfigPortal("FLOPRO")) {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      ESP.restart();
    }
    getSSIDPASW();
    Serial.printf("\nWiFi connected to : ");
    Serial.println(ssid);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Sound, OUTPUT);
  pinMode(Batt, INPUT);
  pinMode(SetWifi, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(Sound, LOW);
  servo.attach(pServo);
  servo.write(0);

  WiFi.mode(WIFI_STA);
  getSSIDPASW();
  Serial.printf("\nConnecting to : ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    configurasiWIFI();
  }
  Serial.printf("\nWiFi connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  client.begin(mqtt_server, net);
  server.on("/", []() {
    server.send(200, "text/plain", "Hi! This is ElegantOTA FLOPRO.");
  });
  ElegantOTA.begin(&server);
  server.begin();
}

void loop() {
  configurasiWIFI();
  client.loop();
  server.handleClient();
  ElegantOTA.loop();
  
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
    client.publish("odypens/jarak", String(Jarak));
    client.publish("odypens/vbatt", String(vBatt));
  }
  if(Jarak < jMin){
    servo.write(180);
    digitalWrite(Sound, HIGH);
    digitalWrite(Sound, LOW);
    Serial.println("Alarm");
    client.publish("odypens/servo", "Pintu Air Terbuka");
  }
  else if(Jarak >= jMin && Jarak <= jMid){
    if(millis() - mSound >= 5000){
      mSound = millis();
      digitalWrite(Sound, HIGH);
      digitalWrite(Sound, LOW);
      client.publish("odypens/sound", "Alarm Berbunyi");
    }
  }
  else{
    servo.write(0);
    digitalWrite(Sound, LOW);
    client.publish("odypens/servo", "Pintu Air Tertutup");
  }
}
