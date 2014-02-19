#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S3, HTServo,  HTServo,  none,     none)
#pragma config(Sensor, S2,     IRSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     ,               sensorI2CCustom)
#pragma config(Motor,  motorA,          hangmanMot,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          intakeL,       tmotorNXT, PIDControl, reversed, encoder)
#pragma config(Motor,  motorC,          intakeR,       tmotorNXT, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     sweBL,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     armL,          tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     sweFL,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     flagMot,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     sweBR,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     armR,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     sweFR,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     winchMot,      tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S3_C1_1,    swiFR,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    swiBR,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    dropbox,              tServoStandard)
#pragma config(Servo,  srvo_S3_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
#pragma config(Servo,  srvo_S3_C2_1,    swiFL,                tServoStandard)
#pragma config(Servo,  srvo_S3_C2_2,    swiBL,                tServoStandard)
#pragma config(Servo,  srvo_S3_C2_3,    antiRatchet,          tServoStandard)
#pragma config(Servo,  srvo_S3_C2_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S3_C2_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S3_C2_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "arps_functions_swedr.h"
#include "auto_globVars_swedr.h"
/////////DUMP AUTONOMOUS/////////

void initializeRobot()
{
	servo[swiFL] = 97;
	servo[swiBL] = 127;
	servo[swiFR] = 127;
	servo[swiBR] = 147;

	muxUpdateInterval = 1;
	servoChangeRate[swiFL] = 0;
	servoChangeRate[swiFR] = 0;
	servoChangeRate[swiBR] = 0;
	servoChangeRate[swiBL] = 0;
	StartTask(HoldBox);//servo[dropbox] = 255;
	StartTask(AntiRat);
	return;
}

task main()
{
	initializeRobot();

	waitForStart();
	StartTask(hangArmMaintain);
	StartTask(RampArm);
	moveStraight(55.0, 65.0, 75.0);	     //have the motor go at 100 power
	while(true){}
}
