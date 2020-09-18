#ifndef _ANALOG_READER_H
#define _ANALOG_READER_H

class AnalogReader
{
	public:
		AnalogReader(const int pin);
		//int read();
		int read(const int min, const int max);

	private:
		const int m_pin;
};
#endif //_ANALOG_READER_H
