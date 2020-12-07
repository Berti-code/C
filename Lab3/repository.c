#include "repository.h"



Repository* createRepository()
{
	Repository* repository = (Repository*)malloc(sizeof(Repository));
	if (repository == NULL)
		return NULL;
	repository->length = 0;
	return repository;
}

void destroyRepository(Repository* repository)
{
	free(repository);
}

int getRepositoryLength(Repository* repository)
{
	return repository->length;
}

void addToRepository(Repository* repository, TElem robot)
{
	repository->arrayOfElements[repository->length++] = robot;
}

void updateRepository(Repository* repository, TElem robot, int updateRobotIndex)
{
	repository->arrayOfElements[updateRobotIndex] = robot;
}

void deleteFromRepository(Repository* repository, int deleteRobotIndex)
{
	for (int i = deleteRobotIndex; i < repository->length - 1; i++)
	{
		repository->arrayOfElements[i] = repository->arrayOfElements[i + 1];
	}
	repository->length--;
}