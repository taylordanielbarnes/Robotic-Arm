#include <Servo.h>
#include <Stick.h>
#include <Button.h>


//pinout
const int servoPin[5] = {3, 5, 6, 9, 10};
const int buttonPin = 4;
const int stickSwitchPin = 2;
const int stickAnalogPin = 0;

//parts of the robot and joystick
Servo servoArray[5]; //each servo in the robotic arm
int servoValue[5] = {90, 80, 90, 90, 45}; //values for each servo to hold
Stick controlStick(stickSwitchPin , stickAnalogPin); //stick used to control the servos of the robotic arm
Button toggle(buttonPin); //button to cycle through different servos

//variable that determines which servo will be controlled by each stick
int servoIndex = 0;

//value by which the servos increment
const int servoAdder[5] = {4, 1, 5, 5, 4};

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
    servoIndex++;

    //keep it between 0 and 5
    if(servoIndex == 5)
      servoIndex = 0;

    Serial.println(servoIndex);
  }

  //push servo forward until limit
  if(controlStick.isUp() && servoValue[servoIndex] < upperLimit[servoIndex])
  {
    servoValue[servoIndex] += servoAdder[servoIndex];
    Serial.println(servoValue[servoIndex]);
    delay(20);
  }
  //push servo backward until limit
  if(controlStick.isDown() && servoValue[servoIndex] > lowerLimit[servoIndex])
  {
    servoValue[servoIndex] -= servoAdder[servoIndex];
    Serial.println(servoValue[servoIndex]);
    delay(20);
  }

}
