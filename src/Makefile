CXXFLAGS=-std=gnu++11 -DDEBUG -g -Wall -Wextra -pedantic -I../include -DGL_GLEXT_PROTOTYPES
LXXFLAGS=-g -lm -lGL -lGLU -lglut
OBJS=RenderObject.o GlutCallbacks.o BeardedAxe.o UniformOperations.o \
  TeapotObject.o Scene.o GlobalState.o

all: $(OBJS)
	@$(CXX) -I../include -o ba $(OBJS) $(LXXFLAGS) 
	@echo "    [LD] ba"

.SUFFIXES: .cc.o
$*.o: $*.cc
	@$(CXX) $(CXXFLAGS) -c $*.cc
	@echo "    [CC] $*.o"

.PHONY: clean
clean:
	@-rm -rf *.o ba
	@echo "    [CLEAN] ."
