#pragma once

#include <iostream>
#include <vector>
#include <string>
//#include "AbstractFileVisitor.h"
class AbstractFileVisitor;

using namespace std;
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary


class AbstractFile {
public:
	virtual ~AbstractFile() = default;

	
	virtual vector<char> read() = 0;
	virtual int write(vector<char> v)= 0;
	virtual int append(vector<char> v)=0;
	virtual unsigned int getSize()=0;
	virtual string getName()=0;

	virtual void accept(AbstractFileVisitor*) = 0;
private:

};