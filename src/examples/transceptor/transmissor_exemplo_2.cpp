#ifdef notCompile
/******************************************************************************************************************************/
// Este é o programa transmissor.
// Envia dados para um pipe 0. Se chave pressionda, envia 1, caso contrário envia 0
// Transceiver: nRF24L01+
/******************************************************************************************************************************/

#include <SPI.h>                                                    // Biblioteca de comunicação SPI
#include <RF24.h>                                                   // Inclui a biblioteca do nRF24L01+

#define Ch1   8                                                     // Chave ligada no pino 8 do Arduino

RF24 myRadio(9,10);                                                 // Cria o objeto myRadio - CE,CSN
byte AdressPipe[][6] = {"0pipe"};                                   // Cria um canal de comunição - PIPE0
int Contador = 0;                                                   // Cria uma variável para ser enviada

void setup() 
{
    delay(1000);                                                    // Espera 1 segundo
    pinMode(Ch1,INPUT_PULLUP);                                      // Coloca o pino Ch1 como entrada e ativa o pullup
    myRadio.begin();                                                // Inicia o radio
    myRadio.setChannel(1);                                          // Seleciona o canal do radio
    myRadio.setPALevel(RF24_PA_MAX);                                // Ajusta a potencia do radio para a máxima
    myRadio.setDataRate(RF24_250KBPS);                              // Ajusta a taxa de comunicação para 250K bits por segundo
    myRadio.setAutoAck(false);                                      // Desliga o ACK
    myRadio.openWritingPipe(AdressPipe[0]);                         // Abre o canal 0pipe
    delay(500);                                                     // Espera 1/2 segundo
}

void loop() 
{
    Contador = digitalRead(Ch1);                                    // Lê Ch1 e salva em Contador
    myRadio.write(&Contador, sizeof(Contador));                     // Escreve no radio a variável contadora
    delay(100);                                                     // Espera 0.1 segundo
}
#endif