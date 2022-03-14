PROG:=Main.class
SRCS:=Main.java Store.java Logger.java

JAVA:= javac -O

all: $(PROG)

%.class: %.java
	$(JAVA) $<

go:
	@java $(basename $(PROG))

edit:
	geany -i -s *.java &

clean:
	@rm -f *.class core
