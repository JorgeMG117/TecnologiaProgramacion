public class Patinete extends VMP
{
	protected static final double precio = 1.5;

	public Patinete(int _id,float _x,float _y)
	{
		super(_id,_x,_y);
	}

	@Override
	public double coste() { return Patinete.precio; }
}


