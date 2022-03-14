#pragma once
#include "writer.h"

class WriterDirect : public Writer
{
public:
	WriterDirect();
	~WriterDirect();

	void put(int data) override;
};
