import java.util.List;

abstract class Store<T>
{
	protected T	val;

	public abstract String name();

	public abstract void push(T v);
	public void push(List<T> vl)
	{
		for (T v : vl) push(v);
	}

	public T value() { return val; }
}

class StoreLast<T> extends Store<T>
{
	public String name() { return "last"; }

	@Override
	public void push(T v)
	{
		val = v;
	}
}

class StoreMax<T extends Comparable<T>> extends Store<T>
{
	private boolean first = true;

	public String name() { return "max"; }

	@Override
	public void push(T v)
	{
		if (first)
		{
			val = v;
			first = false;
		}
		else
		{
			if (v.compareTo(val)>0) val = v;
		}
	}
}

class StoreMin<T extends Comparable<T>> extends Store<T>
{
	private boolean first = true;

	public String name() { return "min"; }

	@Override
	public void push(T v)
	{
		if (first)
		{
			val = v;
			first = false;
		}
		else
		{
			if (v.compareTo(val)<0) val = v;
		}
	}
}

class StoreAvg<T extends Number> extends Store<T>
{
	private int count;

	public StoreAvg(T ini) { val = ini; count = 0; }

	public String name() { return "average"; }

	@Override
	public void push(T v)
	{
		count++;
//		val = val+v;
		val = v;
	}

	@Override
	public T value()
	{
//		return (count>0 ? val.doubleValue()/count : val);
		return val;
	}
};
