

//#include <LiquidCrystal_I2C.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LCD5110_Graph.h>

#define one_wire_bus0 A0                             //declaração do pino signal do sensor 1
#define one_wire_bus1 A1   

LCD5110 tela(8,9 ,10 ,12 ,11);                      //cria objeto de classe LCD5110
/*  
CLK - Pino 8
DIN - Pino 9
DC  - Pino 10
RST - Pino 12
CE  - Pino 11
*/
//fontes de impressão no display
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
//imagens de sinalização
extern uint8_t floco[];
extern uint8_t helice1[];


OneWire oneWire0(one_wire_bus0);                             //instancia o objeto de classe OneWire e e seta o pino do sensor de recepção do sinal
DallasTemperature sensor0(&oneWire0);                        //passa as referências(recepção) do oneWire para o DallasTemp.

OneWire oneWire1(one_wire_bus1);                             //instancia o objeto de classe OneWire e e seta o pino do sensor de recepção do sinal
DallasTemperature sensor1(&oneWire1);        


void setup() {
 
 tela.InitLCD();                                          //inicialização do display

 Serial.begin(9600);
 Serial.println("Sensor de Temperatura DS18B20");
 sensor0.begin();
 sensor1.begin();
 
 // tela.drawRoundRect(0,0,83,47);                          //desenha um retângulo com as bordas arredondadas
 // tela.drawLine(0,15,83,15);
} 

void loop() {
 
 sensor0.requestTemperatures();                            //comando solicitando a temperatura
 float leitura0 = sensor0.getTempCByIndex(0);               //armazena na variavel 'leitura' os valores lidos pelo sensor (em celsius na posição 0)  

  sensor1.requestTemperatures();                            //comando solicitando a temperatura
 float leitura1 = sensor1.getTempCByIndex(0);               //armazena na variavel 'leitura' os valores lidos pelo sensor (em celsius na posição 0)      
 
 Serial.println("Valor lido: ");   
 Serial.println(leitura0);
 Serial.println("\t");
 Serial.println(leitura1);
 Serial.println("\t");


 
 /*tela.setFont(SmallFont);                                //definindo a fonte
 tela.print("Temperatura: ", CENTER, 5);                   //palavra a ser impressa; começando à esquerda do display na linha 0
 tela.setFont(BigNumbers);                                     
 tela.printNumF(leitura, 1, 14, 20);
 tela.setFont(SmallFont);
 tela.print("o", 72, 19);
 delay(1000); 
 tela.update();
 //tela.clrScr();                                               //apaga o conteudo da tela
*/
 tela.clrScr();
 tela.setFont(BigNumbers);                                     
 tela.printNumF(leitura0, 1, 4, 3);
 tela.setFont(SmallFont);
 tela.printNumF(leitura1, 70, 20, 3);
 tela.setFont(SmallFont);
 tela.print("SP: 22", 4, 34);
 tela.drawBitmap (56, 2, floco, 17, 17);
 tela.drawBitmap(56, 25, helice1, 17, 17);
 delay(1000);//(coluna,linha, imagem, largura, altura)
 tela.update();  //atualiza os dados da tela
                                               //atualiza os dados da tela
}
