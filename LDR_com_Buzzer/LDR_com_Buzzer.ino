const int pinoLDR = A0;
const int pinoBuzzer = 9;
const int pinoBotao = 8;

int leituraLDR = 0;
int  leituraBotao;

void setup() {
  //configurando o pinos como entrada e saidas
  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  
  //armazena a leitura da tensão do LDR 
  leituraLDR = analogRead(pinoLDR);
 
  //armazena a leitura do botao
  leituraBotao = digitalRead(pinoBotao);
  
  //se o feixe de laser for deslocado ou interrompido (cair valor da leitura)
  if(leituraLDR <= 512){
    tone(pinoBuzzer, 1000); //aciona o buzzer
  }
  else if(leituraBotao == LOW){ //senão, e se o botão estiver pressionado
      noTone(pinoBuzzer); //desliga buzzer
  }

  delay(100); // em intervalos de 100 milissegundos' atualiza a leitura
}
