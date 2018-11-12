/*
 * RoboticArm Class
 * 
 * Contains all of the servos of the arm
 * in the future, it could be used to easily
 * access complicated motions
 */
 
#ifndef RoboticArm_h
#define RoboticArm_h

#include "Arduino.h"
#include "Servo.h"


 


class RoboticArm
{
	public:
		RoboticArm(int p1 , int p2 , int p3 , int p4 , int p5 , int p6); //construct with the pins of all 6 servos
		
		Servo& getServo(int p); //return one of the servos, so that each one can be used individually
	private:
		Servo servoArray[6];
};
 
#endif