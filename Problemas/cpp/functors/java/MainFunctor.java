class MainFunctor
{
	public static void main(String[] argv)
	{
		System.out.println("sqr()");
		Functors.plot(new Functors.Sqr());
		System.out.println();

		System.out.println("mul_by(3)");
		Functors.plot(new Functors.MulBy(3));
		System.out.println();

		System.out.println("round()");
		Functors.plot(new Functors.Round());
		System.out.println();
	}
}

