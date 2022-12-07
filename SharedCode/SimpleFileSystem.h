#pragma once
// declaration of SimpleFileSystem class goes here
#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem {
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;
public:
	virtual int addFile(std::string filename, AbstractFile* absPt) ;
	virtual int createFile(string name) ;
	virtual int deleteFile(string name) ;
	virtual AbstractFile* openFile(string name) ;
	virtual int closeFile(AbstractFile* absPt) ;
};
