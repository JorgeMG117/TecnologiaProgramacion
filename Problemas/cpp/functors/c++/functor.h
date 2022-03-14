#pragma once

#include <iostream>
#include <iomanip>
#include <list>

namespace fn
{
	using namespace std;

	template<typename R, typename P>
	class functor {
	public:
		virtual R eval(const P& p) const = 0;
		R operator()(const P& p) const { return eval(p); }
	};

	class sqr : public functor<float,float> {
	public:
		float eval(const float& x) const override { return x*x; }
	};

	class mul_by : public functor<float,float> {
		float factor;
	public:
		mul_by(float factor) : factor(factor) {}
		float eval(const float& x) const override { return factor*x; }
	};

	class round : public functor<int,float> {
	public:
		int eval(const float& x) const override { return int(x+0.5); }
	};

	template <typename R>
	void plot(const functor<R,float>& f) {
		cout << "   x =";
		for (float t=0; t<=6; t+=0.6)
			cout << fixed << setw(6) << setprecision(2) << t;
		cout << endl;
		cout << "f(x) =";
		for (float t=0; t<=6; t+=0.6)
			cout << fixed << setw(6) << setprecision(2) << f(t);
		cout << endl;
	}

	template<typename P>
	class predicate : public functor<bool,P>
	{
	};

	class is_even : public predicate<int> {
	public:
		bool eval(const int& x) const override {
			return (x%2)==0;
		}
	};

	class is_prime : public predicate<int> {
	public:
		bool eval(const int& x) const override {
			if (x<3) return false;
			for (int i=2; i<x; i++)
				if ((x%i)==0) return false;
			return true;
		}
	};

	void select(const predicate<int>& condicion, int a, int b) {
		for (int i=a; i<=b; ++i)
			if (condicion(i)) cout << i << " ";
		cout << endl;
	}

#if 0
	template<typename T>
	list<T> filter(const predicate<T>& cond,const list<T>& org)
	{
		list<P> res;
		for (const auto& e : org)
			if (cond(e)) res.push_back(e);
		return res;
	}
#endif

	template<typename T,typename C>
	C filter(const predicate<T>& cond,const C& org)
	{
		C res;
		for (const auto& e : org)
			if (cond(e)) res.push_back(e);
		return res;
	}

#if 0
	template<typename R,typename P>
	list<R> map(const functor<R,P>& f,const list<P>& org)
	{
		list<R> res;
		for (const auto& e : org)
			res.push_back(f(e));
		return res;
	}
#endif

	template<typename R,typename P,template<typename...> typename C>
	C<R> map(const functor<R,P>& f,const C<P>& org)
	{
		C<R> res;
		for (const auto& e : org)
			res.push_back(f(e));
		return res;
	}
}


