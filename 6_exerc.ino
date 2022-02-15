/*Programa feito para mostrar funcionalidade do display
int segA = 4;
int segB = 3;
int segC = 5;
int segD = 6;
int segE = 7;
int segF = 8;
int segG = 9;

void setup()
{
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
}

void loop()
{
  digitalWrite(segA, LOW);
  delay(1000);
}*/
//Programa para fazer um contador;
int a = 4, b = 3, c = 5, d = 6, e = 7, f = 8, g = 9; //variaveis de mesmo tipo colocadas na mesma linha
int num[10][7]{ //matriz (array)
  {a,b,c,d,e,f},//zero
  {b,c}, //um
  {a,b,e,d,g}, //dois
  {a,b,c,d,g}, //trêS
  {b,c,f,g}, //quatro
  {a,c,d,f,g}, //cinco
  {a,c,d,e,f,g}, //seis
  {a,b,c}, //sete
  {a,b,c,d,e,f,g}, //oito
  {a,b,c,f,g}, //nove
};

void setup(){
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop()
{
  for(int i = 0; i < 10; i++){
    apaga();
    numero(i);
    delay(1000);
  }
}

void apaga(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void numero(int n){
  for(int i = 0; i < 7; i++) digitalWrite(num[n][i], LOW);
}