#include "Arduino.h"

#define RECEPTOR                //comente para habilitar o transmissor

#define TRANSMISSOR

#ifndef RECEPTOR
#define TRANSMISSOR
#endif


// The sizeof this struct should not exceed 32 bytes


const uint64_t my_radio_pipe = 0xE8E8F0F0E1LL;  //Remember that this code should be the same for the receiver

//const uint64_t pipeIn = 0xE8E8F0F0E1LL; //Remember that this code is the same as in the transmitter




struct pacoteDeDados
{
  byte ch1;
  byte ch2;
  byte ch3;
  byte ch4;
  byte ch5;
  byte ch6;
  byte ch7;
};