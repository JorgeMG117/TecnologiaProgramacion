PROG:=Main.class
SRCS:=Cuenta.java CuentaCorriente.java Nomina.java Divisa.java Main.java

JAVA:= javac -O

all: $(PROG)

%.class: %.java
	$(JAVA) $<

go:
	@java $(basename $(PROG))

edit:
	geany -s *.java &

clean:
	@rm -f *.class core
