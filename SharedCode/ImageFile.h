#pragma once
//#include <string>
//#include <vector>
//#include <iostream>
#include "AbstractFile.h"

using namespace std;


class ImageFile: public AbstractFile {
public:
	ImageFile(string name);
	virtual unsigned int getSize();
	virtual string getName();
	virtual int write(vector<char> input);
	virtual int append(vector<char> v);
	virtual vector<char> read();
	virtual void accept(AbstractFileVisitor* hank);
private:
	string name;
	vector<char> contents;
	char size;


};