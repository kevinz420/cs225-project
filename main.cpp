#include <iostream>
#include "src/algorithms.h"
#include "src/graph.h"
/*
Compile: "make"
Run: "./bin/exec"
*/
using namespace std;

int main() {
    Graph g("facebook_combined.txt");
    // g.print();
    auto page = pageRanks(g);
    for (size_t i = 0; i < page.size(); i++) {
        if (page[i][0] > 0.05) cout << page[i][0] << " ";
    }
    return 0;
}