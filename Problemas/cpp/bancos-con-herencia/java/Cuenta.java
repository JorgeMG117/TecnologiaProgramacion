public abstract class Cuenta
{
	// Comun
	protected double capital;

	public Cuenta(double _capital)
	{
		capital = _capital;
	};

	// Cada tipo de cuenta debe dar su implementación
	public abstract double valor(int t);

	// La clase base ofrece ya una implementación para todos
	public double tae()
	{
		return 100*(valor(12)/valor(0) - 1);
	}

	// La clase base ofrece ya una implementación, que sirve
	// para la mayoria de los casos
	// Los casos especiales pueden redefinirla
	public void actualiza()
	{
		capital = valor(1);
	}
}
