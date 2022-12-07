#pragma once
// declaration of BasicDisplayVisitor here
//#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

using namespace std;

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
};