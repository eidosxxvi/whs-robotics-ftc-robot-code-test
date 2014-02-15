#pragma config(Hubs, S1, HTMotor, HTMotor, HTMotor, HTServo)
#pragma config(Sensor, S1, , sensorI2CMuxController)
#pragma config(Sensor, S2, touchSensor, sensorTouch)
#pragma config(Sensor, S3, IRSensor, sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4, gyroSensor, sensorI2CHiTechnicGyro)
#pragma config(Motor, motorA, rightIntake, tmotorNXT, PIDControl, encoder)
#pragma config(Motor, motorB, leftIntake, tmotorNXT, PIDControl, encoder)
#pragma config(Motor, motorC, , tmotorNXT, openLoop)
#pragma config(Motor, mtr_S1_C1_1, leftDrive, tmotorTetrix, PIDControl, reversed)
#pragma config(Motor, mtr_S1_C1_2, rightDrive, tmotorTetrix, PIDControl)
#pragma config(Motor, mtr_S1_C2_1, leftArm, tmotorTetrix, openLoop, reversed)
#pragma config(Motor, mtr_S1_C2_2, rightArm, tmotorTetrix, openLoop)
#pragma config(Motor, mtr_S1_C3_1, hang1, tmotorTetrix, openLoop)
#pragma config(Motor, mtr_S1_C3_2, hang2, tmotorTetrix, openLoop, reversed)
#pragma config(Servo, srvo_S1_C4_1, flagServo, tServoStandard)
#pragma config(Servo, srvo_S1_C4_2, servo2, tServoNone)
#pragma config(Servo, srvo_S1_C4_3, autoServo, tServoStandard)
#pragma config(Servo, srvo_S1_C4_4, intakeServo, tServoStandard)
#pragma config(Servo, srvo_S1_C4_5, hangServo1, tServoStandard)
#pragma config(Servo, srvo_S1_C4_6, hangServo2, tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard       !!*//


/**********************************
** WHS Robotics  |  FTC Team 542 **
** Block Party! 2013-2014 Season **
** Charge (Ramp)                 **
** Main  |  Right  |  V1         **
***********************************/
///////////////////INCLUDES///////////////////
#include "JoystickDriver.c" //driver for receiving bluetooth msgs
#include "arps_functions1.h" //header file for ARP Functions

//INITIALIZATION//
void initializeRobot()
{
	resetBucket();

	//reset DT motors? idk
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
	servo[autoServo] = 15;
	//Clear Timers T1 and T2
	ClearTimer(T1);

	//beep to signal end of initialization
	PlayTone(440,30);
	return;
}


//MAIN//
task main()
{
	initializeRobot();
	waitForStart();
	//-----------------CHARGE BEGIN------------------------
	//---Move forward
	motor[leftDrive] = 100;
	motor[rightDrive] = 100;
	wait1Msec(700);
	//---Turn Right
	gyroCenterPivot(48.0, 100);
	//---Move forward
	moveStraight(27.0, 100);
	scoreAutoArm();

	stopDriveTrain();
}