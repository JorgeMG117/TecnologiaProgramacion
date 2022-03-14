import java.util.Collection;
import java.util.ArrayList;
import java.lang.reflect.*;

class Functors
{
	public static interface Functor<R,P> {
		R eval(P p);
	};

	public static class Sqr implements Functor<Float,Float> {
		public Float eval(Float x) { return x*x; }
	};

	public static class MulBy implements Functor<Float,Float> {
		private float factor;

		public MulBy(float f) { factor = f; }
		public Float eval(Float x) { return factor*x; }
	};

	public static class Round implements Functor<Integer,Float> {
		public Integer eval(Float x) { return Math.round(x); }
	};

	public static <R> void plot(Functor<R,Float> f) {
		System.out.print("   x =");
		for (float t=0; t<=6; t+=0.6)
			System.out.format("%6.2f",t);
		System.out.println();
		System.out.print("f(x) =");
		for (float t=0; t<=6; t+=0.6)
			System.out.print(f.eval(t)+" ");
		System.out.println();
	}

	public static interface Predicate<P> extends Functor<Boolean,P>
	{
	};

	public static class IsEven implements Predicate<Integer> {
		public Boolean eval(Integer x) {
			return (x%2)==0;
		}
	};

	public static class IsPrime implements Predicate<Integer> {
		public Boolean eval(Integer x) {
			if (x<3) return false;
			for (int i=2; i<x; i++)
				if ((x%i)==0) return false;
			return true;
		}
	};

	public static void select(Predicate<Integer> condicion, int a, int b) {
		for (int i=a; i<=b; ++i)
			if (condicion.eval(i)) System.out.print(i+" ");
		System.out.println();
	}

	public static <T> Collection<T> filter(Predicate<T> cond,Collection<T> org)
		throws	NoSuchMethodException,
				InstantiationException,
				InvocationTargetException,
				IllegalAccessException
	{
		Collection<T> res = org.getClass().getDeclaredConstructor().newInstance();
		for (T e : org)
			if (cond.eval(e)) res.add(e);
		return res;
	}

	public static <R,P> Collection<R> map(Functor<R,P> f,Collection<P> org)
		throws	NoSuchMethodException,
				InstantiationException,
				InvocationTargetException,
				IllegalAccessException
	{
		Collection<R> res = org.getClass().getDeclaredConstructor().newInstance();
		for (P e : org)
			res.add(f.eval(e));
		return res;
	}
}

