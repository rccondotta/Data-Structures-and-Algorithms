/*
Adjaceny Matrix

Graph class with a private member V which represents the number of vertices in the graph,
and a private member adj which is a pointer to a two-dimensional array representing the adjacency matrix.

functions: addEdge, removeEdge, and printGraph
- addEdge function takes two integers as arguments, representing the source and destination vertices of the edge,
and it adds the edge to the adjacency matrix
- removeEdge function takes two integers as arguments, representing the source and destination vertices of the edge,
and it removes the edge from the adjacency matrix
- printGraph function is used to print the adjacency matrix of the graph.

Example is undirected graph, if you want to implement a directed graph,
you would have to initialize the adjacency matrix with the value 0 and
only change the value in the corresponding cell to 1 when creating the edge.
*/
#include <iostream>

class Graph {
private:
    int V; // Number of vertices
    int** adj; // Pointer to an array containing the adjacency matrix

public:
    Graph(int V) {
        this->V = V;
        adj = new int*[V];
        for (int i = 0; i < V; i++)
            adj[i] = new int[V];

        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
    }

    void addEdge(int v, int w) {
        adj[v][w] = 1; // Add edge between v and w
    }

    void removeEdge(int v, int w) {
        adj[v][w] = 0; // Remove edge between v and w
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                std::cout << adj[i][j] << " ";
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Graph matrix :" << std::endl;
    g.printGraph();
    return 0;
}
