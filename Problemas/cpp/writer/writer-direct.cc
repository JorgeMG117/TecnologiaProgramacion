#include "writer-direct.h"

WriterDirect::WriterDirect()
{
	cout << __PRETTY_FUNCTION__ << endl;
}

WriterDirect::~WriterDirect()
{
	cout << __PRETTY_FUNCTION__ << endl;
}

void WriterDirect::put(int data)
{
	cout << __PRETTY_FUNCTION__ << endl;
	os.write((char*)&data,sizeof(int));
}
