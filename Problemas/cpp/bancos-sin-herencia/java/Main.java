class Main
{
	public static void main(String[] args)
	{
		Cuenta cuentas[] = new Cuenta[4];

		cuentas[0] = new Cuenta(Cuenta.Tipo.CORRIENTE, 1000, 1.2);
		cuentas[1] = new Cuenta(Cuenta.Tipo.PLAZO,     5000,60.0,12);
		cuentas[2] = new Cuenta(2000, 2.5);
		cuentas[3] = new Cuenta(10000,30.0, 6);

		mostrar_taes(cuentas,4);
		System.out.println();

		System.out.println("Mes | Valor");
		System.out.println("================");
		for (int t=0; t<=24; t++)
		{
			System.out.format("%3d",t);
			System.out.print(" | ");
			System.out.format("%8.2f",total(cuentas,4,t));
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
