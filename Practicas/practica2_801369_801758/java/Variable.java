public class Variable implements Nodo
{
    private String variable;

    public Variable(String _variable){ variable = _variable; }

    @Override
    public String toString(){
        return variable;
    }

    @Override
    public float eval(SymbolTab syms){
        if(!syms.containsKey(variable)){
		    System.out.println("Error!!! ");
            return 0;
        }
        else{
            return syms.get(variable);
        }
    }
}
