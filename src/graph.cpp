#include "graph.h"

Graph::Graph(string filename, int num_nodes) { // constructor (read in data)
    numNodes = num_nodes;
    //TODO, get the data into graph representation
    //I think we should use integers to represent each node, then use the vector<string>
    //to get the data for index i in the form of an integer.
}

void Graph::addEdge(int first, int second) {
    adj[first][second] = 1;
    adj[second][first] = 1; //because undirected graph
}

bool Graph::containsEdge(int first, int second) const {
    return adj[first][second] == 1;
}

// iterate through nodes and check if each is connected to curr
vector<int> Graph::getNeighbors(int curr) {
    vector<int> to_return;
    for (unsigned i = 0; i < numNodes; i++) { 
        if (containsEdge(curr, i) && i != curr) to_return.push_back(i);
    }
    return to_return;
}

// printing adj matrix
void Graph::print() const {
    for (unsigned i = 0; i < adj.size(); i++) {
        for (unsigned j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}
