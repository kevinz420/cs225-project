## Output/Correctness of Algorithms:
### 1. Shortest path: 
Our shortest path algorithm returns a list of nodes that are on the shortest path between a given start and end node, in the order that they appear in the path. To test this algorithm, we wrote test cases that verified that the algorithm returned the correct shortest path between various nodes in our test graph.

### 2. Betweenness centrality: 
Our betweenness centrality algorithm calculates the percentage of shortest paths in the graph that pass through each node (the centrality score). This function returns a vector that represents the centrality score for each node in the graph. Our test cases for this algorithm verify that the correct centrality score is returned for certain nodes, and that the “most central” node has the highest centrality score.

### 3. PageRank: 
Our PageRank algorithm returns a vector that represents the PageRank score for every node. In our context, the PageRank score represents how likely a user is to land on a certain Facebook page after randomly surfing Facebook for a long time. Our test cases for this algorithm checks that the correct PageRank score is returned for certain nodes.
 
## Answer to Leading Question:
Our leading question was: “How many pairs of users p1, p2 in a social network are connected by min_path(p1, p2) = n = 3?” We answered this question by implementing a shortest paths function that takes in two nodes (people) and returns a list of nodes on the shortest path between them. We called this function on all pairs of people in our Facebook dataset and found that around 53,000 pairs of people (from our dataset) are connected by a shortest path of length 3.
