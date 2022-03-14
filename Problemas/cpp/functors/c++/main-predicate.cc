#include <iostream>
#include "functor.h"
#include <list>
#include <vector>

using namespace std;
template<typename T>
void out(const T& c)
{
	for (const auto& e : c)
		cout << boolalpha << e << " ";
	cout << endl;
}

int main()
{
	fn::select(fn::is_even(),1,10);
	fn::select(fn::is_prime(),1,30);

	list<int>  l {1,2,3,4,5,6,7,8,9,10};

	auto lfe = fn::filter(fn::is_even(),l);
	out(lfe);
	auto lfp = fn::filter(fn::is_prime(),l);
	out(lfp);

	auto lme = fn::map(fn::is_even(),l);
	out(lme);
	auto lmp = fn::map(fn::is_prime(),l);
	out(lmp);

	vector<int>  v {1,2,3,4,5,6,7,8,9,10};

	auto vfe = fn::filter(fn::is_even(),v);
	out(vfe);
	auto vfp = fn::filter(fn::is_prime(),v);
	out(vfp);

	auto vme = fn::map(fn::is_even(),v);
	out(vme);
	auto vmp = fn::map(fn::is_prime(),v);
	out(vmp);

	return 0;
};

