#include "writer-direct.h"
#include "writer-cached.h"

int main()
{
//	WriterDirect w;
//	WriterCached w(128);
//	Writer* w = new WriterDirect;
	Writer* w = new WriterCached(128);

	w->put(33);

	delete w;

	return 0;
}
