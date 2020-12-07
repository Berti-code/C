#pragma once
#include "repository.h"


typedef struct
{
	Repository* repository;
}Service;

Service* createService(Repository* repository);

void destroyService(Service* service);

Repository* getRepository(Service* repository);

int findRobot(Service* repository, TElem robot);

int addRobotService(Service* service,int serialNumber, char* state, char* specialisation, int energyCapacity);

void updateRobotService(Service* service,int serialNumber,char* state,char* specialisation,int energyCapacity,int updateRobotSerialNumber);

int getIndexOfRobot(Service* service, int serialNumber);

int deleteRobotService(Service* service,int serialNumber);//handle existence condition!

Robot* getRobotsArray(Service* service);