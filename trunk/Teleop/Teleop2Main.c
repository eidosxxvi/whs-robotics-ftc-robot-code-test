#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S2,     HTSMUX,         sensorI2CCustom)
#pragma config(Motor,  motorB,          flagLeft,      tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          flagRight,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     driveRight,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     driveLeft,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     armRight,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     armLeft,       tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**********************************
** WHS Robotics  |  FTC Team 542 **
** Ring It Up! 2012-2013 Season  **
** Tele-Op Program 2.0           **
** Main                          **
***********************************/

///////////////////////////INCLUDES////////////////////////////
#include "Teleop2Tasks.h" //Tele-op tasks



///////////////////////GLOBAL VARIABLES////////////////////////
const int JOY_THRESHOLD = 25;
const int SLOW_FACTOR = 3;
const float MOTOR_MAX = 100.0;
const float MOTOR_MIN = 0.0;
const float JOY_MAX = 128.0;
const float JOY_MIN = -127.0;
const float SCALE_JOYMOT = (MOTOR_MAX - MOTOR_MIN)/(JOY_MAX - JOY_MIN);


int driveLeftPwr = 0;
int driveRightPwr = 0;
int LJoy = 0;
int RJoy = 0;



////////////////////////INITIALIZATION/////////////////////////
void initializeRobot()
{
  resetFlags(); //initialize flag positions and timer

  PlayTone(400,30); //because it's Windsor
  return;
}



/////////////////////////FUNCTIONS/////////////////////////////
int scalePow(int rawPow, bool NormalSpeed)
{
	float finalPow = 0;

	//find the proportional motor power using ratio of motor to joystick
	finalPow = SCALE_JOYMOT * rawPow;

	if(NormalSpeed)
	{
		return finalPow;
	}
	else //slower speed
	{
		return (finalPow/SLOW_FACTOR);
	}
}



////////////////////////////MAIN///////////////////////////////
task main()
{
  initializeRobot();
  waitForStart();


  //Start all other tasks
	StartTask(Arm);
	StartTask(Flags);

	//Control Drive Train
  while (true)
  {
	  getJoystickSettings(joystick); //update joystick readings
		LJoy = joystick.joy1_y1;
		RJoy = joystick.joy1_y2;

	  //Slow drive speed when L1 pressed
	  if (joy1Btn(5) == true)
    {
    	//Left drive train, slow
    	if(abs(LJoy) > JOY_THRESHOLD) //stat. sig. val. from left joystick
    	{
      	driveLeftPwr = scalePow(LJoy, false); //scale left joystick slower
      }
     	else //not stat. sig. val. from left joystick
     	{
     		driveLeftPwr = STOP;
     	}
      //Right drive train, slow
     	if(abs(RJoy) > JOY_THRESHOLD) //stat. sig. val. from right joystick
     	{
      	driveRightPwr = scalePow(RJoy, false); //scale right joystick slower
      }
     	else //not stat. sig. val. from right joystick
     	{
     		driveRightPwr = STOP;
     	}
    }

    //Normal drive speed (nothing pressed)
    else
    {
    	//Left drive train
    	if(abs(LJoy) > JOY_THRESHOLD) //stat. sig. val. from left joystick
    	{
      	driveLeftPwr = scalePow(LJoy, true); //set left DT pow to left joystick
      }
     	else //not stat. sig. val. from left joystick
     	{
     		driveLeftPwr = STOP;
     	}
      //Right drive train
     	if(abs(RJoy) > JOY_THRESHOLD) //stat. sig. val. from right joystick
     	{
      	driveRightPwr = scalePow(RJoy, true); //set right DT pow to right joystick
      }
     	else //not stat. sig. val. from right joystick
     	{
     		driveRightPwr = STOP;
     	}
    }

    //Move drive train with set speeds
    motor[driveLeft] = driveLeftPwr;
    motor[driveRight] = driveRightPwr;
  }
}
