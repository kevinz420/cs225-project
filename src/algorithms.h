#pragma once

#include "graph.h"
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
#include <list>

using namespace std;

/*
BFS shortest path algorithm
Parameters: sample graph, start node, destination node
Returns: all nodes in the shortest path between start and destination
*/
vector<int> shortestPath(Graph g, int start, int destination);

/*
Helper function for shortest path algorithm
Parameters: adjacency matrix, start node, destination node, helper variables
Returns: true if path exists between src and dest, false otherwise
*/
bool BFS(vector<vector<int>> adj, int src, int dest, int v,
         vector<int>& pred, vector<int>& dist);

/*
Betweeness centrality algorithm (finds percentage of shortest paths that pass through each node)
Parameters: sample graph
Returns: vector that represents the centrality score for each node
*/
vector<double> betweenessCentrality(Graph g);

/*
PageRanks algorithm
Parameters: sample graph
Returns: vector that represents PageRanks score for each node
*/
vector<double> pageRanks(Graph g);

/* 
Matrix multiplication helper function
*/
vector<vector<double>> matmul(vector<vector<double>> a, vector<vector<double>> b);

/*
Prints 2D matrix
*/
void printMatrix(vector<vector<double>> matrix);