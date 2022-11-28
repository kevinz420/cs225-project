# INCLUDES=-I includes/
CXXFLAGS=-std=c++20 -g -fstandalone-debug -O0 -Wall -Wextra -Werror -pedantic
CXX=clang++

clean:
	rm -f bin/*

exec: main.cpp src/graph.cpp src/algorithms.cpp
	$(CXX) $(CXXFLAGS) $^ -o bin/exec

tests: tests/tests.cpp ./src/graph.cpp ./src/algorithms.cpp
	$(CXX) $(CXXFLAGS) $^ -o bin/tests

src/%.cc: includes/%.hpp
	touch $@

.DEFAULT_GOAL := tests
.PHONY: tests clean exec