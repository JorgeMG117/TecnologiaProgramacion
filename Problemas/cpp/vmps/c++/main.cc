#include "flota.h"
#include <iostream>

using namespace std;

int main()
{
	Flota flt;

	Bicicleta*          b  = new Bicicleta(1001,0,0);
	BicicletaElectrica* be = new BicicletaElectrica(1002,1,1);
	Patinete*           p  = new Patinete(1003,2,2);
	PatineteElectrico*  pe = new PatineteElectrico(1004,3,3);
	cout << endl;

	flt.annade(b);
	flt.annade(be);
	flt.annade(p);
	flt.annade(pe);

	cout << boolalpha;

	cout << "VMPs:" << endl;
	for (auto v : flt.lista())
	{
		cout << v->identificador();
		cout << " " << v->disponible();
		cout << " " << v->coste();
		cout << endl;
	}
	cout << endl;

	for (auto v : flt.lista())
	{
		v->alquilar();
//		v->devolver();
		v->liberar();
		cout << endl;
	}

	vector<VMP*> fa = flt.fueraDeArea(1.5);
	cout << endl << "Abandonados:" << endl;
	for (auto v : fa)
		cout << v->identificador() << endl;
	cout << endl;

	cout << "VMPs:" << endl;
	for (auto v : flt.lista())
	{
		cout << v->identificador();
		cout << " " << v->disponible();
		cout << endl;
	}
	cout << endl;

	be->carga(10);
	flt.cargaBaja(20);

	cout << "VMPs:" << endl;
	for (auto v : flt.lista())
	{
		cout << v->identificador();
		cout << " " << v->disponible();
		cout << endl;
	}
	cout << endl;

	return 0;
}
