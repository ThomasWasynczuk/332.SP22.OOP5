#include "MetadataDisplayVisitor.h"
// definitions of metadata visitor here

void MetadataDisplayVisitor::visit_TextFile(TextFile* file)
{
	cout << file->getName() << endl << "text" << endl << file->getSize();
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file)
{
	cout << file->getName() << endl << "image" << endl << file->getSize();
}
