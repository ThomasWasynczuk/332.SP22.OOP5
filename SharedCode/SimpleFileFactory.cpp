#include "SimpleFileFactory.h"
// studio 18 - simple file factory definitions
#include "ImageFile.h"
#include "TextFile.h"

AbstractFile* SimpleFileFactory::createFile(string name)
{

	string text = ".txt";
	string image = ".img";
	AbstractFile* dudley;
	if (name.find(text) != string::npos) {
		dudley = new TextFile(name);
		//pair<string, AbstractFile*> youngFella(name, dudley);
		
		return dudley;
	}
	else if (name.find(image) != string::npos) {
		dudley = new ImageFile(name);
		//pair<string, AbstractFile*> youngFella(name, dudley);
		
		return dudley;
	}
	return nullptr; //unknown file suffix
}
