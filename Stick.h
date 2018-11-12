/*
 * Stick Class
 *
 * Makes it easy to use analog sticks
 * probably just along one axis for now,
 * but it should be pretty easily scalable
 */

#ifndef Stick_h
#define Stick_h

#include "Arduino.h"





class Stick
{
	public:
		Stick(int swP , int aP); //construct with a switch pin and an analog pin

		bool isUp(); //check to see if the stick is pushed upward
		bool isDown(); //or down

		String toString(); //output info on the stick's position
	private:
		int swPin; //the number for which the switch pin is plugged in
		int aPin; //the number for which the sensing pin is plugged in
};

#endif