
/*before applying the code update your  rrespective libraries
ThingSpeak
WiFiClient
ESP8266WiFi

Also download nodemcu board from boards manager 
match the CPu frequency with "80MHz"
and set the upload speed to "115200"
*/

#include <ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ThingSpeak.h>

const char *ssid =  "XXXXXXXXXX";     // replace with your wifi name
const char *pass =  "XXXXXXX";        // replace with your network Password
int val;

WiFiClient client;
 
unsigned long myChannelNumber = XXXXXX; //Your Channel Number (Without Brackets)
 
const char * myWriteAPIKey = "XXXXXXXXXXXXXXXXXX"; //Your Write API Key
void setup() 
{
       Serial.begin(115200);
       delay(10);
               
       Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 
      ThingSpeak.begin(client);
}
 
void loop() 
{      
  val=Serial.read();
 ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
 Serial.println("uploaded");
 delay(1000);
 
 
}
