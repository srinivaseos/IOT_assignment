#include<DHT_U.h>
#include "ThingSpeak.h"
#include"WiFi.h"
char ssid[]="gurujala";
char pass[]="Srinivas77";
int ledpin=13;
int PIR=2;
int pirState=LOW;
int val=0;
int LEDCount;
int PersonCount;
WiFiClient client;
unsigned long myChannelNumber= 1646432;
const char * myWriteAPIKey = "TLSLVP111MBQH9AP";
const int ChannelField1=4;
const int ChannelField2=5;
void setup() {
  pinMode(ledpin,OUTPUT);
  pinMode(PIR,INPUT);
  // put your setup code here, to run once:
 Serial.begin(115200);
 WiFi.mode(WIFI_STA);
ThingSpeak.begin(client);
}

void loop() 
{
    if(WiFi.status()!=WL_CONNECTED)
 {
     Serial.print("Attempting to connect to SSID:");
     Serial.println("SECRET_SSID");
    while(WiFi.status()!=WL_CONNECTED)
  
   {
      WiFi.begin(ssid,pass);
      Serial.print(".");
     delay(5000);
   }
     Serial.println("\nconnected."); 
} 
     val=digitalRead(PIR);
   if(val==HIGH) 
  {
       digitalWrite(ledpin,HIGH);// put your main code here, to run repeatedly:
    if(pirState==LOW);
  {
      Serial.println("motion detected");
      PersonCount++;
     LEDCount++;
     pirState=HIGH;
  } 
  } 
  else
  {
   digitalWrite(ledpin,LOW);
   if(pirState==HIGH)
   {
   Serial.println("motion ended"); 
   pirState==LOW;
  }

  }   ThingSpeak.writeField( myChannelNumber,ChannelField1,PersonCount,myWriteAPIKey);
    ThingSpeak.writeField( myChannelNumber,ChannelField2,LEDCount,myWriteAPIKey);
     delay(1000); 
}