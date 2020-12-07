#include "service.h"


#define MAXIMUM_ARRAY_LENGHT 100

Service* createService(Repository* repository)
{
	Service* service = (Service*)malloc(sizeof(Service));
	if (service == NULL)
		return NULL;
	service->repository = repository;
	return service;
}

void destroyService(Service* service)
{
	free(service);
}

Repository* getRepository(Service* service)
{
	return service->repository;
}

int findRobot(Service* service, TElem robot)
{
	Repository* localRepositoryObject = service->repository;
	int length = getRepositoryLength(service->repository);
	for (int i = 0; i < length; i++)
		if (getSerialNumber(localRepositoryObject->arrayOfElements[i]) == getSerialNumber(robot))
			return 1;
	return 0;
}

int addRobotService(Service* service, int serialNumber, char* state, char* specialisation, int energyCapacity)
{
	Robot localRobotObject = createRobot(serialNumber, state, specialisation,energyCapacity);
	if (findRobot(service, localRobotObject) == 1)//exception
		return 1;
	addToRepository(service->repository, localRobotObject);
	return 0;
}

void updateRobotService(Service* service, int serialNumber, char* state, char* specialisation, int energyCapacity,int updateRobotSerialNumber)
{
	Robot robot = createRobot(serialNumber, state, specialisation, energyCapacity);
	int updateRobotIndex = getIndexOfRobot(service, updateRobotSerialNumber);
	updateRepository(service->repository, robot, updateRobotIndex);
}

int checkExistenceOfRobotWithSerialNumber(Service* service, int serialNumber)
{
	Repository* localRepositoryObject = service->repository;
	for (int i = 0; i < localRepositoryObject->length; i++)
		if (localRepositoryObject->arrayOfElements[i].serialNumber == serialNumber)
			return 1;
	return 0;
}

int getIndexOfRobot(Service* service, int serialNumber)
{
	Repository* localRepositoryObject = service->repository;
	for (int i = 0; i < localRepositoryObject->length; i++)
		if (localRepositoryObject->arrayOfElements[i].serialNumber == serialNumber)
			return i;
	return -1;
}

int deleteRobotService(Service* service, int serialNumber)//handle existence condition!
{
	if (checkExistenceOfRobotWithSerialNumber(service,serialNumber) == 0)
		return 1;
	int deleteRobotIndex = getIndexOfRobot(service, serialNumber);
	deleteFromRepository(service->repository, deleteRobotIndex);
	return 0;
}

Robot* getRobotsArray(Service* service)
{
	return service->repository->arrayOfElements;
}