#pragma once
#include "writer.h"

class WriterCached : public Writer
{
private:
	int*	cache;
	int		size;
	int		ndat;

public:
	WriterCached(int sz);
	~WriterCached();

	void put(int data) override;
};
