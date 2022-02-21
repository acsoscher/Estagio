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

int value = 0;
void loop(){

  //Código exemplo do IDE para wifi server com algumas modificações
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            
            client.print("<br> Clique em <a href=\"/ON\"> ligado</a>, para escrever ON no display.");
            client.print("<br>Clique em <a href=\"/OFF\"> desligado</a>, para escrever OFF no display.");

            client.println();
            
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /ON")) {
            Heltec.display->clear();
            //Heltec.display->setFont(ArialMT_Plain_10);
            Heltec.display->drawString(64, 15, "ON");
            Heltec.display->display();
          }
        if (currentLine.endsWith("GET /OFF")) {
            Heltec.display->clear();
            //Heltec.display->setFont(ArialMT_Plain_10);
            Heltec.display->drawString(64, 15, "OFF");
            Heltec.display->display();
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Cliente desconectado.");
  }
}
