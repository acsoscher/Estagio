
int led = 5; //tem que ser pwm por ser analogWrite
int val_pot = 0; //valor potenciometro/posição
int brilho = 0;

void setup(){
  pinMode(led, OUTPUT);
  
          }

void loop(){
  val_pot = analogRead(A0);
  brilho = map(val_pot, 0, 1023, 0, 255); /*pega o valor que 
  está entre 0 e 1023 e converte para 0 a 255*/
  analogWrite(led, brilho);

}

/* codigo para parar de mostrar valores no monitor serial ao 
parar de mexer no potenciometro

int leitura01 = 0;
int leitura02 = 0;

void setup(){
  Serial.begin(9600);

}

void loop(){
  leitura01 = analogRead(A0);
  if(leitura01 > (leitura02 + 2) || leitura01 < (leitura02 - 2)){
  	leitura02 = leitura01;
    Serial.println(leitura01);  
  	delay(100);
  }
  
}*/
