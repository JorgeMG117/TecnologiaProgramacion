public final class CuentaCorriente extends Cuenta
{
	private double interes;

	public CuentaCorriente(double _capital, double _interes)
	{
		super(_capital); //Constructor clase base
		interes = _interes;
	};

	// Implementa el calculo del valor
	@Override
	public double valor(int t)
	{
		return capital*Math.pow(1.0 + interes/100.0,t);
	}
}
