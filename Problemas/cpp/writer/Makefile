PROG:=main
SRCS:=main.cc writer.cc writer-direct.cc writer-cached.cc

CXX:= g++ -O3

OBJS:=$(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s

main.o: writer.h writer-cached.h writer-direct.h
writer.o: writer.h
writer-cached.o: writer.h writer-cached.h
writer-direct.o: writer.h writer-direct.h
