import java.util.List;

class Main
{
	public static void main(String[] args)
	{
		Logger<Double> temp_log = new Logger<>("temperature",
			List.of(
				new StoreLast<Double>(),
				new StoreMax<Double>(),
				new StoreMin<Double>(),
				new StoreAvg<Double>(0.0)
			) );
		temp_log.push( 16.0 );
		temp_log.push( List.of(17.5, 25.0, 20.5) );
		temp_log.log();

		Logger<Complex> ornt_log = new Logger<>("orientation",
			List.of(
				new StoreLast<Complex>(),
				new StoreMax<Complex>(),
				new StoreMin<Complex>()
//				new StoreAvg<Complex>(new Complex(0))
			) );
		ornt_log.push( List.of(	new Complex(0.0,1.5),
								new Complex(3.0),
								new Complex(2.5,1.0)  ) );
		ornt_log.log();
	}
}
