class PlazoFijo extends Cuenta
{
	private double interes;
	private int    plazo;

	public PlazoFijo(double _capital, double _interes, int _plazo)
	{
		super(_capital);
		interes = _interes;
		plazo   = _plazo;
	};

	// Implementa el calculo del valor
	@Override
	public double valor(int t)
	{
		return (t<plazo ? capital : capital*(1.0+interes/100.0));
	}

	// Redefine la forma de actualizarse
	@Override
	void actualiza()
	{
		if (plazo >= 0) plazo--;
		if (plazo == 0) capital *= (1.0+interes/100.0);
	}
}
