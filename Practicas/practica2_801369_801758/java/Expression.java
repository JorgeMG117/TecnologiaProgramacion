import java.util.StringTokenizer;
import java.util.Stack;

class Expression
{
	// Raiz del arbol de terminos
    private Nodo root;

	// Constructores
    public Expression(String expr){
       parse(expr); 
    }

	private void parse(String s)
	{
		StringTokenizer st = new StringTokenizer(s);

		// Pila de terminos
		// Consulta el tipo de datos 'Stack' de Java
		Stack<Nodo> stk = new Stack<Nodo>();

		while (st.hasMoreTokens())
		{
			String tok = st.nextToken();

			if (tok.equals("+"))
			{
				// Apilar suma
				Nodo r = stk.pop();
				Nodo l = stk.pop();
				Suma o = new Suma(l, r);
				stk.push(o);
			}
			else if (tok.equals("-"))
			{
				// Apilar resta
				Nodo r = stk.pop();
				Nodo l = stk.pop();
				Resta o = new Resta(l, r);
				stk.push(o);
			}
			else if (tok.equals("*"))
			{
				// Apilar producto
				Nodo r = stk.pop();
				Nodo l = stk.pop();
				Multiplicacion o = new Multiplicacion(l, r);
				stk.push(o);
			}
			else if (tok.equals("/"))
			{
				// Apilar cociente
				Nodo r = stk.pop();
				Nodo l = stk.pop();
				Division o = new Division(l, r);
				stk.push(o);
			}
			else
			{
				// Variable o constante
				// Si comienza por un caracter no numerico,
				// es un nombre de variable
				if (Character.isLetter(tok.charAt(0)))
				{
					// Apilar variable
				    stk.push(new Variable(tok));	
				}
				else
				{
					float v = Float.valueOf(tok).floatValue();
					// Apilar constante
				    stk.push(new Constante(v));	
				}
			}
		}
		root = stk.peek(); 
	}

	public float eval(SymbolTab syms)
	{
		// Devuelve el resultado de evaluar la expresion
        return root.eval(syms);
	}

	@Override
	public String toString()
	{
		// Devuelve la cadena que representa la expresion
        return root.toString();
	}
};

