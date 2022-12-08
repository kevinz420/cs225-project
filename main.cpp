#include <iostream>
#include "src/algorithms.h"
#include "src/graph.h"
/*
Compile: "make"
Run: "./bin/exec"
*/
using namespace std;

int main() {
    Graph g("test_graph.txt");
    vector<double> centrality = betweenessCentrality(g);
    for (double d : centrality) {
        cout << d << endl;
    }
    return 0;
}