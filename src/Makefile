CXXFLAGS=-std=c++17 -DDEBUG -g -Wall -Wextra -pedantic -I../include \
  -DGL_GLEXT_PROTOTYPES -fprofile-arcs -ftest-coverage
LXXFLAGS=-g -lm -lGL -lGLU -lglut -lpng -fprofile-arcs -ftest-coverage
OBJS=RenderObject.o GlutCallbacks.o BeardedAxe.o UniformOperations.o \
  SphereObject.o CubeObject.o TeapotObject.o Scene.o GlobalState.o \
	Extras.o

all: $(OBJS)
	$(CXX) -I../include -o ba $(OBJS) $(LXXFLAGS) 

.SUFFIXES: .cc.o
$*.o: $*.cc
	$(CXX) $(CXXFLAGS) -c $*.cc

.PHONY: clean
clean:
	-rm -rf *.o *.gcov *.gcda *.gcno ba

