#include "tracer.h"
#include <iostream>

using namespace std;

int Tracer::level = 0;

Tracer::Tracer(const string& f,bool mo) : fun{f}, markout{mo}
{
	clog << string(2*(level+1),' ') << "> " << fun << endl;
	level++;
}

Tracer::~Tracer()
{
	level--;
	if (markout)
		clog << string(2*(level+1),' ') << "< " << fun << endl;
}
