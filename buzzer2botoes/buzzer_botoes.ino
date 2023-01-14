//Programa de variação de frequência sonora de buzzer com botões push button

int frequencia = 2000;
const int pinoBuzzer = 10;
const int pinoBotao1 = 9;
const int pinoBotao2= 11;

void setup() {
  Serial.begin(9600);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoBotao1, INPUT_PULLUP);
  pinMode(pinoBotao2, INPUT_PULLUP);
}

void loop() {
  //soma 100 à frequência ao apertar o botão 
  if(digitalRead(pinoBotao1) == LOW){
    frequencia = frequencia + 100;
    }
  //subtrai 100 da frquência ao apertar o botão
  if(digitalRead(pinoBotao2) == LOW){
    frequencia = frequencia - 100;
    }

  tone(pinoBuzzer, frequencia); //gera frequência no pino correspondente ao buzzer
  delay(1000);
  noTone(pinoBuzzer); //interrompe a frequência
  delay(1000);
}
