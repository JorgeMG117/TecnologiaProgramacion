class Divisa extends Cuenta
{
	private double	ratio;
	private Cuenta	otra;

	public Divisa(double _ratio, Cuenta _otra)
	{
		super(0);
		ratio = _ratio;
		otra  = _otra;
	};

	// Implementa el calculo del valor
	@Override
	public double valor(int t)
	{
		return ratio*otra.valor(t);
	}

	// Redefine la forma de actualizarse
	@Override  //Cuando ha hecho el ej no ha puesto override en ningun sitio
	public void actualiza()
	{
		otra.actualiza();
	}
}
