#include "algorithms.h"



bool BFS(vector<vector<int>> adj, int src, int dest, int v,
         vector<int>& pred, vector<int>& dist)
{
    vector<bool> visited(v, 0);
 
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = 99999;
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 0;
    list<int> q;
    q.push_back(src);
 
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (unsigned i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                q.push_back(adj[u][i]);

                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
 
    return false;
}

vector<int> shortestPath(Graph g, int start, int destination) {
    // return vector of nodes in shortest path including start and destination
    // return empty vector if path doesnt exist
    // start = destination; // remove this
    // return g.getNeighbors(start); // remove this
    int v = (int)g.getAdjMatrix().size();
    vector<int> pred(v, 0);
    vector<int> dist(v, 0);

    vector<vector<int>> adj_list;
    for (int i = 0 ; i < v; i++) {
        vector<int> temp;
        for (int j = 0; j  < v; j++) {
            if (g.getAdjMatrix()[i][j] == 1) temp.push_back(j);
        }
        adj_list.push_back(temp);
    }

    if (BFS(adj_list, start, destination, v, pred, dist) == false) {

        vector<int> temp;
        return temp;
    }
    vector<int> path;
    int crawl = destination;
    path.push_back(crawl);
    
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }    
    
    reverse(path.begin(), path.end());
    return path;
}

vector<double> betweenessCentrality(Graph g) {
    int numNodes = g.getNumNodes();
    vector<double> centrality(numNodes, 0); // percentage of shortest paths that pass through each node
    for (int i = 0; i < numNodes; i++) {
        for (int j = i+1; j < numNodes; j++) {
            vector<int> shortestPath_ = shortestPath(g, i, j);
            for (size_t n = 0; n < shortestPath_.size(); n++) {
                int node = shortestPath_[n]; // node that shortest path goes through
                centrality[node]++;
            }
        }
    }
    double normalizer = (numNodes-1)*(numNodes-2)/2;
    for (double &d : centrality) {
        d /= normalizer;
    }
    return centrality;
}

vector<vector<double>> pageRanks(Graph g) {
    vector<vector<int>> adj = g.getAdjMatrix(); // n x n matrix
    vector<vector<double>> google(adj.size(), vector<double>(adj.size(), 0)); // google matrix
    for (size_t i = 0; i < adj.size(); i++) {
        for (size_t j = 0; j < adj[0].size(); j++) {
            if (adj[i][j] == 1) google[i][j] = 1;
        }
    }
    vector<vector<double>> probabilities(adj.size(), vector<double>{0}); // n x 1 vector
    probabilities[0][0] = 1;
    for (size_t col = 0; col < google[0].size(); col++) {
        // summing the column
        int sum = 0;
        for (size_t row = 0; row < google.size(); row++) {
            sum += adj[row][col];
        }
        for (size_t row = 0; row < google.size(); row++) {
            if (sum == 0) {
                google[row][col] = 1 / google[0].size();
            } else {
                google[row][col] /= sum;
            }
        }
        
    }

    for (int i = 0; i < 100; i++) { // power iteration
        probabilities = matmul(google, probabilities);
    }

    return probabilities;
}

vector<vector<double>> matmul(vector<vector<double>> a, vector<vector<double>> b) {
    int row1 = a.size();
    int col1 = a[0].size();
    int row2 = b.size();
    int col2 = b[0].size();

    assert(col1 = row2);

    vector<vector<double>> ans(row1, vector<double>(col2, 0));
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            ans[i][j] = 0;
            for (int k = 0; k < row2; k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

void printMatrix(vector<vector<double>> matrix) {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        // cout << '\n';
    }
}