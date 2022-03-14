PROG:=main
SRCS:=buffer.cc tracer.cc main.cc

#CXX:= g++ -march=native -O3
CXX:= g++ -O0

OBJS:=$(SRCS:.cc=.o)

all: $(PROG) main.s

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

buffer.o: buffer.cc buffer.h tracer.h
tracer.o: tracer.cc tracer.h
main.o: main.cc buffer.h tracer.h
main.s: main.cc buffer.h tracer.h
