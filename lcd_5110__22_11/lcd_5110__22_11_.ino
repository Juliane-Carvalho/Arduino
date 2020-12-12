#include <LCD5110_Graph.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
LCD5110 tela(8,9,10,12,11);

#define one_wire_bus0 A0                             //declaração do pino signal do sensor 1
#define one_wire_bus1 A1   

/*Cria objeto da classe LCD5110
CLK – Pino 8
DIN – Pino 9
DC – Pino 10
RST – Pino 12
CE – Pino 11
*/


OneWire oneWire0(one_wire_bus0);                             //instancia o objeto de classe OneWire e e seta o pino do sensor de recepção do sinal
DallasTemperature sensor0(&oneWire0);                        //passa as referências(recepção) do oneWire para o DallasTemp.

OneWire oneWire1(one_wire_bus1);                             //instancia o objeto de classe OneWire e e seta o pino do sensor de recepção do sinal
DallasTemperature sensor1(&oneWire1);        

extern uint8_t helice1[];
extern uint8_t floco2[];
 
//Obtendo as fontes
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
 
void setup()
{
 tela.InitLCD(100); //Inicializando o display
 sensor0.begin();
 sensor1.begin();
 Serial.begin(9600);

}
 
void loop()
{

   sensor0.requestTemperatures();                            //comando solicitando a temperatura
 float leitura0 = sensor0.getTempCByIndex(0);               //armazena na variavel 'leitura' os valores lidos pelo sensor (em celsius na posição 0)  

  sensor1.requestTemperatures();                            //comando solicitando a temperatura
 float leitura1 = sensor1.getTempCByIndex(0);               //armazena na variavel 'leitura' os valores lidos pelo sensor (em celsius na posição 0)      


 Serial.println("VALORES LIDOS: "); 
 Serial.print("Sensor 1:  ");  
 Serial.println(leitura0);
 Serial.println("\t");
  Serial.print("Sensor 2:  ");  
 Serial.println(leitura1); 
 Serial.println("\t");

tela.setFont(SmallFont);
tela.print("SENSOR 1:", 1, 3);
tela.setFont(SmallFont);                                     
tela.printNumF(leitura0, 1, 3, 14);    

tela.setFont(SmallFont);
tela.print("SENSOR 2:", 1, 28);
tela.setFont(SmallFont);
tela.printNumF(leitura1, 1, 4, 38);
 //tela.print("SP: 22", 4, 40);
 tela.drawBitmap (63, 0, floco2, 17, 17);
 tela.drawBitmap(63, 25, helice1, 17, 17);
 delay(2000);//(coluna,linha, imagem, largura, altura)
 tela.update();  //limpa os dados da tela
}
