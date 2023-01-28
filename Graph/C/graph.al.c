/*
Adjacency List

Simple undirected graph with 4 vertices and a few edges between them

output:
Vertex 0: 1 2
Vertex 1: 0 2
Vertex 2: 0 1 3
Vertex 3: 2
*/
#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int dest;
    struct Edge *next;
};

struct Graph {
    int V;
    struct Edge *list;
};

// Create a new edge node
struct Edge *newEdge(int dest) {
    struct Edge *newNode = (struct Edge*)malloc(sizeof(struct Edge));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a new graph
struct Graph *createGraph(int V) {
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->list = (struct Edge*)malloc(V * sizeof(struct Edge));
    for (int i = 0; i < V; i++) {
        graph->list[i].next = NULL;
    }
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    struct Edge *newNode = newEdge(dest);
    newNode->next = graph->list[src].next;
    graph->list[src].next = newNode;

    // For an undirected graph, add an edge from dest to src as well
    newNode = newEdge(src);
    newNode->next = graph->list[dest].next;
    graph->list[dest].next = newNode;
}

// Print the graph
void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Edge *temp = graph->list[i].next;
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Create a graph with 4 vertices
    struct Graph *graph = createGraph(4);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Print the graph
    printGraph(graph);

    return 0;
}
