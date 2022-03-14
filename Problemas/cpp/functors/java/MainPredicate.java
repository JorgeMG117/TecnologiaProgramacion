import java.util.Collection;
import java.util.List;
import java.util.LinkedList;
import java.util.ArrayList;

class MainPredicate
{
	public static void main(String[] argv)
	{
		Functors.select(new Functors.IsEven(),1,10);
		Functors.select(new Functors.IsPrime(),1,30);

		try
		{
			List<Integer> l = new LinkedList(List.of(1,2,3,4,5,6,7,8,9,10));
			out(l);

			var lfe = Functors.filter(new Functors.IsEven(),l);
			out(lfe);
			var lfp = Functors.filter(new Functors.IsPrime(),l);
			out(lfp);

			var lme = Functors.map(new Functors.IsEven(),l);
			out(lme);
			var lmp = Functors.map(new Functors.IsPrime(),l);
			out(lmp);

			List<Integer> v = new ArrayList(List.of(1,2,3,4,5,6,7,8,9,10));
			out(v);

			var vfe = Functors.filter(new Functors.IsEven(),v);
			out(vfe);
			var vfp = Functors.filter(new Functors.IsPrime(),v);
			out(vfp);

			var vme = Functors.map(new Functors.IsEven(),v);
			out(vme);
			var vmp = Functors.map(new Functors.IsPrime(),v);
			out(vmp);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

	static <T> void out(Collection<T> c)
	{
		System.out.println(c.getClass().getName()+": "+c);
	}
}

