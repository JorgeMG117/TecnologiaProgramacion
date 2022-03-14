#pragma once
#include <initializer_list>

using namespace std;

class Buffer
{
private:
	static const int SZ;
	int*	data;
public:
	Buffer();
	Buffer(const Buffer& that);
	Buffer(Buffer&& that);
	Buffer(const initializer_list<int>& il);
	~Buffer();

	const Buffer& operator=(const Buffer& that);
	const Buffer& operator=(Buffer&& that);
	const Buffer& operator=(const initializer_list<int>& il);
};
