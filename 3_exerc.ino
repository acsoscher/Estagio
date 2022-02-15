/*CRIAR UM SEMÁFORO UTILIZANDO 6 LEDS E UM RGB*/ 
boolean anoC = true;
int pinoA = 13;
int pinoV = 12;
int pinoR = 11;
int pinoG = 10;
int pinoB = 9;
int pinoV02 = 8;

void setup(){
  pinMode(pinoR, OUTPUT);
  pinMode(pinoG, OUTPUT);
  pinMode(pinoB, OUTPUT);
  pinMode(pinoV, OUTPUT);
  pinMode(pinoV02, OUTPUT);
  pinMode(pinoA, OUTPUT);
}

void loop(){
  setCor(255,0,0);
  digitalWrite(pinoV02, HIGH);
  delay(2000);
  digitalWrite(pinoV02, LOW);
  setCor(255,255,0);
  digitalWrite(pinoA, HIGH);
  delay(2000);
  digitalWrite(pinoA, LOW);
  setCor(0,255,0);
  digitalWrite(pinoV, HIGH);
  delay(2000);
  digitalWrite(pinoV, LOW);  
 
}
  
void setCor(int verm, int verd, int azul){
  if(anoC == true){
    verm =  verm++;
    verd =  verd++;
    azul =  azul++;
  }
  analogWrite(pinoR,verm);
  analogWrite(pinoG,verd);
  analogWrite(pinoB,azul);
}
