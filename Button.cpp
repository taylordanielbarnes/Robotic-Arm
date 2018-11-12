/*
 * Button Class
 *
 * Makes it easy and intuitive to use
 * buttons on a controller
 */

#include "Arduino.h"
#include "Button.h"





//constructor
//configure pinNo to digital input
Button::Button(int p)
{
	pinNo = p;
	pinMode(pinNo , INPUT);
}



//check to see if the button is pressed once
//if it is, return true
//if not, return false
bool Button::isDepressed()
{
	if(digitalRead(pinNo))
	{
		delay(35);
		
		if(!digitalRead(pinNo))
		{
			return true;
		}
	}

	return false;
}



//string info
//tells if the button is being pressed
String Button::toString()
{
	if(digitalRead(pinNo))
	{
		return("TRUE");
	}
	else if(!digitalRead(pinNo))
	{
		return("FALSE");
	}
}