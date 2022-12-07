#include "PasswordProxy.h"

PasswordProxy::PasswordProxy(AbstractFile* file, string passw) : pw(passw), pwProtFile(file){}

PasswordProxy::~PasswordProxy()
{
	delete(pwProtFile);
}

string PasswordProxy::passwordPrompt()
{
	string password;
	cout << "password: " << endl;
	cin >> password;
	return password;
}

bool PasswordProxy::pwMatch(string pword)
{
	if (pw == pword) {
		return true;
	}
	return false;
}

vector<char> PasswordProxy::read()
{
	if (pwMatch(passwordPrompt())) {
		return pwProtFile->read();
	}
	else {
		return vector<char>();
	}
}

int PasswordProxy::write(vector<char> v)
{
	if (pwMatch(passwordPrompt())) {
		return pwProtFile->write(v);
	}
	else {
		return 23; //inco pw
	}
}

int PasswordProxy::append(vector<char> v)
{
	if (pwMatch(passwordPrompt())) {
		return pwProtFile->append(v);
	}
	else {
		return 23; // inco pw
	}
}

unsigned int PasswordProxy::getSize()
{
	return pwProtFile->getSize();
}

string PasswordProxy::getName()
{
	return pwProtFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* tony)
{
	if (pwMatch(passwordPrompt())) {
		return pwProtFile->accept(tony);
	}
}
