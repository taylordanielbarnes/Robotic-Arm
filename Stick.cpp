/*
 * Stick Class
 *
 * Makes it easy to use analog sticks
 * probably just along one axis for now,
 * but it should be pretty easily scalable
 */

#include "Arduino.h"
#include "Stick.h"





//constructor
//configure the sensor to the right pins
Stick::Stick(int swP , int aP)
{
	swPin = swP;
	aPin = aP;

	pinMode(swPin , OUTPUT);
	digitalWrite(swPin , HIGH);
}



//check the stick to see if it is being pushed up
//so we know when to start moving servos
bool Stick::isUp()
{
	if(analogRead(aPin) > 800)
	{
		return true;
	}
	
	return false;
}



//check the stick to see if it is being pushed down
//so we know when to start moving servos the other direction
bool Stick::isDown()
{
	if(analogRead(aPin) < 200)
	{
		return true;
	}
	
	return false;
}



//output the data on the stick's position
String Stick::toString()
{
	//String placeHold = String(analogRead(aPin));
	return(String(analogRead(aPin)));
}