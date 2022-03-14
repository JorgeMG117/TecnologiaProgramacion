import java.util.List;
import java.util.ArrayList;

class Flota
{
	private List<VMP> vmps;

	public Flota()
	{
		vmps = new ArrayList<VMP>();
	}

	public void annade(VMP v)
	{
		vmps.add(v);
	}

	public List<VMP> lista()
	{
		return vmps;
	}

	public VMP masLejano()
	{
		VMP tgt=null;
		double maxd = 0;
		for (VMP v : vmps)
		{
			double vd = v.distancia();
			if (vd>maxd)
			{
				tgt  = v;
				maxd = vd;
			}
		}

		return tgt;
	}

	public List<VMP> fueraDeArea(double r)
	{
		List<VMP> out = new ArrayList<>();

		for (VMP v : vmps)
		{
			if (v.disponible() && !v.aparcado() && (v.distancia()>r))
			{
				v.bloquear();
				out.add(v);
			}
		}

		return out;
	}

	public List<VMP> cargaBaja(double cargaMin)
	{
		List<VMP> out = new ArrayList<>();

		for (VMP v : vmps)
		{
			if (v instanceof VMPElectrico)
			{
				VMPElectrico ve = (VMPElectrico)v;
				if ((!v.aparcado()) && (ve.carga()<cargaMin))
				{
					v.bloquear();
					out.add(v);
				}
			}
		}

		return out;
	}

	public double patinetesEnUso()
	{
		int   nu=0, np=0;
		double ratio = 0.0f;

		for (VMP v : vmps)
		{
			if (!v.disponible() && !v.aparcado())
			{
				nu++;
				if (v instanceof Patinete) np++;
			}
		}
		if (nu>0) ratio = 100*((double)np/(double)nu);

		return ratio;
	}
}

