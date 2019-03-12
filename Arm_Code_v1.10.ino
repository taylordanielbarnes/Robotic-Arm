#include <Servo.h>
#include <Stick.h>
#include <Button.h>


//pinout
const int servoPin[5] = {3, 5, 6, 9, 10};
const int buttonPin = 4;
const int stickSwitchPin = 2;
const int stickAnalogPin = 0;

Servo servoArray[5]; //each servo in the robotic arm
int servoValue[5] = {90, 80, 90, 90, 45}; //values for each servo to hold
const int servoAdder[5] = {4, 1, 5, 5, 4}; //value by which the servos increment

//parts of the robot and joystick
Stick controlStick(stickSwitchPin , stickAnalogPin); //stick used to control the servos of the robotic arm
Button toggle(buttonPin); //button to cycle through different servos

//variable that determines which servo will be controlled by each stick
int toggleValue = 0;

//variables that mark where the servo has to stop
//some are different because the periods of rotation are slightly different
int lowerLimit[5] = {10, 5, 10, 10, 25};
int upperLimit[5] = {170, 170, 170, 170, 100};


void setup() 
{
  Serial.begin(9600);

  //pinout: the sequel
  for(int index = 0; index < 5; index++)
  {
    servoArray[index].attach(servoPin[index]);
  }
}

void loop()
{
  //start each loop by making sure each servo angle is up to date
  for(int index = 0; index < 5; index++)
  {
    servoArray[index].write(servoValue[index]);
  }
  
  //check to see if the button is pressed.
  //if so, increment which servo is attached to the stick
  if(toggle.isDepressed())
  {
    toggleValue++;

    //keep it between 0 and 5
    if(toggleValue == 5)
      toggleValue = 0;

    Serial.println(toggleValue);
  }

  //push servo forward until limit
  if(controlStick.isUp() && servoValue[toggleValue] < upperLimit[toggleValue])
  {
    servoValue[toggleValue] += servoAdder[toggleValue];
    Serial.println(servoValue[toggleValue]);
    delay(20);
  }
  //push servo backward until limit
  if(controlStick.isDown() && servoValue[toggleValue] > lowerLimit[toggleValue])
  {
    servoValue[toggleValue] -= servoAdder[toggleValue];
    Serial.println(servoValue[toggleValue]);
    delay(20);
  }

}
