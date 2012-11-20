#pragma config(Sensor, S2,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     gyroRobot,      sensorI2CHiTechnicGyro)
#pragma config(Sensor, S4,     gyroArm,        sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,          arm,           tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          driveLeft,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          driveRight,    tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//------------------initializations-----------------------------
	//Labels:
	string IRLabel = "IR avg1, avg2, diff:";
	string gyroRobotLabel = "gBot avg1, avg2, diff:";
	string gyroArmLabel = "gArm avg1, avg2, diff:";
	//Most recent avg:
	int IRAvg1 = 0;
	int gyroRobotAvg1 = 0;
	int gyroArmAvg1 = 0;
	//Previous avg:
	int IRAvg2 = 0;
	int gyroRobotAvg2 = 0;
	int gyroArmAvg2 = 0;
	//Change:
	float IRChange = 0;
	float gyroRobotChange = 0;
	float gyroArmChange = 0;


//-----------------------------functions-------------------------

/* 1 == IR
2 == gyroRobot
3 == gyroArm
*/
int getSensorValue(int sensor)
{
	if(sensor == 1)
	{
		return SensorValue[IR];
	}
	else if(sensor == 2)
	{
		return SensorValue[gyroRobot];
	}
	else if(sensor == 3)
	{
		return SensorValue[gyroArm];
	}
	else
	{
		return 0;
	}
}


/* 1 == IR
2 == gyroRobot
3 == gyroArm
*/
int calcAvg(int sensor)
{
	int values[50];
	int sum = 0;
	int avg = 0;

	for(int count = 0; count < 50; count++)
	{
		values[count] = getSensorValue(sensor);
		sum = sum + values[count];
		wait1Msec(20);
	}

	avg = sum / 50;
	return avg;
}


void updateSensorVals()
{
	IRAvg2 = IRAvg1;
	gyroRobotAvg2 = gyroRobotAvg1;
	gyroArmAvg2 = gyroArmAvg1;

	IRAvg1 = calcAvg(1);
	gyroRobotAvg1 = calcAvg(2);
	gyroArmAvg1 = calcAvg(3);

	IRChange = IRAvg1 - IRAvg2;
	gyroRobotChange = gyroRobotAvg1 - gyroRobotAvg2;
	gyroArmChange = gyroArmAvg1 - gyroArmAvg2;
}


void displaySensorVals()
{
	//Display IR value
	nxtDisplayString(1, "%s", IRLabel);
	nxtDisplayString(2, "%d, %d, %d", IRAvg1, IRAvg2, IRChange);

	//Display gyroRobot value
	nxtDisplayString(3, "%s", gyroRobotLabel);
	nxtDisplayString(4, "%d, %d, %d", gyroRobotAvg1, gyroRobotAvg2, gyroRobotChange);

	//Display gyroArm value
	nxtDisplayString(5, "%s", gyroArmLabel);
	nxtDisplayString(6, "%d, %d, %d", gyroArmAvg1, gyroArmAvg2, gyroArmChange);
}


//---------------------------main--------------------------
task main()
{
	eraseDisplay();

	IRAvg1 = calcAvg(1);
	gyroRobotAvg1 = calcAvg(2);
	gyroArmAvg1 = calcAvg(3);

	while(true)
	{
		updateSensorVals();
		displaySensorVals();
	}
}
