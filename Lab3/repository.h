#pragma once
#include "robot.h"
#include <stdlib.h>

#define MAXIMUM_ARRAY_LENGHT 100

typedef Robot TElem;

typedef struct 
{
	TElem arrayOfElements[MAXIMUM_ARRAY_LENGHT];
	int length;
}Repository;

Repository* createRepository();

void destroyRepository(Repository* repository);

int getRepositoryLength(Repository* repository);

void addToRepository(Repository* repository,Robot robot);

void updateRepository(Repository* repository,Robot robot,int updateRobotIndex);

void deleteFromRepository(Repository* repository,int deleteRobotIndex);