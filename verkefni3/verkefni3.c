#pragma config(Sensor, dgt4  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgt5 leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port1,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port10,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Sensor, in1,    light_sensor,   sensorReflection)
#pragma config(Sensor, dgtl2,  robot_stop,     sensorTouch)
#pragma config(Sensor, dgtl3,  sonar_sensor,   sensorSONAR_cm)


#define BASETURN 300
#define BASELIGHT 700
task stop_all(){
	while(!robot_stop || vexRT[Btn5D]!=1){
	}
	StopAllTasks();
}
void turn(int deg){

}

task main()
{
	StartTask(stop_all);
	while(true){
		while(light_sensor < BASELIGHT || sonar_sensor < 50 )		// Creates an infinite loop, since "true" always evaluates to true
		{
			if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) // If rightEncoder has counted the same amount as leftEncoder:
			{
			// Move Forward
			motor[rightMotor] = 80;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 80;		    // Left Motor is run at power level 80
			}
			else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])	// If rightEncoder has counted more encoder counts
			{
			// Turn slightly right
			motor[rightMotor] = 60;		    // Right Motor is run at power level 60
			motor[leftMotor]  = 80;		    // Left Motor is run at power level 80
			}
			else	// Only runs if leftEncoder has counted more encoder counts
			{
			// Turn slightly left
			motor[rightMotor] = 80;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 60;		    // Left Motor is run at power level 60
			}
	}
	turn(90);
}
