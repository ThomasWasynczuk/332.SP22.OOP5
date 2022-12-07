#pragma once
#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {
private:
	AbstractFile* pwProtFile;
	string pw;
public:
	PasswordProxy(AbstractFile* file, string passw);
	~PasswordProxy();
protected:
	string passwordPrompt();
	bool pwMatch(string pword);

	virtual vector<char> read();
	virtual int write(vector<char> v);
	virtual int append(vector<char> v);
	virtual unsigned int getSize();
	virtual string getName();

	virtual void accept(AbstractFileVisitor*);
};