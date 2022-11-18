INCLUDES=-I includes/
CXXFLAGS=-std=c++20 -g -fstandalone-debug -O0 -Wall -Wextra -Werror -pedantic $(INCLUDES)
CXX=clang++

clean:
	rm -f bin/*

exec: bin/exec

bin/exec: main.cpp src/algorithms.h src/graph.h src/algorithms.cpp src/graph.cpp
	${CXX} ${CXX_FLAGS} main.cpp src/algorithms.cpp src/graph.cpp -o bin/exec

tests: tests/tests.cpp src/algorithms.cpp
	$(CXX) $(CXXFLAGS) $^ -o bin/tests

.DEFAULT_GOAL := exec
