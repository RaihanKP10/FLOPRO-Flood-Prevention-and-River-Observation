/* By DzavanTS
 *  
 * OTA bisa diakses dengan Jaringan Internet yang sama pada hardware
 * dan Uploader
 * 
 * Untuk mengupload diakses pada alamat IP jaringan
 * Kemudian tambahkan "/update" pada alamat IP
 * 
 * Firmware didapatkan Melalui tool yang disediakan oleh Arduino IDE
 * dengan cara "Sketch>>Export compiled Binary"
 * maka akan sebuah file berformat .bin pada folder source code ini
 */
 
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ElegantOTA.h>

char ssid[] = "";       //SSID WIFI
char pass[] = "";       //Pasword WIFI

WebServer server(80);

bool sBlink;
unsigned long mBlink;

void setup() {
  Serial.begin (9600);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  WiFi.mode(WIFI_STA);
  Serial.printf("\nConnecting to : ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.printf("\nWiFi connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send(200, "text/plain", "Hi! This is ElegantOTA FLOPRO.");
  });
  ElegantOTA.begin(&server);
  server.begin();
}

void loop() {
  server.handleClient();
  ElegantOTA.loop();

  if(millis() - mBlink >= 1000){
    mBlink = millis();
    sBlink= !sBlink;
    digitalWrite(2, sBlink);
  }
}
