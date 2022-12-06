#pragma once

#include "graph.h"
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
#include <list>

using namespace std;

vector<int> shortestPath(Graph g, int start, int destination); // BFS shortest path

bool BFS(vector<vector<int>> adj, int src, int dest, int v,
         vector<int>& pred, vector<int>& dist);

vector<double> betweenessCentrality(Graph g);

vector<vector<double>> pageRanks(Graph g);

// Matrix multiplication function
vector<vector<double>> matmul(vector<vector<double>> a, vector<vector<double>> b);

void printMatrix(vector<vector<double>> matrix);