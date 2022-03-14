#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational	a,b,r;
	char		op;

	while (true)
	{
		cout << "? " << flush;
		read(a);
		cin >> op;
		read(b);
		switch(op)
		{
			case '+': r = add(a,b);       break;
			case '-': r = substract(a,b); break;
			case '*': r = multiply(a,b);  break;
			case '/': r = divide(a,b);    break;
			default:  r = rational(0,0);
		}
		cout << "= "; write(r); cout << endl;
	}

	return 0;
}

