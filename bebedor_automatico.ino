#define trigPin 12 // define pino 12 com nome trigPin
#define echoPin 13 // define pino 12 com nome echoPin
#define fakevcc 11 // define pino 11 com nome fakevcc
#define rele A0 // define pino A0 com nome rele

int count = 0; // cria variavel
int i;

void setup() {
  Serial.begin (9600); // inicia comunicação serial
  pinMode(fakevcc, OUTPUT); // define fakevcc como saida digital
  pinMode(trigPin, OUTPUT); // define trigPin como saida digital
  pinMode(echoPin, INPUT); // define echoPin como entrada digital
  pinMode(rele, OUTPUT);  // define rele como saida digital
  digitalWrite(fakevcc, HIGH); // deixa fakevcc em nivel alto constante
  digitalWrite(rele,HIGH); // inicia relé desativado (modulo relé ativo em nivel baixo)
}

void loop() {
  long duration, distance;  // rotina de medição do sensor ultrassonico
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

 if (distance <= 20) { // se distancia medida for menor ou igual a 20 cm, executa codigo abaixo

for (i=0;i<=3;i++) // laço FOR de 3 repetições

  digitalWrite(trigPin, LOW);  // rotina de medição do sensor ultrassonico
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

count++;
delay(1000); // atraso em 1 segundo
if(distance >= 21){ // se distancia for maior ou igual a 21 cm programa sai do FOR
  count = 0; // zera contagem
  return 0; // retorna ao inicio
  }

if(count==3){ // se em 3 segundos permanecer distancia inferior a 20 cm executa codigo abaixo
    digitalWrite(rele,LOW); // ativa relé
    delay(3000); // atraso de 3 segundos
    digitalWrite(rele,HIGH); // desliga relé
    count = 0;   // zera contador

         digitalWrite(trigPin, LOW);  // rotina de medição do sensor ultrassonico
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
       
       while (distance<=20){ // determina ficar dentro do laço while enquanto distancia permanecer menor que 20 cm
        
  digitalWrite(trigPin, LOW);  // rotina de medição do sensor ultrassonico
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  delay(300);}
}}
   
  if (distance >= 21){ // se distancia for maior ou igual a 21 cm executa abaixo
    Serial.println("sem copo"); // escreve no monitor serial
    digitalWrite(rele,HIGH); // deixa relé desabilitado
  }
  else {
    Serial.print(distance); // escreve a distancia lida pelo sensor no monitor serial
    Serial.println(" cm");  // escreve no monitor serial
  }
  delay(100); // atraso 0.1 segundos
}
