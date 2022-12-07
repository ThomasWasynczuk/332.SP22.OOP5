#pragma once
#include "AbstractCommand.h"
#include <string>
class AbstractFileFactory;
class AbstractFileSystem;
//#include "AbstractFileFactory.h"
//#include "AbstractFileSystem.h"

class TouchCommand : public AbstractCommand {
public:
	TouchCommand(AbstractFileSystem* sys, AbstractFileFactory* facto);
	virtual int execute(std::string bofa) override;
	virtual void displayInfo() override;

private:
	AbstractFileSystem* system;
	AbstractFileFactory* factory;

};