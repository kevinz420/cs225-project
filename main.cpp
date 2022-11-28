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
    vector<int> ones{1,1};
    vector<int> twos{2,2};
    vector<vector<int>> a;
    a.push_back(ones);
    a.push_back(twos);
    vector<vector<int>> ans = matmul(a, a);
    
    return 0;
}