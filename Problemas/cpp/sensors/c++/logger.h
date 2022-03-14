#pragma once
#include "store.h"
#include <algorithm>
#include <initializer_list>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& c)
{
	os << "[ ";
	for (auto i=begin(c); i!=end(c); i++)
		os << *i << " ";
	os << "]";

	return os;
}

template<typename T>
class Logger
{
private:
	string	name;
	vector<Store<T>*> store;
public:
	Logger(const string& n,const std::initializer_list<Store<T>*>& sl)
		: name(n)
	{
		std::copy(begin(sl),end(sl),std::back_inserter(store));
	}

	void push(const T& v)
	{
		for (auto& s : store) s->push(v);
	}
	void push(const std::initializer_list<T>& vl)
	{
		for (auto& s : store) s->push(vl);
	}

	void log() const
	{
		cout << name << ":" << endl;
		for (auto& s : store)
		{
			cout << setw(10) << (s->name()+": ") << s->value() << endl;
		}
		cout << endl;
	}
};
