#include <Servo.h>
#include <Stick.h>
#include <Button.h>


//pinout
const int servoPin[6] = {3, 5, 6, 9, 10, 11};
const int leftButtonPin = 4;
const int leftStickSwitchPin = 2;
const int leftStickAnalogPin = 0;

Servo servoArray[6]; //each servo in the robotic arm
int servoValue[6] = {90, 90, 90, 90, 90, 90}; //values for each servo to hold
const int servoAdder = 5; //value by which the servo increments

//parts of the robot and joystick
Stick leftStick(leftStickSwitchPin , leftStickAnalogPin); //two sticks used to control the servos of the robotic arm
Button leftButton(leftButtonPin); //two buttons to cycle through different stick congigurations

//variables that determine which servo will be controlled by each stick
int leftValue = 0;



void setup() 
{
  Serial.begin(9600);

  //pinout: the sequel
  for(int index = 0; index < 6; index++)
  {
    servoArray[index].attach(servoPin[index]);
  }
}

void loop()
{
  //start each loop by making sure each servo angle is up to date
  for(int index = 0; index < 6; index++)
  {
    servoArray[index].write(servoValue[index]);
  }
  
  //check to see if the left button is pressed.
  //if so, increment which servo is attached to the left stick
  if(leftButton.isDepressed())
  {
    leftValue++;

    //keep it between 0 and 5
    if(leftValue == 6)
      leftValue = 0;

    Serial.println(leftValue);
  }

  //push servo forwared until limit
  if(leftStick.isUp() && servoValue[leftValue] < 170)
  {
    servoValue[leftValue] += servoAdder;
    Serial.println(servoValue[leftValue]);
    delay(20);
  }
  //push servo backward until limit
  if(leftStick.isDown() && servoValue[leftValue] > 10)
  {
    servoValue[leftValue] -= servoAdder;
    Serial.println(servoValue[leftValue]);
    delay(20);
  }

}
