#include "algorithms.h"

vector<vector<int>> pageRanks(Graph g) {
    vector<vector<int>> adj = g.getAdjMatrix(); // n x n matrix
    vector<vector<int>> probabilities(adj.size(), vector<int>()); // n x 1 vector
    probabilities[0][0] = 1;

    // normalize adj matrix
    for (size_t col = 0; col < adj[0].size(); col++) {
        // summing the column
        int sum = 0;
        for (size_t row = 0; row < adj.size(); row++) {
            sum += adj[row][col];
        }
        for (size_t row = 0; row < adj.size(); row++) {
            if (sum == 0) {
                adj[row][col] = 1 / adj[0].size();
            } else {
                adj[row][col] /= sum;
            }
        }
        
    }

    for (int i = 0; i < 100; i++) { // power iteration
        probabilities = matmul(adj, probabilities);
    }

    return probabilities;
}

vector<vector<int>> matmul(vector<vector<int>> a, vector<vector<int>> b) {
    int row1 = a.size();
    int col1 = a[0].size();
    int row2 = b.size();
    int col2 = b[0].size();

    assert(col1 = row2);

    vector<vector<int>> ans(row1, vector<int>(col2, 0));
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

void printMatrix(vector<vector<int>> matrix) {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}