/*
Edge List
Graph class with a private member V which represents the number of vertices in the graph,
and a private member edges which is a vector of pairs of integers representing the edges in the graph.

functions: addEdge,removeEdge, and printGraph
- addEdge function takes two integers as arguments, representing the source and destination vertices of the edge,
and it adds the edge to the edge list
- removeEdge function takes two integers as arguments, representing the source and destination vertices of the edge,
and it removes the edge from the edge list
- printGraph function is used to print the edges of the graph.

Exampe is undirected graph,
if you want to implement a directed graph, you would have to store the edges differently,
for example, you can store a pair of integers as the source vertex, and destination vertex.

Plenty of other ways to implement graph with std::list or std::set
*/
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<pair<int, int>> edges; // Vector of edges

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int v, int w) {
        edges.push_back({v, w}); // Add edge between v and w
    }

    void removeEdge(int v, int w) {
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].first == v && edges[i].second == w) {
                edges.erase(edges.begin() + i); // Remove edge between v and w
                break;
            }
        }
    }

    void printGraph() {
        for (int i = 0; i < edges.size(); i++)
            cout << edges[i].first << " -> " << edges[i].second << endl;
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

    cout << "Graph edges :" << endl;
    g.printGraph();
    return 0;
}
