PROG:=tst
SRCS:=rational.cc main.cc

CXX:= g++ -std=c++11 -O2

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

rational.o: rational.cc rational.h
main.o: main.cc rational.h
main.s: main.cc rational.h
