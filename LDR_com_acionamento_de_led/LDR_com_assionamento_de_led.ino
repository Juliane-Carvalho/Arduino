/*Programa feito por Juliane Carvalho 
baseado nos códigos da RoboCore.
Tem por finalidade simular o ligar e desligar automático de postes */
const int pinoLDR = A0; //pino conectado o LDR
const int pinoLED = 4; // pino conectado o LED
int leitura = 0; // variavel para armazenar o valor lido do pino do LDR

void setup() {

  //configura o pino do LDR e do LED como entrada
  pinMode(pinoLDR, INPUT);
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  //armazena a leitura da tensão do LDR 
  leitura = analogRead(pinoLDR);
  
  if (leitura < 40){
    digitalWrite(pinoLED, HIGH);
    }
   else{
    digitalWrite(pinoLED, LOW);
    }
    
  delay(1000); // em intervalos de 1 segundo atualiza a leitura
}
