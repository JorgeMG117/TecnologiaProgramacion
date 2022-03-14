#include "buffer.h"
#include "tracer.h"
#include <iostream>

using namespace std;

const int Buffer::SZ = 32;

Buffer::Buffer()
{
	__trace;

	data = new int[SZ];
}

Buffer::Buffer(const Buffer& that)
{
	__trace;

	data = new int[SZ];
	if (that.data)
		copy(that.data,that.data+SZ,data);
}

Buffer::Buffer(Buffer&& that)
{
	__trace;

	data = that.data;
	that.data = nullptr;
}

Buffer::Buffer(const initializer_list<int>& il)
{
	__trace;

	data = new int[SZ];
	int sz = max(SZ,int(il.size()));
	copy(il.begin(),il.begin()+sz,data);
}

Buffer::~Buffer()
{
	__trace;

	delete[] data;
}

const Buffer& Buffer::operator=(const Buffer& that)
{
	__trace;

	delete[] data;
	data = new int[SZ];
	if (that.data)
		copy(that.data,that.data+SZ,data);

	return *this;
}

const Buffer& Buffer::operator=(Buffer&& that)
{
	__trace;

	data = that.data;
	that.data = nullptr;

	return *this;
}

const Buffer& Buffer::operator=(const initializer_list<int>& il)
{
	__trace;

	delete[] data;
	data = new int[SZ];
	int sz = max(SZ,int(il.size()));
	copy(il.begin(),il.begin()+sz,data);

	return *this;
}

