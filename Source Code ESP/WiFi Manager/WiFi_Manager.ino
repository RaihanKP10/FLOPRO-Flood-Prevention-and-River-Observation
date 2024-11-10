/* By DzavanTS
 *  
 * Memasuki Mode Wifi Manager dapat dengan cara menekan push button
 * Kemudian nyalakan Wifi untuk menyambungkan ke WiFi ESP FLOPRO
 * Akan secara otomatis menuju ke web Configurasi WiFI
 * Setting Configurasi WiFi yang ingin disambungkan ke ESP lalu save
 * 
 * Jika tidak dapat menuju web Configurasi WiFi maka restart ESP
 * dan lakukan ulang langkahnya
 */
 
#include <WiFiManager.h>

#define SetWifi 22

int timeout = 120;
bool sBlink;
unsigned long mBlink;

void setup() {
  Serial.begin(9600);
  pinMode(SetWifi, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  WiFi.mode(WIFI_STA);
  Serial.printf("\nStarting WiFi Manager\n");
}

void loop() {
  configurasiWIFI();

  if(millis() - mBlink >= 1000){
    mBlink = millis();
    sBlink= !sBlink;
    digitalWrite(2, sBlink);
  }
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
    Serial.printf("\nWiFi connected to : ");
    Serial.println(wm.getWiFiSSID(true));
  }
}
