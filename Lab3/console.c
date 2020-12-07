#include "console.h"


Console* createConsole(Service* service)
{
	Console* console = (Console*)malloc(sizeof(Console));
	if (console == NULL)
		return NULL;
	console->service = service;
	return console;
}

void destroyConsole(Console* console)//free all the others!
{
	free(console);
}

Service* getService(Console* console)
{
	return console->service;
}

Repository* getRepositoryFromConsole(Console* console)
{
	return getService(console)->repository;
}

void transformArguments(Console* console, char* arguments, int* serialNumber, char* state, char* specialisation, int* energyCapacity)
{
	//This function extracts and transforms the arguments from an array of characters
	//to a 
	//get the serialNumber
	char* argument = strtok(arguments, ", ");
	*serialNumber = atoi(argument);
	//get the state
	int index = 0;
	while (arguments[index] != ' ') index++;
	strcpy(arguments, arguments + index + 1);
	argument = strtok(arguments, ", ");
	strcpy(state, argument);
	//get the specialisation
	index = 0;
	while (arguments[index] != ' ') index++;
	strcpy(arguments, arguments + index + 1);
	argument = strtok(arguments, ", ");
	strcpy(specialisation, argument);
	//get the energyCapacity
	index = 0;
	while (arguments[index] != ' ') index++;
	strcpy(arguments, arguments + index + 1);
	argument = strtok(arguments, ", ");
	*energyCapacity = atoi(argument);
}

void addRobotConsole(Console* console, char* arguments)
{
	int serialNumber, energyCapacity;
	char state[MAXIMUM_ARRAY_LENGHT], specialisation[MAXIMUM_ARRAY_LENGHT];
	transformArguments(console,arguments,&serialNumber,state,specialisation,&energyCapacity);
	int functionThrowsExeption = addRobotService(console->service, serialNumber, state, specialisation, energyCapacity);
	if (functionThrowsExeption == 1) printf("No!\n");
}

void updateRobotConsole(Console* console, char* arguments)
{
	int serialNumber, energyCapacity, updateRobotSerialNumber;
	char state[MAXIMUM_ARRAY_LENGHT], specialisation[MAXIMUM_ARRAY_LENGHT];
	transformArguments(console, arguments, &serialNumber, state, specialisation, &energyCapacity);
	updateRobotSerialNumber = serialNumber;
	updateRobotService(console->service, serialNumber, state, specialisation, energyCapacity, updateRobotSerialNumber);
}

void deleteRobotConsole(Console* console, char* arguments)
{
	int deleteRobotSerialNumber = atoi(arguments);
	int functionThrowsExeption = deleteRobotService(console->service, deleteRobotSerialNumber);
	if(functionThrowsExeption) printf("No!\n");
}

void listConsole(Console* console)
{
	Repository* localRepository = getRepositoryFromConsole(console);
	int robotsArrayLenght = localRepository->length;
	for (int i = 0; i < robotsArrayLenght; i++)
	{
		printf("Serial Number= "); printf("%d\n", localRepository->arrayOfElements[i].serialNumber); 
		printf("State: "); printf("%s\n", localRepository->arrayOfElements[i].state); 
		printf("Specialisation: "); printf("%s\n", localRepository->arrayOfElements[i].specialisation); 
		printf("Energy Capacity= "); printf("%d\n", localRepository->arrayOfElements[i].energyCapacity); 
	}
}

void listBySpecialisation(Console* console, char specialisation[])
{
	Repository* localRepositoryObject = getRepositoryFromConsole(console);
	int arrayLength = localRepositoryObject->length;
	TElem* pointerToRobots = localRepositoryObject->arrayOfElements;
	for (int i = 0; i < arrayLength; i++)
	{
		if (strcmp(pointerToRobots[i].specialisation, specialisation) == 0)
		{
			printf("Serial Number= "); printf("%d\n", (pointerToRobots + i)->serialNumber);
			printf("State: "); printf("%s\n", (pointerToRobots + i)->state);
			printf("Specialisation: "); printf("%s\n", (pointerToRobots + i)->specialisation);
			printf("Energy Capacity= "); printf("%d\n", (pointerToRobots + i)->energyCapacity);
		}
	}
}

void listOperation(Console* console,char arguments[])
{
	if (strlen(arguments) == 0)
		listConsole(console);
	else
	{
		char specialisation[MAXIMUM_ARRAY_LENGHT];
		char* token = strtok(arguments, ", ");
		strcpy(specialisation, token);
		listBySpecialisation(console, specialisation);
	}
}

void callTheRequiredFunction(Console* console, char* operationKeyWord,char* arguments)
{
	if (strcmp(operationKeyWord, "add") == 0)
		addRobotConsole(console, arguments);
	if (strcmp(operationKeyWord, "update") == 0)
		updateRobotConsole(console, arguments);
	if (strcmp(operationKeyWord, "delete") == 0)
		deleteRobotConsole(console, arguments);
	if (strcmp(operationKeyWord, "list") == 0)
		listOperation(console, arguments);
}

int readCommand(Console* console)
{
	char separator[] = " ,";
	char command[MAXIMUM_ARRAY_LENGHT];
	char arguments[MAXIMUM_ARRAY_LENGHT];
	int index = 0;
	char state[MAXIMUM_ARRAY_LENGHT], specialisation[MAXIMUM_ARRAY_LENGHT];

	do
	{
		gets(command);
		for (;;)//get the index of the first space character
		{
			if (command[index] == ' ') break;
			if (command[index] == '\0')
			{
				command[index + 1] = '\0';
				break;
			}
			index++;
		}
		strcpy(arguments, command + index + 1);
		command[index] = '\0';
		char* operationKeyWord = command;
		callTheRequiredFunction(console, operationKeyWord, arguments);
	} while (strcmp(command, "exit") != 0);
	return 0;
}