#pragma once
#include <string>

#define __trace  Tracer tracer(__PRETTY_FUNCTION__);
#define __traceo Tracer tracer(__PRETTY_FUNCTION__,true);

using namespace std;

class Tracer
{
private:
	static int level;
	string	fun;
	bool	markout;

public:
	Tracer(const string& f,bool mo=false);
	~Tracer();
};
