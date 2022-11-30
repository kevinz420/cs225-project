#include <iostream>
#include "src/algorithms.h"
#include "src/graph.h"
/*
Compile: "make"
Run: "./bin/exec"
*/
using namespace std;

int main() {
    // Graph g("facebook_combined.txt");
    Graph g("test_graph.txt");
    g.print();
    // auto page = pageRanks(g);
    return 0;
}