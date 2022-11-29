#include "algorithms.h"

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

    for (int i = 0; i < 10; i++) { // power iteration
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