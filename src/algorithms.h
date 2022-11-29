#pragma once

#include "graph.h"
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

vector<vector<double>> pageRanks(Graph g);

// Matrix multiplication function
vector<vector<double>> matmul(vector<vector<double>> a, vector<vector<double>> b);

void printMatrix(vector<vector<double>> matrix);