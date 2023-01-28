/*
Adjacency Matrix

Simple undirected graph with 4 vertices and a few edges between them

output:
0 1 1 0
1 0 1 0
1 1 0 1
0 0 1 0
*/
#include <stdio.h>

#define V 4 // Number of vertices

// Function to create a new graph
int **createGraph() {
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(int **graph, int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1; // For an undirected graph
}

// Function to print the graph
void printGraph(int **graph) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **graph = createGraph();

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Print the graph
    printGraph(graph);

    return 0;
}
