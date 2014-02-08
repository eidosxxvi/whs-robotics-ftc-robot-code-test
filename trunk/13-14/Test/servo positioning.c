#pragma config(Hubs,  S3, HTServo,  HTServo,  none,     none)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Servo,  srvo_S3_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_3,    elServo,              tServoStandard)
#pragma config(Servo,  srvo_S3_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
#pragma config(Servo,  srvo_S3_C2_1,    servo7,               tServoNone)
#pragma config(Servo,  srvo_S3_C2_2,    servo8,               tServoNone)
#pragma config(Servo,  srvo_S3_C2_3,    elServo2,             tServoStandard)
#pragma config(Servo,  srvo_S3_C2_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S3_C2_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S3_C2_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	servo[elServo2] = 240.0;
	wait1Msec(1000);
	PlayTone(300, 30);
	servo[elServo2] = 40.0;//128.0+120.0*(256.0/180.0); //open
	wait1Msec(5000);
	PlayTone(500,30);
}
