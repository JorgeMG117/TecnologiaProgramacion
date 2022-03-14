class BicicletaElectrica extends Bicicleta implements VMPElectrico
{
	private double	cargaBateria;
	private boolean	estaCargando;

	public BicicletaElectrica(int _id,float _x,float _y)
	{
		super(_id,_x,_y);
		cargaBateria = 100;
		estaCargando = true;
	}

	@Override
	public double  carga() { return cargaBateria; }
	@Override
	public void    carga(double c) { cargaBateria = c; }
	@Override
	public boolean cargando() { return estaCargando; }

	@Override
	public void  alquilar() {
		super.alquilar();
		System.out.println("BicicletaElectrica.alquilar()");
		estaCargando = false;
	};

	@Override
	public void  devolver() {
		super.devolver();
		System.out.println("BicicletaElectrica.devolver()");
		estaCargando = true;
	};

	@Override
	public double coste() { return Bicicleta.precio+VMPElectrico.precio; }
};
