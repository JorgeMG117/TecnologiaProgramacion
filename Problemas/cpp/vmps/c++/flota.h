#include <vector>
#include "vmp.h"

using namespace std;

class Flota
{
private:
	vector<VMP*> vmps;

public:
	void			annade(VMP* v);
	const vector<VMP*>&	lista() const;
	VMP*			masLejano() const;
	vector<VMP*>	fueraDeArea(float r) const;
	vector<VMP*>	cargaBaja(float cargaMin) const;
	float			patinetesEnUso() const;
};
