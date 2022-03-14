public class Resta extends Operacion implements Nodo
{
    public Resta(Nodo _izq, Nodo _der){ super(_izq, _der); }

    @Override
    public String toString(){
        return "(" + izq.toString() + "-" + der.toString() + ")";
    }

    @Override
    public float eval(SymbolTab syms){
        return izq.eval(syms) - der.eval(syms);
    }
}
