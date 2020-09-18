#ifdef notCompile
/* *********************
************************envia o texto digitado no monitor serial
*****************************************************
*/

#include <SPI.h>      //INCLUSÃO DE BIBLIOTECA
#include <nRF24L01.h> //INCLUSÃO DE BIBLIOTECA
#include <RF24.h>     //INCLUSÃO DE BIBLIOTECA

RF24 radio(9, 10); //CRIA UMA INSTÂNCIA UTILIZANDO OS PINOS (CE, CSN)

const byte address[6] = "00002"; //CRIA UM ENDEREÇO PARA ENVIO DOS
//DADOS (O TRANSMISSOR E O RECEPTOR DEVEM SER CONFIGURADOS COM O MESMO ENDEREÇO)

void setup()
{
  Serial.begin(9600); //INICIALIZA A SERIAL

  radio.begin();                  //INICIALIZA A COMUNICAÇÃO SEM FIO
  radio.openWritingPipe(address); //DEFINE O ENDEREÇO PARA ENVIO DE DADOS AO RECEPTOR
  radio.setPALevel(RF24_PA_HIGH); //DEFINE O NÍVEL DO AMPLIFICADOR DE POTÊNCIA
  radio.stopListening();          //DEFINE O MÓDULO COMO TRANSMISSOR (NÃO RECEBE DADOS)
}

void loop()
{
  if (Serial.available())
  {
    String text = Serial.readString(); //VARIÁVEL RECEBE A MENSAGEM A SER TRANSMITIDA
    Serial.print("a mensagem: ");
    Serial.print(text);              //IMPRIME NA SERIAL OS DADOS RECEBIDOS
    Serial.println(" :foi enviada");

    radio.write(&text, sizeof(text)); //ENVIA AO RECEPTOR A MENSAGEM
  }
  delay(1);
}
#endif