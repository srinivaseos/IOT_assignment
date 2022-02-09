#include<WiFi.h>
#include "DHT.h"
#include "ThingSpeak.h"
char ssid[]= "gurujala";
char pass[]= "Srinivas77";
#define DHTPIN 22
float temperature;
float humidity;
DHT dht(DHTPIN,DHT11);
WiFiClient client;
unsigned long myChannelNumber= 1646432;
const char * myWriteAPIKey = "TLSLVP111MBQH9AP";
const int ChannelField1=1;
const int ChannelField2=2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
dht.begin();
ThingSpeak.begin(client);
WiFi.mode(WIFI_STA);
}

void loop() {
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
temperature=dht.readTemperature();
humidity=dht.readHumidity();

if(isnan(temperature) || isnan(humidity))
{
  Serial.println("Failed to read DHT sensor!");
  return;
}
Serial.print(F("% Temperature:"));
Serial.print(temperature);
Serial.print(F("% Humidity:"));
Serial.print(humidity);
delay(2000);

ThingSpeak.writeField( myChannelNumber,ChannelField1,temperature,myWriteAPIKey);
ThingSpeak.writeField( myChannelNumber,ChannelField2,humidity,myWriteAPIKey);

delay(1000);
}
