SRCS=vessels.hs Graph.hs
PROG=vessels

all: $(PROG)

$(PROG):
	ghc --make $(SRCS)

edit:
	@geany $(SRCS) &

clean:
	@rm -f *.o *.hi $(PROG)

