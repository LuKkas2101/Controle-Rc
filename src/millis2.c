
#include<millis2.h>

unsigned long tempoAnterior = 0;

bool yield_return(long ms)
{
  
  if (millis() - tempoAnterior >= ms)
  {
    tempoAnterior = millis();
    return true;
  }

  return false;
}