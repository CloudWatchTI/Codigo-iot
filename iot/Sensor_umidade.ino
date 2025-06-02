///////////////////////////////////// SENSOR DE UMIDADE DO SOLO /////////////////////////////////////////
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

int estadoAtualDaUmi = 0;
float lastTempC = -1000.0;  // valor inicial impossível para forçar a 1ª leitura

void SetupUMI() {
}

void LoopUMI(){

  int adc = analogRead(A0);
  float voltage = adc * 5 / 1023.0;
  float resistance = (5 * 10000.0 / voltage) - 10000.0;
  float tempC = 1.0 / (1.0 / 298.15 + log(resistance / 10000.0) / 3435.0) - 273.15;

  if (abs(tempC - lastTempC) > 0.1) {
    delay(10);
    estadoAtualDaUmi = tempC;
    lastTempC = estadoAtualDaUmi;
    envioUMID ();
  }
}