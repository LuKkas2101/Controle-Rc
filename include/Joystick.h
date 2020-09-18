/** \addtogroup Joystick 
 *  @{
 */

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "AnalogReader.h"
#include "Button.h"

class Joystick 
{
	public:
		Joystick(int pinX, int pinY, int pinSW);

		int getX();
		int getX(const int min, const int max);

		int getY();
		int getY(const int min, const int max);

		//return indication on joystick press
		//The joystick assembly button is '0' when not pressed, so we flip the button logic
		bool getSW();
		
	private:
		Button		 *joySW;
		AnalogReader *joyX;
		AnalogReader *joyY;
		int			 m_pinX;
		int			 m_pinY;
		int			 m_pinSW;
		

};
#endif //JOYSTICK
/** @}*/