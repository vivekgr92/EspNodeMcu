/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 *
 * You need to install this for ESP8266 development:
 *   https://github.com/esp8266/Arduino
 *
 * Please be sure to select the right ESP8266 module
 * in the Tools -> Board menu!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "bcd65ddcff644e4ea77c2f183f38d935";
int M1A=5;
int M2A=4;
int M1B=0;
int M2B=2;
int Led=12;

void setup()
{
  Serial.begin(115200);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(12, OUTPUT);
  Blynk.begin(auth, "DVR", "25012010");
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0)
{
  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,LOW);
  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,LOW);
  digitalWrite(Led,HIGH);
  
}
BLYNK_WRITE(V1)
{
  
  int x = param[0].asInt();
  int y = param[1].asInt();

  // Do something with x and y
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("; Y = ");
  Serial.println(y);
  if(x==255)
  {
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,HIGH);
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,HIGH);
  digitalWrite(Led,HIGH);
  
  }
  
}



