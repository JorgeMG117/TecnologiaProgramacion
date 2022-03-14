#pragma once
#include <fstream>
#include <iostream>

using namespace std;

class Writer
{
protected:
	ofstream os;

public:
	Writer();
	virtual ~Writer();

	virtual void put(int data) = 0;
};
