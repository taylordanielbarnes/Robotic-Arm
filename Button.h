/*
 * Button Class
 * 
 * Makes it easy and intuitive to use
 * buttons on a controller
 */

#ifndef Button_h
#define Button_h

#include "Arduino.h"





class Button
{
	public:
		Button(int p); //construct with a pin number for the button

		bool isDepressed(); //return true if the button is being pressed

		String toString(); //give the value for whether it is depressed
	private:
		int pinNo; //the pin number to use
};

#endif