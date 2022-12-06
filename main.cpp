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
    // vector<int> v = shortestPath(g, 8, 9);
    // for (int val : v) cout << val << " ";
    // cout << endl;
    vector<double> centrality = betweenessCentrality(g);
    for (double d : centrality) {
        cout << d << endl;
    }
    return 0;
}