#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "nodemcu-7b097.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "zzLciPt50kzo2w7zt7QU7DQW2omCRWYh9mUJxHMA"
#define WIFI_SSID "Tenda_026AF8"
#define WIFI_PASSWORD "999999999"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop() {
  int n = 0;
  String data = "";

  while(Serial.available()>0)
  {
   data += char(Serial.read()); 
  }
   // set valuen
  Firebase.setString("data_sensor", data);
  // handle error
  if (Firebase.failed()) {
      Serial.print("data gagal di input ke firebase");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.println(data);
  delay(3000);
} 
