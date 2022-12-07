// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <vector>
#include <iostream>
//#include <string>

using namespace std;


int main()
{
	vector<char> v = { 'h','e','y', ' '};
	vector<char> v2 = { 'w', 'h','a','t','s',' ', 'u','p' };
	TextFile* f = new TextFile("file"); 
	f->write(v);
	f->read();
	cout << "size: " << f->getSize() << endl;
	cout << endl;
	f->append(v2);
	f->read();
	cout << "size: " << f->getSize() << endl;

	return 0;
}


