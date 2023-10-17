#include <ESP8266WiFi.h>
 
const char* ssid = "Duocopter";
const char* password = "difficultasf";
 
; // 
WiFiServer server(80);
 
IPAddress local_IP(192, 168, 1, 184);
// Set your Gateway IP address
IPAddress gateway(192, 168, 1, 1);

IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

void setup() {
  // put your setup code here, to run once:
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
}

void loop() {
  // put your main code here, to run repeatedly:

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

   if (request.indexOf("/forward") > 0)  
   {
    digitalWrite(4, HIGH);
    delay(40);
    digitalWrite(4, LOW);
   }

   if (request.indexOf("/backward") > 0)  
   {
    digitalWrite(4, HIGH);
    delay(20); //may have to change later
    digitalWrite(4, LOW);
   }
   if (request.indexOf("/right") > 0)  
   {
    digitalWrite(5, HIGH);
    delay(40);
    digitalWrite(5, LOW);
   }

   if (request.indexOf("/left") > 0)  
   {
    digitalWrite(5, HIGH);
    delay(20); //may have to change later
    digitalWrite(5, LOW);
   }
   if (request.indexOf("/up") > 0)  
   {
    digitalWrite(12, HIGH);
    delay(40);
    digitalWrite(12, LOW);
   }

   if (request.indexOf("/down") > 0)  
   {
    digitalWrite(12, HIGH);
    delay(20); //may have to change later
    digitalWrite(12, LOW);
   }
   if (request.indexOf("/manual") > 0)  
   {
    digitalWrite(13, HIGH);
    delay(40);
    digitalWrite(13, LOW);
   }

   if (request.indexOf("/hover") > 0)  
   {
    digitalWrite(13, HIGH);
    delay(20); //may have to change later
    digitalWrite(13, LOW);
   }
   if (request.indexOf("/stop") > 0)  
   {
    digitalWrite(14, HIGH);
    delay(40);
    digitalWrite(14, LOW);
   }

   if (request.indexOf("/auto") > 0)  
   {
    digitalWrite(14, HIGH);
    delay(20); //may have to change later
    digitalWrite(14, LOW);
   }

}
