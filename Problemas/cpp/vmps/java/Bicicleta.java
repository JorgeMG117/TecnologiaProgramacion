public class Bicicleta extends VMP
{
	protected static final double precio = 2.0;

	public Bicicleta(int _id,float _x,float _y)
	{
		super(_id,_x,_y);
	}

	@Override
	public double coste() { return Bicicleta.precio; }
}
