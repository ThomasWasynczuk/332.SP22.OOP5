#pragma once
// Studio 18 - simplefilefactory class declaration goes here
#include "AbstractFileFactory.h"


class SimpleFileFactory : public AbstractFileFactory {
public:
	AbstractFile* createFile(string name);
};