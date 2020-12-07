#include "console.h"


int main()
{
	Repository* repositoryObject = createRepository();
	Service* serviceObject = createService(repositoryObject);
	Console* consoleObject = createConsole(serviceObject);
	
	readCommand(consoleObject);
	return 0;
}