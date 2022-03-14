PROG:=main-functor main-predicate
SRCS:=main-functor.cc main-predicate.cc

CXX:= g++ -Wall

OBJS:=$(SRCS:.cc=.o)

all: $(PROG)

main-functor: main-functor.o
	$(CXX) -o $@ $<

main-predicate: main-predicate.o
	$(CXX) -o $@ $<

.cc.o:
	$(CXX) -c $<

edit:
	geany -i -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s *.gch

# Dependencias
main-functor.o: functor.h
main-predicate.o: functor.h
