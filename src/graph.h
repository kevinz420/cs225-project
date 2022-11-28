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
        void addEdge(int first, int second);
        bool containsEdge(int first, int second) const;
        vector<int> getNeighbors(int curr);
        vector<vector<int> > getAdjMatrix();
        void print() const;
         
    private:
        vector<vector<int> > adj; //adjacency matrix containing the nodes and the edges
        vector<string> data; //given an id, return the data inside the node
        int numNodes = 0;
};