PROG:=Main.class
SRCS:=Main.java

JAVAC:=javac

all: $(PROG)

$(PROG): $(SRCS)
	$(JAVAC) $<

.PHONY: edit go

go: $(PROG)
	java $(basename $(PROG))

edit:
	@geany -s -i *.java &

clean:
	@rm -f *.class core tags

#Main.class: Main.java Expression.java Term.java SymbolTab.java
Main.class: Main.java Expression.java SymbolTab.java Constante.java Nodo.java Suma.java Division.java Operacion.java Multiplicacion.java Resta.java Variable.java
