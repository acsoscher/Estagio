void setup(){
  
 pinMode(13, OUTPUT); //OUTPUT = saída |
  // O pino de porta número 13 funcionará como saída
  
}

void loop(){
  
 digitalWrite(13, HIGH); //HIGH = ligado | Liga a LED
 delay(1000); //espera 1000 mili segundos para executar um comando
 digitalWrite(13, LOW); //LOW = desligado | Desliga a LED
 delay(1000);
}