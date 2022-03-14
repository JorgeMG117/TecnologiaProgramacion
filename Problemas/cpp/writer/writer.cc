#include "writer.h"

Writer::Writer()
{
	cout << __PRETTY_FUNCTION__ << endl;
	os.open("/dev/null",ofstream::binary);
}

Writer::~Writer()
{
	cout << __PRETTY_FUNCTION__ << endl;
	os.close();
}
