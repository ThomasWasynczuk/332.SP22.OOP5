#pragma once
#include "AbstractFile.h"
//#include <vector>

// TextFile declaration goes here

class TextFile: public AbstractFile {
private:
	vector<char> contents;
	string name;
public:
	TextFile(string s);
	virtual vector<char> read();
	virtual int write(vector<char> v);
	virtual int append(vector<char> v);
	virtual unsigned int getSize();
	virtual string getName();
	virtual void accept(AbstractFileVisitor* hank);
};