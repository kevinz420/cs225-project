#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class Graph {

    public:
        Graph();
        Graph(string filename); // constructor (read in data)
        bool containsEdge(int first, int second) const;
        vector<int> getNeighbors(int curr);
        vector<vector<int> > getAdjMatrix();
        void print() const;
         
    private:
        void addEdge(int first, int second);

        vector<vector<int> > adj; //adjacency matrix containing the nodes and the edges
        int numNodes = 0;
};