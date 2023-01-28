/*
Adjaceny List Implementation

Graph class with a private member V which represents the number of vertices in the graph,
and a private member adj which is a pointer to an array of vectors.
Each vector in the adj array represents the adjacency list of a vertex.

functions: addEdge and printGraph
- addEdge function takes two integers as arguments, representing the source and destination vertices of the edge,
and it adds the edge to the adjacency list of the source vertex
- printGraph function is used to print the adjacency list of each vertex in the graph.
*/
#include <iostream>
#include <vector>

class Graph {
private:
    int V;  // Number of vertices
    std::vector<int>* adj; // Pointer to an array containing adjacency lists

public:
    Graph(int V) {
        this->V = V;
        adj = new std::vector<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v's list.
    }

    void printGraph() {
        for (int v = 0; v < V; ++v) {
            std::cout << "\n Adjacency list of vertex " << v << "\n head ";
            for (auto x : adj[v])
                std::cout << "-> " << x;
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();
    return 0;
}
