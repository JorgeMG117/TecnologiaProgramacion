public abstract class Operacion
{
    protected Nodo izq;
    protected Nodo der;

    public Operacion(Nodo _izq, Nodo _der){
        izq = _izq;
        der = _der;
    }
}
