/*
Edge List

Simple directed graph

output:
Edge 0: 0 -> 1  weight: 5
Edge 1: 0 -> 2  weight: 3
Edge 2: 1 -> 2  weight: 2
Edge 3: 2 -> 3  weight: 4
Edge 4: 3 -> 1  weight: 1
*/
#include <stdio.h>
#include <stdlib.h>

// Edge structure
struct Edge {
    int src;  // Source vertex
    int dest; // Destination vertex
    int weight; // weight of the edge
    struct Edge* next; // Pointer to the next edge
};

// Graph structure
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    struct Edge* edges; // Pointer to the edge list
};

// Function to create a new graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    static int i = 0;
    graph->edges[i].src = src;
    graph->edges[i].dest = dest;
    graph->edges[i].weight = weight;
    i++;
}

// Function to print the edge list
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->E; i++) {
        printf("Edge %d: %d -> %d  weight: %d\n", i, graph->edges[i].src, graph->edges[i].dest, graph->edges[i].weight);
    }
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    struct Graph* graph = createGraph(V, E);

    // Add edges to the graph
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 1, 1);

    // Print the edge list
    printGraph(graph);

    return 0;
}