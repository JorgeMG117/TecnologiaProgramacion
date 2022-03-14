#include "writer-cached.h"

WriterCached::WriterCached(int sz) : size(sz), ndat(0)
{
	cout << __PRETTY_FUNCTION__ << endl;
	cache = new int[size];
}

WriterCached::~WriterCached()
{
	cout << __PRETTY_FUNCTION__ << endl;
	if (ndat>0)
		os.write((char*)cache,ndat*sizeof(int));
	delete[] cache;
}

void WriterCached::put(int data)
{
	cout << __PRETTY_FUNCTION__ << endl;
	if (ndat==size)
	{
		os.write((char*)cache,ndat*sizeof(int));
		ndat = 0;
	}
	cache[ndat++] = data;
}
