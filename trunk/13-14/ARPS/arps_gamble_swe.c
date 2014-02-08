//#include "whateverItMayBe"



task main()
{
	waitForStart();
	raiseArm = true;
	wait1Msec(300);
	if(SensorValue[IRSensor] <= 4 && SensorValue[IRSensor] != 0)
	{
		crate = 1;
	}
	else if(SensorValue[IRSensor] == 5)
	{
		crate = 2;
	}
	else if(SensorValue[IRSensor] == 0)//added in SensorValue, it caused everything to go wrong
	{
		crate = 3;
	}
	moveStraight(90.0, 30.0, 100)//---Move forward
	gyroCenterPivot(45, 100)//---Move towards the ramp by having servos turn and then moving forward

	if(crate == 2)							//this crate would have to be the closest one to us
	{
		moveStraight(90.0, 30.0, 100)				//motors would be going at 100 power
		gyroCenterPivot(90, 100)
		dropTheBlock;												//drop the cube into the second crate
	}
	else if(crate == 3)
	{
		moveStraight(90.0, 40.0, 100)				//motors would be going at 100 power
		gyroCenterPivot(90, 100)						//robot will turn 90 degrees to the right
		dropTheBlock;												//drop the cube into the third crate
	}
	else
	{
		moveStraight(90.0, 15.0, 100)				//Robot will go forward for 15 inches at 100 power.
		gyroCenterPivot(90, 100)						//robot will turn 90 degrees to the right
		dropTheBlock;												//drop the cube into the first crate
	}
}
