// Hugo Lázaro Zapata 801758
// Jorge Martinez Gil 801369

import java.lang.Iterable;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.lang.UnsupportedOperationException;

public class DynamicStack<T> extends Stack<T> implements Iterable<T>{

    private class nodo{
        public T dato;
        public nodo sig;
	};
    private nodo cima;
    private int total;

    @SuppressWarnings("unchecked")
	public DynamicStack()
	{
		cima = null;
		total = 0;
	}

    public boolean push(T t)
	{
		if(total == 0){
			cima = new nodo();
			cima.dato = t;
			cima.sig = null;
		}
		else{
			nodo nuevo = new nodo();
			nuevo.dato = t;
			nuevo.sig = cima;
			cima = nuevo;
		}
		total++;
		return true;
	}

	public boolean pop()
	{
		if(total > 1){ cima = cima.sig; }
		else if(total == 1){ cima = null; }
        else{ return false; }

        total--;
		return true;
	}

    private class StackIterator implements Iterator<T>{
        DynamicStack<T> stk;
		nodo i;

        private StackIterator(DynamicStack<T> stk)
		{
			this.stk = stk;
			i        = stk.cima;
		}

        public boolean hasNext(){ return i != null; }

        public T next() throws NoSuchElementException
		{
			if (!hasNext())
			{
				// Aquí lanzamos la excepción
				throw new NoSuchElementException();
			}
			else
			{
                T aux = i.dato;
				i = i.sig;
				return aux;

			}
		}

        public void remove() throws UnsupportedOperationException
		{
			throw new UnsupportedOperationException();
		}
    }

    public Iterator<T> iterator()
	{
		return new StackIterator(this);
	}

}