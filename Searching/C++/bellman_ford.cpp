#include <iostream>
#include <vector>
#include <limits.h>

// Define a structure to represent an edge in the graph
struct Edge {
    int source, dest, weight;
};

// Define a vector of edges to represent the graph
std::vector<Edge> edges = {
    {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
    {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
};

// Define the number of vertices in the graph
const int V = 5;

// Define a function to implement the Bellman-Ford algorithm
void BellmanFord(int src) {
    std::vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (auto edge : edges) {
            int u = edge.source;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative weight cycles
    for (auto edge : edges) {
        int u = edge.source;
        int v = edge.dest;
        int weight = edge.weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            std::cout << "Graph contains negative weight cycle" << std::endl;
            return;
        }
    }

    // Print the shortest distance of each vertex from the source vertex
    std::cout << "Vertex Distance from Source" << std::endl;
    for (int i = 0; i < V; i++)
        std::cout << i << "\t\t" << dist[i] << std::endl;
}

int main() {
    int src = 0;
    BellmanFord(src);

    return 0;
}
