#include "rational.h"
#include <iostream>
#include <sstream>

using namespace std;

const string PROMPT = "? ";

/*
clog << __func__ << endl;
Constante que muestra en que
funcion estamos
*/

/*
Si no definimos operacion de 
asignacion c++ copia byte a byte
*/

int main()
{
	Rational	a,b,r;
	/*Asi se llama a un constructor sin parametros
	NO Rational a()*/
	char		op;

	/*Mete instrucciones a ensamblador
	para meter un comentario
	-S para generar ensamblador*/
	asm("# bgn");
	r = a+b;
	asm("# end");

	for(;;)
	{
		string line;
		cout << PROMPT;
		getline(cin,line);
		if (line.empty()) break;

		istringstream sin(line);
		sin >> a >> skipws >> op >> b;

		switch(op)
		{
			case '+': r = a+b; break;
			case '-': r = a-b; break;
			case '*': r = a*b; break;
			case '/': r = a/b; break;
			default:  r = Rational(0,1);
		}
		float fr = r;
		cout << a << " " << op << " " << b;
		cout << " = " << r;
		cout << " = " << fr;
		cout << endl;
	}

	cout << "by!" << endl;

	return 0;
}

