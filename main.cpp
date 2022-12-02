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
    // g.print();
    vector<vector<double>> page = pageRanks(g);
    for (vector<double> p : page) {
        cout << p[0] << endl;
    }
    return 0;
}