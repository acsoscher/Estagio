//pushbutton porém liga ao apertar o botão e desliga ao apertar novamente
int led = 2;
int botao = 3;
int press = 0;
int ligado = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);//recebe informação do botão
}

void loop(){
  
 press = digitalRead(botao);
  
  if(press == HIGH){
    delay(100);
    switch(ligado){
     case 0:
     	digitalWrite(led, HIGH);
    	ligado = 1;
      break;
      case 1:
      	digitalWrite(led, LOW);
    	ligado = 0;
      break;
      
    } 
}
}