#pragma once
#include <algorithm>
#include <initializer_list>
#include <string>
#include <complex>
#include <vector>

using namespace std;

template<typename T>
class Store
{
protected:
	T	val;
public:
	virtual string name() const = 0;

	virtual void push(const T& v) = 0;
	void push(const std::initializer_list<T>& vl)
	{
		for (auto v : vl) push(v);
	}

	virtual T    value() const { return val; }
};

template<typename T>
class StoreLast : public Store<T>
{
private:
	using Store<T>::val;
public:
	using Store<T>::push;

	string name() const override { return "last"; }

	void push(const T& v) override
	{
		val = v;
	}
};

template<typename T>
complex<T> max(const complex<T>& a,const complex<T>& b)
{
	return (abs(a)>abs(b) ? a : b);
}

template<typename T,template <typename> typename C>
C<T> max(const C<T>& a, const C<T>& b)
{
	C<T> res;
	auto ia = begin(a);
	auto ib = begin(b);
	for (; ia!=end(a) && ib!=end(b); ia++,ib++)
		res.push_back(max(*ia,*ib));
	return res;
}

template<typename T>
class StoreMax : public Store<T>
{
private:
	using Store<T>::val;
	bool	first;

public:
	StoreMax() : first(true) {}

	string name() const override { return "max"; }

	using Store<T>::push;
	void push(const T& v) override
	{
		if (first)
		{
			val = v;
			first = false;
		}
		else
		{
			val = max(val,v);
		}
	}
};

template<typename T>
complex<T> min(const complex<T>& a,const complex<T>& b)
{
	return (abs(a)<abs(b) ? a : b);
}

template<typename T,template <typename> typename C>
C<T> min(const C<T>& a, const C<T>& b)
{
	C<T> res;
	auto ia = begin(a);
	auto ib = begin(b);
	for (; ia!=end(a) && ib!=end(b); ia++,ib++)
		res.push_back(min(*ia,*ib));
	return res;
}

template<typename T>
class StoreMin : public Store<T>
{
private:
	using Store<T>::val;
	bool	first;

public:
	StoreMin() : first(true) {}

	string name() const override { return "min"; }

	using Store<T>::push;
	void push(const T& v) override
	{
		if (first)
		{
			val = v;
			first = false;
		}
		else
		{
			val = min(val,v);
		}
	}
};

template<typename T>
complex<T> operator/ (const complex<T>& c,int k)
{
	return c/T(k);
}

template<typename T,template<typename...> typename C>
C<T> operator+ (const C<T>& a,const C<T>& b)
{
	C<T> res;
	auto ia = begin(a);
	auto ib = begin(b);
	for (; ia!=end(a) && ib!=end(b); ia++,ib++)
		res.push_back((*ia)+(*ib));
	return res;
}

template<typename T,template<typename...> typename C>
C<T> operator/ (const C<T>& c,int k)
{
	C<T> res;
	for (auto& e : c)
		res.push_back(e/k);
	return res;
}

template<typename T>
class StoreAvg : public Store<T>
{
private:
	using Store<T>::val;
	int	count;

public:
	StoreAvg(const T& ini) : count(0) { val = ini; }

	string name() const override { return "average"; }

	using Store<T>::push;
	void push(const T& v) override
	{
		count++;
		val = val+v;
	}

	T value() const override
	{
		return (count>0 ? val/count : val);
	}
};
