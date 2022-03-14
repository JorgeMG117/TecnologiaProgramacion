#include "flota.h"

void Flota::annade(VMP* v)
{
	vmps.push_back(v);
}

const vector<VMP*>& Flota::lista() const
{
	return vmps;
}

VMP* Flota::masLejano() const
{
	VMP* tgt=nullptr;
	float maxd = 0;
	for (auto v : vmps)
	{
		float vd = v->distancia();
		if (vd>maxd)
		{
			tgt  = v;
			maxd = vd;
		}
	}

	return tgt;
}

vector<VMP*> Flota::fueraDeArea(float r) const
{
	vector<VMP*> out;

	for (auto v : vmps)
	{
		if (v->disponible() && !v->aparcado() && (v->distancia()>r))
		{
			v->bloquear();
			out.push_back(v);
		}
	}

	return out;
}

vector<VMP*> Flota::cargaBaja(float cargaMin) const
{
	vector<VMP*> out;

	for (auto v : vmps)
	{
		VMPElectrico* ve = dynamic_cast<VMPElectrico*>(v);
		if (ve)
		{
			if (!ve->aparcado() && (ve->carga()<cargaMin))
			{
				ve->bloquear();
				out.push_back(ve);
			}
		}
	}

	return out;
}

float Flota::patinetesEnUso() const
{
	int   nu=0, np=0;
	float ratio = 0.0f;

	for (auto v : vmps)
	{
		if (!v->disponible() && !v->aparcado())
		{
			nu++;
			if (dynamic_cast<Patinete*>(v)!=nullptr) np++;
		}
	}
	if (nu>0) ratio = 100*(float(np)/float(nu));

	return ratio;
}
