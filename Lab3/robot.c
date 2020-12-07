#include "robot.h"

Robot createRobot(int serialNumber, char state[], char specialisation[], int energyCapacity)
{
	Robot robot;
	robot.serialNumber = serialNumber;
	strcpy(robot.state, state);
	strcpy(robot.specialisation, specialisation);
	robot.energyCapacity = energyCapacity;
	return robot;
}

int getSerialNumber(Robot robot)
{
	return robot.serialNumber;
}

char* getState(Robot* robot)
{
	return robot->state;
}

char* getSpecialisation(Robot* robot)
{
	return robot->specialisation;
}

int getEnergyCapacity(Robot robot)
{
	return robot.energyCapacity;
}
