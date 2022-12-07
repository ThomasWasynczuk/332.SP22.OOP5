#include "ImageFile.h"
#include "AbstractFileVisitor.h"
// definition of ImageFile class here

ImageFile::ImageFile(string name) :

	name(name),
	size(0)
{}

unsigned int ImageFile::getSize()
{
	return (unsigned int)this->contents.size();
}

string ImageFile::getName()
{
	return this->name;
}

int ImageFile::write(vector<char> inp)
{
	size = inp[inp.size() - 1];
	int sizeAsInt = (int)size - 48;
	inp.pop_back();
	if (inp.size() != sizeAsInt * sizeAsInt) {
		contents.clear();
		size = 0;
		return 14; // this should be a filesize error in error enum
	}
	for (int i = 0; i < inp.size(); i++) {
		if (inp[i] != ' ' && inp[i] != 'X') {
			contents.clear();
			size = 0;
			return 15; // this should be an incorrect pixel error
		}
		else {
			contents.push_back(inp[i]);
		}
	}
	return 0;
}

int ImageFile::append(vector<char> inp)
{
	return 13;
}

vector<char> ImageFile::read()
{
	int sizerino = this->size - 48;
	for (int i = sizerino-1; i >= 0; i--) {
		for (int j = 0; j < sizerino; j++) {
			int k = i * sizerino + j;
			cout << contents[k];
		}
		cout << endl;
	}
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* hank)
{
	hank->visit_ImageFile(this);
}
