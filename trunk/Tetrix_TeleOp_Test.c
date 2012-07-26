#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c";

task main()
{
  while(true)
  {
    getJoystickSettings(joystick);
    int y1 = joystick.joy1_y1;
    int y2 = joystick.joy1_y2;

    motor[motorD] = y2; //back right motor
    motor[motorE] = y1; //back left motor
    if(joy1Btn(1) == 1)
    {
      powerOff();
    }
  }
}
