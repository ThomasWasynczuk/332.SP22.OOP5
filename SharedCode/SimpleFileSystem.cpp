// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"
#include <string>

int SimpleFileSystem::addFile(std::string filename, AbstractFile* absPt)
{
	map<string, AbstractFile*>::iterator it;
	it = files.find(filename);
	if (it != files.end()) {
		//file exists @ it
		return 17; // filename already exists
	}
	
	if (absPt == nullptr) {
		return 18; // file is nullptr
	}
	pair<string, AbstractFile*> youngFella (filename, absPt);
	files.insert(youngFella);
	return 0;
}

int SimpleFileSystem::createFile(string name)
{
	map<string, AbstractFile*>::iterator it;
	it = files.find(name);
	if (it != files.end()) {
		//file exists @ it
		return 17; // filename already exists
	}
	string text = ".txt";
	string image = ".img";
	if (name.find(text) != string::npos) {
		TextFile* dudley = new TextFile(name);
		pair<string, AbstractFile*> youngFella(name, dudley);
		files.insert(youngFella);
		return 0;
	}
	else if(name.find(image) != string::npos) {
		ImageFile* dudley = new ImageFile(name);
		pair<string, AbstractFile*> youngFella(name, dudley);
		files.insert(youngFella);
		return 0;
	}
	return 18; //unknown file suffix
}

int SimpleFileSystem::deleteFile(string name)
{
	map<string, AbstractFile*>::iterator it;
	it = files.find(name);
	if (it != files.end()) { // file exists
		if (openFiles.find(it->second) != openFiles.end()) { // file is open
			return 20; 
		}
		AbstractFile* pt = files.at(name);
		files.erase(name);
		delete(pt);
		return 0;
	}
	else { // file does not exist
		return 20;
	}
	return 0;
}

AbstractFile* SimpleFileSystem::openFile(string name)
{
	map<string, AbstractFile*>::iterator it;
	it = files.find(name);
	if (it != files.end()) { // if file exists
		if (openFiles.find(it->second) != openFiles.end()) { // if file is already open
			return nullptr;
		}
		openFiles.insert(it->second);
		return it->second;
	}
	else {
		//file doesnt exist
		return nullptr;
	}
	return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile* absPt)
{
	if (openFiles.find(absPt) != openFiles.end()) {
		openFiles.erase(absPt);
		return 0;
	}
	else {
		return 19;
	}
}
