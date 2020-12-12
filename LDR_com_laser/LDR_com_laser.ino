
const int pinoLDR = A0;
int leitura = 0;

void setup() {
  //configurando a Serial
  Serial.begin(9600); // 9600bps

  //configura o pino do LDR como entrada
  pinMode(pinoLDR, INPUT);
}

void loop() {
  //armazena a leitura da tensão do LDR 
  leitura = analogRead(pinoLDR);

  //imprime o valor lido pelo arduino (0 a 1023)
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\t"); //tabulacao

  //Imprime se há ou não um obstáculo
  Serial.print("Obstaculo: ");
  
  if(leitura <= 512){
    Serial.print("Sim");
  }
  
  else {
   Serial.print("Nao"); 
  }

  Serial.println(); // pula para proxima linha

  delay(1000); // em intervalos de 1 segundo atualiza a leitura
}
