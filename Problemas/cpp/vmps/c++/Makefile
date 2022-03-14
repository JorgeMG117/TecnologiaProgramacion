PROG:=main
SRCS:=main.cc flota.cc

CXX:= g++ -march=native -O3

OBJS:=$(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

.cc.s:
	$(CXX) -c -S $<

edit:
	geany -i -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s

# Dependencias
main.o: vmp.h flota.h
flota.o: vmp.h flota.h
