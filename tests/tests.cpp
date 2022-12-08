#ifndef CONFIG_CATCH_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

#include "../src/graph.h"
#include "../src/algorithms.h"
#include <cmath>

Graph make_graph() {
    Graph g("test_graph.txt");
    return g;
}

TEST_CASE("Graph constructor") {
    Graph test_graph = make_graph();
    REQUIRE(test_graph.getAdjMatrix().size() == 10);
    REQUIRE(test_graph.getNeighbors(1) == vector<int>{0, 2, 3, 9});
    REQUIRE(test_graph.containsEdge(7, 4) == test_graph.containsEdge(4, 7));
    REQUIRE(test_graph.containsEdge(-12, 24) == false);
}

TEST_CASE("Shortest path (path exists)") {
    Graph test_graph = make_graph();
    REQUIRE(shortestPath(test_graph, 0, 6) == vector<int>{0, 6});
    REQUIRE(shortestPath(test_graph, 4, 9) == vector<int>{4, 7, 9});
    REQUIRE(shortestPath(test_graph, 5, 0).size() == 3);
}

TEST_CASE("Shortest path (path doesn't exists)") {
    Graph test_graph = make_graph();
    REQUIRE(shortestPath(test_graph, 0, 12).size() == 0);
    REQUIRE_FALSE(shortestPath(test_graph, 8, 9).size() == 0);
}

TEST_CASE("PageRanks algorithm") {
    double tol = 0.001;
    Graph test_graph = make_graph();
    vector<double> pageRanks_matrix = pageRanks(test_graph);
    REQUIRE(pageRanks_matrix.size() == 10);
    REQUIRE(std::abs(pageRanks_matrix[7] - 0.125) < tol); // page ranks score for person 8 == 0.125
    REQUIRE(std::abs(pageRanks_matrix[4] - 0.075) < tol); // page ranks score for person 4 == 0.075
}

TEST_CASE("Betweeness Centrality algorithm") {
    double tol = 0.001;
    Graph test_graph = make_graph();
    vector<double> centrality = betweenessCentrality(test_graph);
    REQUIRE(std::abs(centrality[0] - 0.3611) < tol);
    double max_centrality = 0;
    int max_index = 0;
    for (size_t i = 0; i < centrality.size(); i++) {
        if (centrality[i] > max_centrality) {
            max_centrality = centrality[i];
            max_index = i;
        }
    }
    REQUIRE(max_index == 3);
}