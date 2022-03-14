import java.util.List;
import java.util.ArrayList;

class Logger<T>
{
	private String			name;
	private List<Store<T>>	store;

	public Logger(String n,List<Store<T>> sl)
	{
		name  = n;
		store = new ArrayList<Store<T>>(sl);
	}

	public void push(T v)
	{
		for (Store<T> s : store) s.push(v);
	}
	public void push(List<T> vl)
	{
		for (Store<T> s : store) s.push(vl);
	}

	public void log()
	{
		System.out.println(name+":");
		for (Store<T> s : store)
			System.out.format("%10s: %s\n",s.name(),s.value());
		System.out.println();
	}
}
