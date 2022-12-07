#pragma once
// declaration of the interface all file systems provide goes here
#include <string>
#include "AbstractFile.h"

class AbstractFileSystem {
public:
	virtual int addFile(std::string filename, AbstractFile* absPt)=0;
	virtual int createFile(string name)=0;
	virtual int deleteFile(string name)=0;
	virtual AbstractFile* openFile(string name)=0;
	virtual int closeFile(AbstractFile* absPt)=0;
};