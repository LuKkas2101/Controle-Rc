#include "Joystick.h"
#include "Arduino.h"
/**
* Construct Joystick instance.<BR>
* It consists of two 10Kohm potentiometer and a Pushbutton.<BR>
* pinX, pinY - analog pin on arduino board to read potentiometers.<BR>
* pinSW - digital pin on arduino board to read pushbutton state.
*/
Joystick::Joystick(int pinX, int pinY, int pinSW) : m_pinX(pinX), m_pinY(pinY), m_pinSW(pinSW) 
{
    pinMode(m_pinX,INPUT);
    pinMode(m_pinY,INPUT);
    
    joyX = new AnalogReader(m_pinX);
    joyY = new AnalogReader(m_pinY);
    joySW = new Button(m_pinSW);

    joySW->init(INPUT_PULLUP);
}

//Return X axis value
int Joystick::getX(const int min, const int max)
{
    return joyX->read(min, max);
}

//Return X axis value de  0 to 255
int Joystick::getX()
{
    return getX(0, 255);
}

int Joystick::getY(const int min = 0, const int max = 255)
{
    return joyY->read(min, max);
}

//Return Y axis value de 0 to 255
int Joystick::getY()
{
    return getY(0, 255);
}

/**
* Return indication on joystick press.<BR>
* The joystick assembly button is '0' when not pressed, so we flip the button logic
*/
bool Joystick::getSW()
{
    return !joySW->onChange();
}
		