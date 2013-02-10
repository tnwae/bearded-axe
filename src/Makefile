CXXFLAGS=-std=gnu++11 -DDEBUG -g -Wall -Wextra -pedantic -I../include -DGL_GLEXT_PROTOTYPES
LXXFLAGS=-g -lm -lGL -lGLU -lglut
OBJS=RenderObject.o GlutCallbacks.o BeardedAxe.o

all: $(OBJS)
	$(CXX) -I../include -o ba $(OBJS) $(LXXFLAGS) 

.SUFFIXES: .cc.o
$*.o: $*.cc
	$(CXX) $(CXXFLAGS) $*.cc

.PHONY: clean
clean:
	-rm -rf *.o ba
