#include <Stick.h>
#include <Button.h>
#include <RoboticArm.h>


//pinout
const int servoPin1 = 1;
const int servoPin2 = 2;
const int servoPin3 = 3;
const int servoPin4 = 4;
const int servoPin5 = 5;
const int servoPin6 = 6;

const int leftStickSwitchPin = 7;
const int leftStickAnalogPin = 1;
const int rightStickSwitchPin = 8;
const int rightStickAnalogPin = 2;

const int leftButtonPin = 9;
const int rightButtonPin = 10;

//parts of the robot and joystick
RoboticArm arm(servoPin1 , servoPin2 , servoPin3 , servoPin4 , servoPin5 , servoPin6); //define the digital ports of the servos
Stick leftStick(leftStickSwitchPin , leftStickAnalogPin); //two sticks used to control
Stick rightStick(rightStickSwitchPin , rightStickAnalogPin); //the servos of the arm
Button leftButton(leftButtonPin); //two buttons to cycle through
Button rightButton(rightButtonPin); //options for the sticks

//variables that determine which servo will be controlled by each stick
int leftValue = 1;
int rightValue = 2;



void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  //check to see if the left button is pressed.
  //if so, increment which servo is attached to the left stick
  if(leftButton.isDepressed())
  {
    leftValue++;

    //keep it between 1 and 6
    if(leftValue == 7)
      leftValue = 1;

    //make sure the two sticks are unique
    if(leftValue == rightValue)
      leftValue++;
  }

  //check to see if the right button is pressed.
  //if so, increment which servo is attached to the right stick
  if(rightButton.isDepressed())
  {
    rightValue++;

    //keep it between 1 and 6
    if(rightValue == 7)
      rightValue = 1;

    //make sure the two sticks are unique
    if(leftValue == rightValue)
      rightValue++;
  }

  //move a servo dependent on the left stick
  if(leftStick.isUp())
  {
    arm.getServo(leftValue).write(180);
    delay(500);
  }
  else if(leftStick.isDown())
  {
    arm.getServo(leftValue).write(0);
    delay(500);
  }

  //move a servo dependent on the right stick
  if(rightStick.isUp())
  {
    arm.getServo(rightValue).write(180);
    delay(500);
  }
  else if(rightStick.isDown())
  {
    arm.getServo(rightValue).write(0);
    delay(500);
  }
}
