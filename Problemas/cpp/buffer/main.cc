#include <iostream>
#include "tracer.h"
#include "buffer.h"

using namespace std;

void   f(Buffer b);
void   g(const Buffer& b);
Buffer h();

int main()
{
	clog << "ctor" << endl;
	Buffer a;
	clog << "ctor" << endl << endl;

	clog << "ctor copy" << endl;
	Buffer b {a};
	clog << "ctor copy" << endl << endl;

	clog << "ctor move" << endl;
	Buffer c {std::move(a)};
	clog << "ctor move" << endl << endl;

	clog << "ctor i-list" << endl;
	Buffer d {1,2,3};
	clog << "ctor i-list" << endl << endl;

	clog << "assign copy" << endl;
	a = b;
	clog << "assign copy" << endl << endl;

	clog << "assign move" << endl;
	a = std::move(b);
	clog << "assign move" << endl << endl;

	clog << "assign i-list" << endl;
	a = {1,2,3};
	clog << "assign i-list" << endl << endl;

	clog << "fun arg val" << endl;
	f(b);
	clog << "fun arg val" << endl << endl;

	clog << "fun arg ref" << endl;
	g(a);
	clog << "fun arg ref" << endl << endl;

	clog << "fun ret" << endl;
	b = h();
	clog << "fun ret" << endl << endl;

	clog << "fun combined" << endl;
	f(h());
	clog << "fun combined" << endl << endl;

	clog << "out" << endl;
	return 0;
}

void f(Buffer b)
{
	__traceo;
}

void g(const Buffer& b)
{
	__traceo;
}

Buffer h()
{
	__traceo;

	Buffer lb;

	return lb;
}
