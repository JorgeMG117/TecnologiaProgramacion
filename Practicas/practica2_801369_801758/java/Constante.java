public class Constante implements Nodo
{
    private float constante;

    public Constante(float _constante){ constante = _constante; }

    @Override
    public String toString(){
        return String.valueOf(constante);
    }

    @Override
    public float eval(SymbolTab syms){
        return constante;
    }
}
