#pragma once

#include "graph.h"
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

vector<vector<int>> pageRanks(Graph g);

// Matrix multiplication function
vector<vector<int>> matmul(vector<vector<int>> a, vector<vector<int>> b);

void printMatrix(vector<vector<int>> matrix);