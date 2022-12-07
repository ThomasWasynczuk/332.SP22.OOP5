// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/SimpleFileFactory.h"
using namespace std;

int main()
{
	AbstractFileSystem* absFS = new SimpleFileSystem;
	AbstractFileFactory* absFF = new SimpleFileFactory;
	AbstractFile* textfile = absFF->createFile("sample.txt");

	absFS->addFile(textfile->getName(), textfile);
	absFS->openFile("sample.txt");
	textfile->read();
	textfile->write({ '1','2','3' });
	textfile->read();
	absFS->closeFile(textfile);
	absFS->deleteFile(textfile->getName());
	return 0;
}
