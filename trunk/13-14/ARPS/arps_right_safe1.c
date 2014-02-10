#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     touchSensor,    sensorTouch)
#pragma config(Sensor, S3,     IRSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     gyroSensor,     sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,          rightIntake,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftIntake,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     leftDrive,     tmotorTetrix, PIDControl, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     rightDrive,    tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C2_1,     leftArm,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     rightArm,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     hang1,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     hang2,         tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    flagServo,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    autoServo,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    intakeServo,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    hangServo1,           tServoStandard)
#pragma config(Servo,  srvo_S1_C4_6,    hangServo2,           tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


/**********************************
** WHS Robotics  |  FTC Team 542 **
** Block Party! 2013-2014 Season **
** Safe (Ramp + Score)           **
** Main  |  Red  |  V1           **
***********************************/

////////////////////////INCLUDES////////////////////
#include "JoystickDriver.c"; //driver for receiving bluetooth msgs
#include "arps_functions1.h"; //header file for ARP Functions


///////////INITIALIZATION////////////
bool needArm = false;
//////Servo Position KONSTANTS//////
const int HANG_POS_ONE = 60;
const int HANG_END_ONE = 250;
const int HANG_POS_TWO = 180;
const int HANG_END_TWO = 0;


///////////TASKS///////////////
task Arm()
{
	while(needArm)
	{
		moveArm(100);
		wait1Msec(750);
		moveArm(0);
		needArm = false;
	}
}



void initializeRobot()
{
		servoTarget[hangServo1] = HANG_POS_ONE;
	servoTarget[hangServo2] = HANG_POS_TWO;
	servo[intakeServo] = 80;
	wait1Msec(1000);
  //resetHang(); //hang arm
  //resetBucket(); //DO NOT reset the NXT motors!!

	//reset drive train encoders
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;

	HTGYROstartCal(gyroSensor); //calibrate gyro

	StartTask(Arm);

	//beep to signal end of initialization
	PlayTone(440, 30);

  return;
}



//////////////MAIN/////////////

task main()
{
	initializeRobot();

	waitForStart();

	servoTarget[intakeServo] = 80;
	//----------SAFE BEGIN------------
			moveArm(100);
		wait1Msec(700);
		moveArm(0);
	//---Move forward
	moveStraight(6.0,100);
	stopDriveTrain();
	//---Turn Right
	gyroCenterPivot(45,100);
	stopDriveTrain();

	//---Move forward
	moveStraight(20.0, 100);
	stopDriveTrain();


	//---Score
	servo[intakeServo] = 150;
	wait1Msec(700);
	//---Move forward to get on ramp.
	moveStraight(15.0, -100);
	stopDriveTrain();

	gyroCenterPivot(-30,100);
	stopDriveTrain();

	moveStraight(60.0, 100);
	stopDriveTrain();
	//---Close box
	servo[intakeServo] = 80;
	wait1Msec(5000);
}
