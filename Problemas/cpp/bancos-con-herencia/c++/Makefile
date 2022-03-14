PROG:=main
SRCS:=cuenta.cc cuenta-corriente.cc plazo-fijo.cc nomina.cc divisa.cc main.cc

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
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s

# Dependencias
cuenta.o: cuenta.cc cuenta.h
cuenta-corriente.o: cuenta-corriente.cc cuenta-corriente.h cuenta.h
plazo-fijo.o: plazo-fijo.cc plazo-fijo.h cuenta.h
nomina.o: nomina.cc nomina.h cuenta.h
divisa.o: divisa.cc divisa.h cuenta.h
main.o: main.cc cuenta.h cuenta-corriente.h plazo-fijo.h nomina.h divisa.h
