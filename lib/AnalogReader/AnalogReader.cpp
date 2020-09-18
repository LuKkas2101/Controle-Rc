#include "AnalogReader.h"
#include <Arduino.h>

#ifdef _ANALOG_READER_H

#define minAnalogico 0
#define maxAnalogico 1023

AnalogReader::AnalogReader(const int pin) : m_pin(pin) {}

/**
 * Read analog value from board ADC

int AnalogReader::read()
{
	return analogRead(m_pin);
}
*/

int AnalogReader::read(const int min = 0, const int max = 255)
{
	return map(analogRead(m_pin), minAnalogico, maxAnalogico, min, max);
}





#endif