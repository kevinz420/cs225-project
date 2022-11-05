## Leading Question 

Our graph contains all the users a part of a social network. Our algorithm works to find the number of 3rd degree or higher mutual connections.. As a result of the pandemic, connecting with people has become tougher – both professionally and socially. We aim to propose new connections between people by identifying those that have mutuals, but are unaware of these connections due to them being more degrees apart. We aim to use the Stanford Facebook dataset to solve this problem. We will construct a graph from the dataset provided after completing the necessary parsing which will involve filtering out NA values as well as values that are irrelevant to our project. We then plan to use Djikstra’s algorithm to find the shortest path between two nodes, which we will define as the degree of connection between two people. We will use DFS/BFS to traverse through our graph. There will be several different paths between two nodes because of the nature of mutual connections, but by identifying the shortest path, we are able to effectively construct a list of the pairs of people who are more than 2 degrees apart.

Leading question: How many pairs of users p1, p2 in a social network are connected by min_path(p1, p2) ≥ n = 3 degrees?

## Dataset Acquisition

## Data Format

We are acquiring our dataset from the Stanford Large Network Dataset Collection. We have chosen the “Social circles: Facebook” dataset which contains data on facebook users such as details about their profile (for example political party affiliation) and a list of their friends/connections. The file is a .txt file that contains about 4039 nodes and 88234 edges. It is formatted in two columns, the left is the node and the right column is the node that it is connected to. The size of the dataset is relatively large enough that we can draw a lot of conclusions from it but small enough that we can analyze the entire dataset. 



## Data Correction

We plan on parsing the input data using the C++ input stream (ifstream) library. To ensure the quality of the data, we intend on simply skipping over lines where data seems to be corrupted or does not exist (for example when there is nothing in the right column). 



## Data Storage

We will be using a struct to represent each node, where the struct contains the id of the node and a vector of ids representing every node that the current node is connected to (i.e. the edges). If there are about 4000 nodes (N) and 80000 edges (E). Since each edge must be contained in the struct of both nodes, the total Big O space complexity would be O(N + 2E). 



## Algorithm 

To answer the leading question, we will be using Djikstra’s algorithm to identify the shortest path between two nodes. We will also try using Brandes algorithm to find the shortest path, which is a BFS approach to the problem. The expected inputs for the algorithm would be a pair of nodes in the graph & the graph, which would come after we constructed the graph based on the provided input. The expected output for our algorithm would be the number of pairs of people who are more than 3 degrees of connection away from each other in the graph. Our estimated/target efficiency for the algorithm is O(V*2), where V represents the number of vertices in the graph.


## Timeline

Week 1 (11/7 – 11/13) - data acquisition & processing, converting input dataset into graph
Week 2 (11/14-11/20) – work on implementing Djikstra’s algorithm
Week 3 (11/28 – 12/4) – work on implementing Brandes algorithm, generating output
Week 4 (12/4 – 12/8) – final presentation deliverable preparation / slides
