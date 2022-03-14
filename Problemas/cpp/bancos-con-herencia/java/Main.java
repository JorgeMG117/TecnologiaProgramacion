class Main
{
	public static void main(String[] args)
	{
		Cuenta cuentas[] = new Cuenta[4];

		cuentas[0] = new CuentaCorriente(1000,2.0);
		cuentas[1] = new PlazoFijo(500,2.0,12);
		cuentas[2] = new Nomina(1200.0);
		CuentaCorriente cuenta_en_dolares = new CuentaCorriente(100,3.0);
		cuentas[3] = new Divisa(0.82,cuenta_en_dolares);

		mostrar_taes(cuentas,4);
		System.out.println();

		System.out.println("Mes |  Valor cuentas                           |  Total      ");
		System.out.println("=============================================================");
		for (int t=0; t<=24; t++)
		{
			System.out.format("%3d",t);
			System.out.print(" | ");
			for (int i=0; i<4; i++)
				System.out.format("%10.2f",cuentas[i].valor(t));
			System.out.print(" | ");
			System.out.format("%10.2f",total(cuentas,4,t));
			System.out.println(" €");
		}
	}

	static double total(Cuenta cuentas[], int n, int t)
	{
		double sol = 0.0;
		for (int i=0;i<n;++i)
			sol += cuentas[i].valor(t);
		return sol;
	}

	static void mostrar_taes(Cuenta cuentas[], int n)
	{
		System.out.print("TAEs: ");
		for (int i=0;i<n;++i)
			System.out.print(cuentas[i].tae()+" ");
	}
}
