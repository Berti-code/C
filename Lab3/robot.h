#pragma once
#include <string.h>

typedef struct
{
	int serialNumber;
	char state[50];
	char specialisation[50];
	int energyCapacity;
}Robot;

/*
Creates a robot with the required fields
Input:  serialNumber - int
		state - array of characters
		specialisation - array of characters
		energyCapacity - int
*/

Robot createRobot(int serialNumber, char state[], char specialisation[], int energyCapacity);

int getSerialNumber(Robot robot);

char* getState(Robot* robot);

char* getSpecialisation(Robot* robot);

int getEnergyCapacity(Robot robot);