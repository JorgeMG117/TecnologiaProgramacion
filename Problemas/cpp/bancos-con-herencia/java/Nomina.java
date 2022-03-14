class Nomina extends Cuenta
{
	private double sueldo;

	public Nomina(double _sueldo)
	{
		super(_sueldo);
		sueldo = _sueldo;
	};

	// Implementa el calculo del valor
	@Override
	public double valor(int t)
	{
		return capital + t*sueldo;
	}
}
