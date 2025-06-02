
/*
/////// PINAGEM DO ESP PARA ARDUINO ///////
-------------------------------------------
NodeMCU / ESP8266   |  NodeMCU / ESP8266  |
D0 = 16             |  D6 = 12            |
D1 = 5              |  D7 = 13            |
D2 = 4              |  D8 = 15            |
D3 = 0              |  D9 = 3             |
D4 = 2              |  D10 = 1            |
D5 = 14             |                     |
-------------------------------------------
*/

    
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>            

///////////////////////////////////// CASA  ////////////////////////////////////////

const char* ssid = "VINI";                    //NOMBRE DE LA RED DEL MODEN       shiftr.io
const char* password = "leo12345";               //CONTRASEÑA DEL MODEN             shiftr.io

const char* mqtt_server = "mudviper133.cloud.shiftr.io";

WiFiClient espClient;
PubSubClient client(espClient);

///////////////////////////////////////// VOID SETUP /////////////////////////////////////////

void setup() {
  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(recebePacote);
  
  SetupUMI();
}
////////////////////////////////////////// VOID LOOP //////////////////////////////////////////

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  LoopUMI();
}
///////////////////////////////////////////////////////////////////////////////////////////////

