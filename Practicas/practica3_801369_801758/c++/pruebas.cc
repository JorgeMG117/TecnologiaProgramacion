#include "practica3.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    Camion camion(30);
    Contenedor<Carga>	contenedor_estandar(7);
	Contenedor<Toxico>	contenedor_toxico(3);
	Contenedor<SerVivo>	contenedor_servivo(20);

    Producto longaniza_graus("Longaniza de Graus",0.5,0.8);
	contenedor_estandar.guardar(longaniza_graus);
    
	Producto adoquines_zaragoza("Adoquines de Zaragoza",0.1,5.0);
	contenedor_estandar.guardar(adoquines_zaragoza);
    
    Producto playStation("Play Station",3,5.0);
    contenedor_estandar.guardar(playStation);

    Contenedor<SerVivo>	otro_contenedor_servivo(1.5);
    SerVivo jorge("Jorge",1,100);
    otro_contenedor_servivo.guardar(jorge);
    contenedor_estandar.guardar(otro_contenedor_servivo);

    Contenedor<SerVivo>	otro2_contenedor_servivo(5);
    if (!contenedor_estandar.guardar(otro2_contenedor_servivo))
		cout << "Contenedor Estandar lleno de Otro 2 Contenedor Servivo" << endl;
	
/*
	Toxico tu_relaccion("Relaccion",2,10);
	contenedor_toxico.guardar(tu_relaccion);

    Toxico comunidadLOL("Comunidad del League of Legends", 1, 0.2);
    contenedor_toxico.guardar(comunidadLOL);

	Toxico pilas("Pilas",1,10);		//no cabe
	contenedor_toxico.guardar(pilas);
    if (!contenedor_toxico.guardar(pilas))
		cout << "Contenedor Toxico lleno de pilas" << endl;


	SerVivo mi_haprovado("Aprovar",10,100);
	contenedor_servivo.guardar(mi_haprovado);

	SerVivo conejo("Conejo",10,100);
	contenedor_servivo.guardar(conejo);

	SerVivo ferni("Ferni",4,100);
	if (!contenedor_servivo.guardar(ferni))
		cout << "No esperareis que os lo resuelva yo? *silencio incomodo* no se, no es mio :(" << endl;
	*/
    camion.guardar(contenedor_estandar);
    camion.guardar(contenedor_toxico);
    camion.guardar(contenedor_servivo);
	
    cout << camion << endl;
}

