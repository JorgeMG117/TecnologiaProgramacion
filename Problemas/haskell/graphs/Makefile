SRCS=graphs.hs Graph.hs
PROG=graphs

all: $(PROG)

$(PROG):
	ghc --make $(SRCS)

edit:
	@geany $(SRCS) &

clean:
	@rm -f *.o *.hi $(PROG)

