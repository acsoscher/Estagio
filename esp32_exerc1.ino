#include <WiFi.h>
#include "heltec.h"

const char* ssid     = "Nome"; //define nome da rede wifi
const char* password = "Senha"; //define senha da rede wifi

WiFiServer server(80);

void setup()
{
   Serial.begin(115200);
   Heltec.begin(true /*DisplayEnable Enable*/, true /*LoRa Enable*/, true /*Serial Enable*/); //inicializa a placa
   Heltec.display->clear(); //limpa tela display
    delay(10);

    Serial.print("Conectando-se a ");
    Serial.println(ssid); //mostra rede
 
    WiFi.begin(ssid, password); //inicializa wifi

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi conectado. Endereço de IP:");
    Serial.println(WiFi.localIP());//mostra endereço ip
    
    server.begin();//inicia o server


}


void loop(){

  //Código exemplo do IDE para wifi server com algumas modificações
 WiFiClient client = server.available();   // procura por clientes

  if (client) {                             // se houver um cliente 
    Serial.println("Novo Cliente.");        // ele vai informar no monitor serial  
    String currentLine = "";                // e criar uma string para armazenar dado ele  
    while (client.connected()) {            // enquanto o cliente estivr conectado
      if (client.available()) {             // se houver alguma informação do cliente ela será lida
        char c = client.read();             // e então escrita no monitor serial
        Serial.write(c);                    
        if (c == '\n') {                    

         
          // ao final do pedido do cliente a seguinte mensagem será escrita
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            
            client.print("<br> Clique em <a href=\"/ON\"> ligado</a>, para escrever ON no display.");
            client.print("<br>Clique em <a href=\"/OFF\"> desligado</a>, para escrever OFF no display.");

            client.println();
            
            break;
          } else {    
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }

        // se o cliente clicou em 'ligado' será escrito na tela do ESP32 ON
        if (currentLine.endsWith("GET /ON")) {
            Heltec.display->clear();
            //Heltec.display->setFont(ArialMT_Plain_10);
            Heltec.display->drawString(64, 15, "ON");
            Heltec.display->display();
          }
         // se o cliente clicou em 'desligado' será escrito na tela do ESP32 OFF
        if (currentLine.endsWith("GET /OFF")) {
            Heltec.display->clear();
            //Heltec.display->setFont(ArialMT_Plain_10);
            Heltec.display->drawString(64, 15, "OFF");
            Heltec.display->display();
        }
      }
    }
    // aqui fecha a conexão
    client.stop();
    Serial.println("Cliente desconectado.");
  }
}
