//  Define the TextFile class here
#include "TextFile.h"
#include <vector>
#include <iostream>
#include <string>
#include "AbstractFileVisitor.h"

using namespace std;

TextFile::TextFile(string s)
	: name(s)
{};

unsigned int TextFile::getSize() {
	return this->contents.size();
}

string TextFile::getName() {
	return this->name;
}

int TextFile::write(vector<char> v) {
	this->contents = v;
	if (this->contents == v) { // may have to for loop this and check individual char s
		return 0;
	}
	else {
		return 1;
	}
}

int TextFile::append(vector<char> v) {
	for (int i = 0; i < v.size(); i++) {
		this->contents.push_back(v[i]);
	}
	return 0;
}

vector<char> TextFile::read() {
	for (unsigned int i = 0; i < getSize(); i++) {
		cout << contents[i];
	}
	cout << endl;
	return contents;
}

void TextFile::accept(AbstractFileVisitor* hank)
{
	hank->visit_TextFile(this);
}