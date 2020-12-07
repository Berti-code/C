#pragma once
#include "service.h"
#include <stdio.h>


typedef struct
{
	Service* service;
}Console;

Console* createConsole(Service* service);

void destroyConsole(Console* console);

Service* getService(Console* service);

Repository* getRepositoryFromConsole(Console* console);

void addRobotConsole(Console* console, char* arguments);

void updateRobotConsole(Console* console, char* arguments);

void deleteRobotConsole(Console* console, char* arguments);

void listConsole(Console* console);

void listBySpecialisation(Console* console, char specialisation[]);

void listOperation(Console* console, char arguments[]);

int readCommand(Console* console);