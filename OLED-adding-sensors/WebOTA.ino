#include <WiFi.h>
#include <WiFiMulti.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>



WiFiMulti wifiMulti;
AsyncWebServer server(80);

string hello =

void netStart(void) {

   wifiMulti.addAP("villa", "puttanesca");
   wifiMulti.addAP("Noisebridge", "noisebridge");
   
  Serial.println("");

    Serial.println("Connecting Wifi...");
    if(wifiMulti.run() == WL_CONNECTED) {
        Serial.println("");
        Serial.print("WiFi connected: ");
        Serial.println(WiFi.SSID());
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }
        else {
        Serial.println("Wifi failed to connect.\n");
    }
    

  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(200, "text/plain", "Mars yet?.");
  });

  AsyncElegantOTA.begin(&server);    // Start ElegantOTA
  server.begin();
  Serial.println("HTTP server started");
}
