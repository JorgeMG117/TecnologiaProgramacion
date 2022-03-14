public interface VMPElectrico
{
	static final double precio = 1.0;

	public double  carga();
	public void    carga(double c);
	public boolean cargando();
};
