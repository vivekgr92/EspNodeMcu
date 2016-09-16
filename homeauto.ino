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
***************************************************************/

/* This Program is Written , Compiled and tested by VIVEK GR*/
 

#define BLYNK_PRINT Serial    
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SPI.h>


char auth[] = "1e79dd4362354471abcb7b1d5af69680";              // You should get Auth Token in the Blynk App.
WidgetLCD lcd(V3);                                             // LCD is connected to the Virtual Pin no 3
long rssi;
IPAddress ip;
int rawvoltage;
float millivolts;
float celsius;

int PIR=12;
int Led1=4;
int Led2=0;
int sensor_in;
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, "EFY-Wlan7", "25012010");                   //  Enter your Wifi Credentials
  lcd.clear();
  pinMode(PIR,INPUT);
  pinMode(16,OUTPUT);
  pinMode(Led1,OUTPUT);
  pinMode(Led2,OUTPUT);
  delay(5000);

}

void loop()
{
  Blynk.run();
  rssi=WiFi.RSSI();                                        // Functions to display RSSI and Ip address
  Serial.print(rssi);
  //lcd.print(0, 0, "WELCOME:)");
   ip = WiFi.localIP();

rawvoltage= analogRead(A0);
millivolts= (rawvoltage/1024.0) * 3000;                   // ADC Voltage conversion to Deg Celsius
celsius= millivolts/10;
//Serial.print(celsius);
//Serial.print(" degrees Celsius, ");
//lcd.print(0, 0, "Temperature");
//lcd.print(0, 1,celsius);

Blynk.virtualWrite(0, celsius);                       // This fn is used to write the celsius value in to the Blynk Tmp Guage , displayed on the Phone
sensor_in=digitalRead(PIR);
if (sensor_in == HIGH)
{
    Serial.print("\n\nHIGH");
    digitalWrite(16,HIGH);
    Blynk.email("espnodemcu@gmail.com", "Subject: Motion Detected", "Suspicious activiy detected!!...");   // This Fn is used to send in the email , if motion is detected
    Serial.print("Email Sent");
}else
{
   Serial.print("\n\nlow");
   digitalWrite(16,LOW);
}
}

 BLYNK_WRITE(V4) //Button Widget is writing to pin V1
{
  int pinData = param.asInt(); 
  if(pinData==1)
  {
    lcd.clear();
    lcd.print(0 ,0,"Wifi Strength");                  // This fn displays the Wifi strength when a button is pressed from the Blynk App
    lcd.print(0 ,1,rssi);
  }else
  {
    lcd.clear();
  }
  
}

BLYNK_WRITE(V5) //Button Widget is writing to pin V1
{
  int pinData = param.asInt(); 
  if(pinData==1)
  {
    lcd.clear();
    lcd.print(0 ,0,"IP ADDRESS:");                 // This fn displays the IP Address when a button is pressed from the Blynk App
    lcd.print(0 ,1,ip);
   
  }else
  {
    lcd.clear();
  }
  
}

BLYNK_WRITE(V6) //Button Widget is writing to pin V1
{
  int pinData = param.asInt(); 
  if(pinData==1)
  {
    digitalWrite(Led1,HIGH);
    digitalWrite(Led2,HIGH);                   // This fn displays the Switches on the Flasher Led's when a button is pressed from the Blynk App
    delay(500);
    digitalWrite(Led2,LOW);
    digitalWrite(Led2,LOW);
   
  }else
  {
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,LOW);
    delay(500);
    digitalWrite(Led2,LOW);
    digitalWrite(Led2,LOW);
  }
  
}

