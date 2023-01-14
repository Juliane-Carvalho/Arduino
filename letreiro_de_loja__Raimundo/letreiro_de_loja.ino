//Simulação de letreiro eletrônico com comando de controle infra-vermelho

#include <IRremote.h>

int RECV_PIN = 11;
float valorlido;       // valor hex do botão apertado

int led3 = 7;
int led2 = 4;
int led1 = 2;

 
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);
  irrecv.enableIRIn(); // inicia a recepção do IR
}

void loop() 
{
    
   if(irrecv.decode(&results)){
    Serial.print("Valor Lido: ");
    Serial.println(results.value, HEX);
    valorlido = (results.value);

    //Se foi apertado o botão 1
    if(valorlido == 0xFD08F7){
      Serial.println("TODA LOJA POR 25 REAIS");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
     
      }else{
   
    //Se foi apertado o botão 2  
    if(valorlido == 0xFD8877){
      Serial.println("BOAS COMPRAS");
      digitalWrite(led1, HIGH);
      delay(1000);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      delay(1000);
      digitalWrite(led2,LOW);
      digitalWrite(led3, HIGH);
      delay(1000);
      digitalWrite(led3,LOW);
   
      }
      }
    
    //Se o botão 3 for apertado  
    if(valorlido == 0xFD48B7){
      Serial.println("VAI TER 10conto");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(1000);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(1000);
      
      }
       else {

    irrecv.resume(); //Próxima leitura  
    
      }
   
    }  

    }
 

