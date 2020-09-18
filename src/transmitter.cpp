/* Tranmsitter code for the Arduino Radio control with PWM or PPM output
 * Install the NRF24 library to your IDE
 * Upload this code to the Arduino (5V,16MHz)
 * Connect a NRF24 module to it:
 
    Module // Arduino 
    
    GND    ->   GND
    Vcc    ->   3.3V
    CE     ->   D9
    CSN    ->   D10
    CLK    ->   D13
    MOSI   ->   D11
    MISO   ->   D12

This code transmits 7 channels with data from pins A0, A1, A2, A3, A4, D2 and D3
*/

#include <configure.h>
#ifdef TRANSMISSOR
#include "Joystick.h"
#include "Potentiometer.h"
#include <SPI.h>
#include <nRF24L01.h> 
#include <RF24.h>
#include <Arduino.h>
#include "LED.h"
#include "Buzzer.h"

/*
// The sizeof this struct should not exceed 32 bytes
struct Data_to_be_sent {
  byte ch1;
  byte ch2;
  byte ch3;
  byte ch4;
  byte ch5;
  byte ch6;
  byte ch7;
};
*/

//Create a variable with the structure above and name it sent_data
PacoteDeDados sent_data;
Joystick joystick_1(A0, A1, 2);
Joystick joystick_2(A2, A3, 3);
Potentiometer potentiometer_5v1_1(A4);
Potentiometer potentiometer_5v1_2(A5);
Button button1(4);
Button button2(5);
LED led1(6);
LED led2(7);
Buzzer buzzer1(8);
RF24 radio(9, 10); //Set CE and CSN pins

void setup()
{
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(my_radio_pipe);

  button1.init(INPUT);
  button2.init(INPUT);

  //Reset each channel value
  sent_data.ch1 = 127;
  sent_data.ch2 = 127;
  sent_data.ch3 = 127;
  sent_data.ch4 = 127;
  sent_data.ch5 = 0;
  sent_data.ch6 = 0;
  sent_data.ch7 = 0;
}

void loop()
{
  /*If your channel is reversed, just swap 0 to 255 by 255 to 0 below
  EXAMPLE:
  Normal:    data.ch1 = analogRead 0, 255);
  Reversed:  data.ch1 = analogRead 255, 0);  */
  
  sent_data.ch1 = joystick_1.getX();
  sent_data.ch2 = joystick_1.getY();
  sent_data.ch3 = joystick_2.getX();
  sent_data.ch4 = joystick_2.getY();

  sent_data.ch5 = joystick_1.getSW();
  sent_data.ch6 = joystick_2.getSW();

  sent_data.ch7 = potentiometer_5v1_1.read(0, 255);
  sent_data.ch8 = potentiometer_5v1_2.read(0, 255);

  sent_data.ch9 = button1.onChange();
  sent_data.ch10 = button1.onChange();
  
  radio.write(&sent_data, sizeof(PacoteDeDados));
}

#endif