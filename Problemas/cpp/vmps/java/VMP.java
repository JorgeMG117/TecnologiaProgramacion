public abstract class VMP
{
	private int	 id;
	private double x,y;
	private boolean estaEnBase;
	private boolean estaDisponible;

	public VMP(int _id,float _x,float _y)
	{
		id = _id;
		x = _x;
		y = _y;
		estaEnBase = true;
		estaDisponible = true;
		System.out.println("VMP()");
	}

	public int    identificador() { return id; }
	public double distancia() { return Math.sqrt(x*x+y*y); }

	public boolean  disponible() { return estaDisponible; }
	public void     liberar()  { estaDisponible = true; }
	public void     bloquear() { estaDisponible = false; }

	public boolean  aparcado() { return estaEnBase; }
	public void alquilar()
	{
		System.out.println("VMP.alquilar()");
		estaDisponible = false;
		estaEnBase = false;
	}
	public void devolver()
	{
		System.out.println("VMP.devolver()");
		estaDisponible = true;
		estaEnBase = true;
	}

	public abstract double coste();
}
