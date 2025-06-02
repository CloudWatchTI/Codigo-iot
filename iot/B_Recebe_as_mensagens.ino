  

///////////////////////////////////////// RECEBE AS MENSAGENS /////////////////////////////////////////

    int resultadoR = 0;
    int resultadoG = 0;
    int resultadoB = 0;
    
    int resultadoA = 0;
    int resultadoT = 0;
    int resultadoU = 0;

void recebePacote(char* topic, byte* payload, unsigned int length) {

    String msg;

    for (int i = 0; i < length; i++) {
       char c = (char)payload[i];
       msg += c;
      }

  /////////////////////////////////////////////////////////////////////////////////////////////////////

  if ((char)payload[0] == 'U') {         //<---------------------------------------------- UMIDADE 
    
    int PriU =  (char)payload[5] - '0';
    int SegU = ((char)payload[4] - '0')*10;
    int TerU = ((char)payload[3] - '0')*100;

    resultadoU = TerU + SegU + PriU;
  envioUMID();
  } 

  delay(200);
} 


