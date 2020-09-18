#ifdef notCompile
/******************************************************************************************************************************/
// Este é o programa receptor.
// Recebe dados de um pipe 0. Se Contador for igual a 0, liga rele no pino 8.
// Transceiver: nRF24L01+
/******************************************************************************************************************************/

#include <SPI.h>                                                    // Biblioteca de comunicação SPI
#include <RF24.h>                                                   // Inclui a biblioteca do nRF24L01+

#define led   8                                                   // Define pino 8 ligado ao rele

RF24 myRadio(9,10);                                                 // Cria o objeto myRadio - CE,CSN
byte AdressPipe[][6] = {"0pipe"};                                   // Cria um canal de comunição - PIPE0
int Contador = 1;                                                   // Cria uma variável para ser enviada

void setup() 
{
    delay(1000);                                                    // Espera 1 segundo
    pinMode(led,OUTPUT);                                          // Coloca o pino Relay como saída
    digitalWrite(led,HIGH);                                       // Desliga o rele
    Serial.begin(9600);                                             // Inicializa a serial com 9600 bps        
   
    myRadio.begin();                                                // Inicia o radio
    myRadio.setChannel(1);                                          // Seleciona o canal do radio
    myRadio.setPALevel(RF24_PA_MAX);                                // Ajusta a potencia do radio para a máxima
    myRadio.setDataRate(RF24_250KBPS);                              // Ajusta a taxa de comunicação para 250K bits por segundo
    myRadio.setAutoAck(false);                                      // Desliga o ACK
    myRadio.openReadingPipe(1,AdressPipe[0]);                       // Abre a leitura do 0pipe
    myRadio.startListening();                                       // Inicia a leitura dos dados
    Serial.println("OK, receptor pronto!");                         // Receptor pronto para leitura dos dados
    delay(500);                                                     // Espera 1/2 segundo
}

void loop() 
{
    while(myRadio.available())                                      // Enquanto existir dados disponíveis
    {
        myRadio.read(&Contador, sizeof(Contador));                  // Lê o dados que chegou e envia para Contador
        Serial.print("Valor do Contador: ");                        // Imprime máscara
        Serial.println(Contador);                                   // Imprime a variavel Contador
    }
    digitalWrite(led,Contador);                                   // Desliga o rele
}
#endif