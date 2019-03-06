
#include <ESP8266WiFi.h>

#include <FirebaseArduino.h>
#include <SoftwareSerial.h>
SoftwareSerial s(D6,D5);
// Set these to run example.
#define FIREBASE_HOST "books-c7126.firebaseio.com"
#define FIREBASE_AUTH "RropN3CMdOJ3pNXNpIsX4Syl8S6UiNPHJuGGJfA4"
#define WIFI_SSID "CIG IITR"
#define WIFI_PASSWORD "behappy123"
int data;
void setup() {
  Serial.begin(9600);
  s.begin(9600);
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

int n = 0;

void loop() {+



  // set value
   s.write("s");
  
    data=s.read();
    Serial.println(data);
    delay(1000);
  
  if(data!=-1){
  String str = String(data);
  Firebase.setString("books/1/value", str);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      //Serial.println(Firebase.error());  
      return;
  }
  }
  
  // update value
  //Firebase.setFloat("number", 43.0);
  // handle error
  /*if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);*/

  // get value 
  /*Serial.print("number: ");
  Serial.println(Firebase.getFloat("number"));
  delay(1000);*/

  // remove value
  //Firebase.remove("number");
  //delay(1000);

  // set string value
  /*Firebase.setString("message", "hello world");
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // set bool value
  Firebase.setBool("truth", false);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // append a new value to /logs
  String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  Serial.println(name);
  delay(1000);*/
}
