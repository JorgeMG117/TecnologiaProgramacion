#include <iostream>
#include <iomanip>
#include "functor.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "sqr()" << endl;
	fn::plot(fn::sqr());
	cout << endl;

	cout << "mul_by(3)" << endl;
	fn::plot(fn::mul_by(3));
	cout << endl;

	cout << "round()" << endl;
	fn::plot(fn::round());
	cout << endl;

	return 0;
}


