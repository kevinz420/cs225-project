
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

        void populate(string filename, int num_nodes) {
            numNodes = num_nodes;
            //TODO, get the data into graph representation
            //I think we should use integers to represent each node, then use the vector<string>
            //to get the data for index i in the form of an integer.
        }

        void addEdge(int first, int second) {
            adj[first][second] = 1;
            adj[second][first] = 1; //because undirected graph
        }
        bool containsEdge(int first, int second) const {
            return adj[first][second] == 1;
        }
        vector<int> getNeighbors(int curr) {
            vector<int> to_return;
            for (unsigned i = 0; i < adj[curr].size(); i++) {
                if (containsEdge(adj[curr][i]) && i != curr) to_return.push_back(adj[curr][i]);
            }
            return to_return;
        }
        void print() const {
            for (unsigned i = 0; i < adj.size(); i++) {
                for (unsigned j = 0; j < adj[i].size(); j++) {
                    cout << adj[i][j] << " ";
                }
                cout << "\n";
            }
        }
         
    private:
        vector<vector<int>> adj; //adjacency list containing the nodes and the edges
        vector<string> data; //given an id, return the data inside the node
        int numNodes = 0;
};