#include "TouchCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include <iostream>

using namespace std;


TouchCommand::TouchCommand(AbstractFileSystem* sys, AbstractFileFactory* facto):system(sys),factory(facto){}

int TouchCommand::execute(string bofa)
{
	AbstractFile* butts = factory->createFile(bofa);
	if (butts == nullptr) {
		cout << "could not create file" << endl;
		return 25;
	}
	int err = system->addFile(bofa, butts);
	if (err != 0) {
		delete(butts);
		cout << "file " << bofa << "could not be added to abstractFileSystem" << endl;
		return 26;
	}
	return 0;
}



void TouchCommand::displayInfo()
{
	std::cout << "touch creates a file, touch canbe invoked with the command : touch " << this << endl;
}
