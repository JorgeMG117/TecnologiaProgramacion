#include <cmath>
#include <iostream>

using namespace std;

class VMP
{
private:
	int		id;
	float	x,y;
	bool	estaEnBase;
	bool	estaDisponible;

public:
	VMP(int _id,float _x,float _y)
		: id(_id), x(_x), y(_y), estaEnBase(true), estaDisponible(true)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}

	int   identificador() const { return id; }
	float distancia() const { return sqrt(x*x+y*y); }

	bool  disponible() const { return estaDisponible; }
	void  liberar()  { estaDisponible = true; }
	void  bloquear() { estaDisponible = false; }

	bool  aparcado() const { return estaEnBase; }
	virtual void  alquilar()
	{
		cout << __PRETTY_FUNCTION__ << endl;
		estaDisponible = false;
		estaEnBase = false;
	}
	virtual void  devolver()
	{
		cout << __PRETTY_FUNCTION__ << endl;
		estaDisponible = true;
		estaEnBase = true;
	}

	virtual float coste() = 0;
};

class VMPElectrico : virtual public VMP
{
protected:
	static constexpr float precio = 1.0;
private:
	float	cargaBateria;
	bool	estaCargando;
public:
	VMPElectrico() : VMP(7,0,0), cargaBateria(100), estaCargando(true)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	float carga() const { return cargaBateria; }
	void  carga(float c) { cargaBateria = c; }
	bool  cargando() const { return estaCargando; }
	void  alquilar() override {
		VMP::alquilar();
		cout << __PRETTY_FUNCTION__ << endl;
		estaCargando = false;
	};
	void  devolver() override {
		VMP::devolver();
		cout << __PRETTY_FUNCTION__ << endl;
		estaCargando = true;
	};
};

class Bicicleta : virtual public VMP
{
protected:
	static constexpr float precio = 2.0;
public:
	Bicicleta(int _id,float _x,float _y) : VMP(_id,_x,_y)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	float coste() override { return Bicicleta::precio; }
};

class BicicletaElectrica :  public Bicicleta, public VMPElectrico
{
public:
	BicicletaElectrica(int _id,float _x,float _y)
		: Bicicleta(_id,_x,_y), VMP(_id,_x,_y)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	float coste() override { return Bicicleta::precio+VMPElectrico::precio; }
};

class Patinete : virtual public VMP
{
protected:
	static constexpr float precio = 1.5;
public:
	Patinete(int _id,float _x,float _y)
		: VMP(_id,_x,_y)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	float coste() override { return Patinete::precio; }
};

class PatineteElectrico : public Patinete, public VMPElectrico
{
public:
	PatineteElectrico(int _id,float _x,float _y)
		: Patinete(_id,_x,_y), VMP(_id,_x,_y)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	float coste() override { return Patinete::precio+VMPElectrico::precio; }
};
