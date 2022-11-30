#ifndef CONFIG_CATCH_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

#include "../src/graph.h"
#include "../src/algorithms.h"

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
