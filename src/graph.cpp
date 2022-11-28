#include "graph.h"

Graph::Graph() {}

Graph::Graph(string filename) { // constructor (read in data)
    string line;
    std::ifstream infile(filename);
    while (getline(infile, line)) {
        string p1 = "";
        string p2 = "";
        bool isFirst = true;
        for (auto c : line) {
            if (c == ' ') isFirst = false;
            else {
                if (isFirst) p1 += c;
                else p2 += c;
            }
        }

        int n1 = stoi(p1);
        int n2 = stoi(p2);

        addEdge(n1, n2);
    }
    numNodes = adj.size();
}

void Graph::addEdge(int first, int second) {
    if (first >= (int)adj.size() || second >= (int)adj.size()) {
        adj.resize(max(first, second) + 1);
        for (auto& row : adj) {
            row.resize(max(first, second) + 1);
        }
    }
    adj[first][second] = 1;
    adj[second][first] = 1; //because undirected graph
}

bool Graph::containsEdge(int first, int second) const {
    if (first >= (int)adj.size() || second >= (int)adj.size()) {
        return 0;
    }
    return adj[first][second] == 1;
}

// iterate through nodes and check if each is connected to curr
vector<int> Graph::getNeighbors(int curr) {
    vector<int> to_return;
    for (int i = 0; i < numNodes; i++) { 
        if (containsEdge(curr, i) && i != curr) to_return.push_back(i);
    }
    return to_return;
}

vector<vector<int> > Graph::getAdjMatrix() {
    return adj;
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
