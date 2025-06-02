///////////////////////////////////////// CONECTA E RECONECTA O WIFI /////////////////////////////////////////

void reconnect() {
// Loop até estarmos reconectados
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
// Crie um ID de cliente aleatório
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
// Tentativa de conexão
    
      if (client.connect("ESP8266", "mudviper133", "Senha")) {      //< A função "client.connect" conecta o esp no servidor 
        
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("ESP8266", "OPERANDO");//<----------------------------------- 
      // ... and resubscribe
      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

