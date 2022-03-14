import java.util.List;
import java.util.ArrayList;

public class Main
{
	public static void main(String[] args)
	{
		Flota flt = new Flota();

		Bicicleta          b  = new Bicicleta(1001,0,0);
		BicicletaElectrica be = new BicicletaElectrica(1002,1,1);
		Patinete           p  = new Patinete(1003,2,2);
		PatineteElectrico  pe = new PatineteElectrico(1004,3,3);

		flt.annade(b);
		flt.annade(be);
		flt.annade(p);
		flt.annade(pe);

		System.out.println("VMPs:");
		for (VMP v : flt.lista())
		{
			System.out.print(v.identificador());
			System.out.print(" "+v.disponible());
			System.out.print(" "+v.coste());
			System.out.println();
		}
		System.out.println();

		for (VMP v : flt.lista())
		{
			v.alquilar();
	//		v.devolver();
			v.liberar();
			System.out.println();
		}

		List<VMP> fa = flt.fueraDeArea(1.5);
		System.out.println();
		System.out.println("Abandonados:");
		for (VMP v : fa)
			System.out.println(v.identificador());
		System.out.println();

		System.out.println("VMPs:");
		for (VMP v : flt.lista())
		{
			System.out.print(v.identificador());
			System.out.print(" "+v.disponible());
			System.out.println();
		}
		System.out.println();

		be.carga(10);
		flt.cargaBaja(20);

		System.out.println("VMPs:");
		for (VMP v : flt.lista())
		{
			System.out.print(v.identificador());
			System.out.print(" "+v.disponible());
			System.out.println();
		}
		System.out.println();
	}
}
