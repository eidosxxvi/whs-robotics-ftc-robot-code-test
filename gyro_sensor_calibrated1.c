#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     gyroRobot,      sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     driveRight,    tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     driveLeft,     tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     armRight,      tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C2_2,     armLeft,       tmotorTetrix, PIDControl, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-gyro.h";

//--------------declarations-------------
float currentValue = 0.0;
float angleChange = 0.0;
float timeChange = 0.0;
float currTotalMove = 0.0;
float remainingTurn = 42.0;
float error = 0.0;
float gyroReading = 0.0;
float adjustedTarget = 0.0;

//--------------constants----------------
const float LOW_TURK = 0.75;
const float MID_TURK = 0.9;
const float HIGH_TURK = 10.0;
const float ADJUST_M = 1.0;//0.8905;
const float ADJUST_B = 7.0;//4.7182;


//--------------functions-----------------
float getAngleChange()
{
	gyroReading = HTGYROreadCal(3);
	currentValue = HTGYROreadRot(3);//gyroReading - BIAS;
	timeChange = time1[T1]/1000.0;
	ClearTimer(T1);
	angleChange = currentValue * timeChange;
	return angleChange;
}

float getCurrTotalMove()
{
	currTotalMove += getAngleChange();
	return currTotalMove;
}

//Turn at a certain speed (determined by speedK) until get to turnDirection
void gyroCenterPivot(int turnDirection, int speedKonstant)
{
	adjustedTarget = ADJUST_M * turnDirection - ADJUST_B;
	float turn = 100.0;
	while(abs(remainingTurn) > 1)
	{
		remainingTurn = adjustedTarget - currTotalMove;
		error = adjustedTarget - getCurrTotalMove();
		turn = error * speedKonstant;
		motor[driveLeft] = turn;
		motor[driveRight] = -turn;
		wait10Msec(1);
	}
	motor[driveLeft] = 0;
	motor[driveRight] = 0;
	currentValue = 0.0;
	angleChange = 0.0;
	timeChange = 0.0;
	currTotalMove = 0.0;
	remainingTurn = 42.0;
	error = 0.0;
	gyroReading = 0.0;
	adjustedTarget = 0.0;
}


//--------------main-------------------
task main()
{
	HTGYROstartCal(3);
	ClearTimer(T1);
	gyroCenterPivot(45, HIGH_TURK);
}
