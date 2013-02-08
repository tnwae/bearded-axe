CXXFLAGS=-DDEBUG -g -Wall -Wextra -pedantic -I../include -DGL_GLEXT_PROTOTYPES
LXXFLAGS=-g -lm -lGL -lGLU -lglut
OBJS=BeardedAxe.o GlutCallbacks.o

all: $(OBJS)
	$(CXX) -I../include -o ba $(LXXFLAGS) $(OBJS)

.SUFFIXES: .cc.o
$*.o: $*.cc
	$(CXX) $(CXXFLAGS) $*.cc

.PHONY: clean
clean:
	-rm -rf *.o ba
