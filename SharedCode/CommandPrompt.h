#pragma once
#include<map>
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include<string>

using namespace std;

class CommandPrompt {//: public AbstractCommand{
private:
	map<string, AbstractCommand*> commandMap;
	AbstractFileSystem* sys;
	AbstractFileFactory* facto;
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(string, AbstractCommand*);

	int run();
protected:
	void listCommands(); //not explicitly void, but only prints
	string prompt();
};