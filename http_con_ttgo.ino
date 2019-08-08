#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

WiFiMulti wifiMulti;

void setup() {
  Serial.begin(115200);
  delay(100);
  wifiMulti.addAP("snapoffice_01","SnapAguascalientes");
  
    Serial.println("Conectando a WiFi");
    while(wifiMulti.run()!= WL_CONNECTED){
    Serial.print(".");
    }
    
   Serial.println();
   Serial.println("WiFi Conectado");
   Serial.print("Direccion IP: ");
   Serial.println(WiFi.localIP());
}

void loop() {
  HTTPClient http;
  Serial.println("[HTTP] Iniciando...");
  http.begin("http://www.arduino.cc/asciilogo.txt");
  
  Serial.println("[HTTP] GET...");
  http.GET();
  String respuesta = http.getString();
  Serial.print(respuesta);
  http.end();
  delay(10000);

}
