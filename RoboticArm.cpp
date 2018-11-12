/*
 * RoboticArm Class
 * 
 * Contains all of the servos of the arm
 * in the future, it could be used to easily
 * access complicated motions
 */
 
#include "Arduino.h"
#include "RoboticArm.h"
 
 
 
 
 
//constructor
//create all six servos
RoboticArm::RoboticArm(int p1 , int p2 , int p3 , int p4 , int p5 , int p6)
{
	servoArray[0].attach(p1);
	servoArray[1].attach(p2);
	servoArray[2].attach(p3);
	servoArray[3].attach(p4);
	servoArray[4].attach(p5);
	servoArray[5].attach(p6);
}

//return one of the six servos of the arm
Servo& RoboticArm::getServo(int p)
{
	switch(p)
	{
		case 1:
			return servoArray[0];
		case 2:
			return servoArray[1];
		case 3:
			return servoArray[2];
		case 4:
			return servoArray[3];
		case 5:
			return servoArray[4];
		case 6:
			return servoArray[5];
	}
}