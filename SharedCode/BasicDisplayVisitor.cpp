#include "BasicDisplayVisitor.h"
// definitions of basic display visitor here
using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile* file)
{
	vector<char> contents = file->read();
	for (unsigned int i = 0; i < file->getSize(); i++) {
		cout << contents[i];
	}
	cout << endl;
	return;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* file)
{
	vector<char> contents = file->read();
	int sizerino = file->getSize() - 48;
	for (int i = sizerino - 1; i >= 0; i--) {
		for (int j = 0; j < sizerino; j++) {
			int k = i * sizerino + j;
			cout << contents[k];
		}
		cout << endl;
	}
	return;
}
