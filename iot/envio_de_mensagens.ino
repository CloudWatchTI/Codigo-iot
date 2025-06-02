///////////////////////////////////// ENVIA AS MENSAGENS PRO SERVIDOR /////////////////////////////////////////

void envio(){

    //#define MSG_BUFFER_SIZE  (50)
    //char R[MSG_BUFFER_SIZE];
    //int temp = 0;
    //temp = analogRead(A0)/10;
    
    delay(200);
}

void envioUMID (){
    
    #define MSG_BUFFER_SIZE1  (50)
    char R2[MSG_BUFFER_SIZE1];
    snprintf (R2, MSG_BUFFER_SIZE1, "%ld", estadoAtualDaUmi ,"%ld"); 
    client.publish("umi", R2);
}

