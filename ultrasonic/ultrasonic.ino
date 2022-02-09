#include "ThingSpeak.h"
#include"WiFi.h"
char ssid[]="gurujala";
char pass[]="Srinivas77";

const int trigger =5;
const int echo =18;
long T;
float distanceCM;
WiFiClient client;
unsigned long myChannelNumber= 1646432;
const char * myWriteAPIKey = "TLSLVP111MBQH9AP";
const int ChannelField=3;
void setup() {
  Serial.begin(115200);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  // put your setup code here, to run once:

}

void loop()
{
  // put your main code here, to run repeatedly:
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
digitalWrite(trigger,LOW);
delay(1);
digitalWrite(trigger,HIGH);
delay(10);
digitalWrite(trigger,LOW);
T=pulseIn(echo,HIGH);
distanceCM=(T*0.034)/2;
Serial.println("distance in cm:");
Serial.println(\ndistanceCM);
ThingSpeak.writeField( myChannelNumber,ChannelField,distanceCM,myWriteAPIKey);
delay(1000);
}