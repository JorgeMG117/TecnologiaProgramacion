class Cuenta
{
	public	enum Tipo { CORRIENTE, PLAZO };

	private	Tipo	tipo;
	// Comun
	private	double	capital;
	// Si es cuenta corriente, tipo de interes mensual en %.
	// Si es plazo fijo, tipo de interes en % cuando se acaba el plazo.
	private	double	interes;
	// Si es plazo fijo, tiempo (en meses)
	//	hasta que vence el plazo (no da dinero antes)
	private	int		plazo;

    //Constructor general
	public Cuenta(Tipo _tipo,double _capital,double _interes,int _plazo)
	{
		tipo    = _tipo;
		capital = _capital;
		interes = _interes;
		plazo   = _plazo;
	};

    //Constructor general, delegado
	public Cuenta(Tipo _tipo,double _capital,double _interes)
	{
		this(_tipo,_capital,_interes,0);
	};

    //Construye una cuenta corriente, no tiene parámetro plazo
    public Cuenta(double _capital,double _interes)
	{
		tipo    = Tipo.CORRIENTE;
		capital = _capital;
		interes = _interes;
		plazo   = 0;
	};

    //Construye un plazo porque tiene parámetro plazo, delegado
    public Cuenta(double _capital,double _interes,int _plazo)
	{
		this(Tipo.PLAZO,_capital,_interes,_plazo);
	};

	private double valor_corriente(int t)
	{
		return capital*Math.pow(1.0+(interes/100.0),t);
	}

	private double valor_plazo(int t)
	{
		return (	t >= plazo ?
					capital*(1+(interes/100.0))
					:
					capital	);
	}

	double valor(int t)
	{
		double res = 0.0;

		switch(tipo)
		{
			case CORRIENTE:
				res = valor_corriente(t);
				break;
			case PLAZO:
				res = valor_plazo(t);
				break;
		}

		return res;
	}

	double tae()
	{
		return 100*(valor(12)/valor(0) - 1);
	}
}
