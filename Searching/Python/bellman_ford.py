import sys

# Define a class to represent an edge in the graph
class Edge:
    def __init__(self, source, dest, weight):
        self.source = source
        self.dest = dest
        self.weight = weight

# Define a list of edges to represent the graph
edges = [Edge(0, 1, -1), Edge(0, 2, 4), Edge(1, 2, 3), Edge(1, 3, 2),
         Edge(1, 4, 2), Edge(3, 2, 5), Edge(3, 1, 1), Edge(4, 3, -3)]

# Define the number of vertices in the graph
V = 5

# Define a function to implement the Bellman-Ford algorithm
def BellmanFord(src):
    # Initialize the distance of each vertex from the source vertex with infinity
    dist = [float("inf") for i in range(V)]
    dist[src] = 0

    # Relax edges V - 1 times
    for i in range(V - 1):
        for edge in edges:
            u = edge.source
            v = edge.dest
            weight = edge.weight
            if dist[u] != float("inf") and dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight

    # Check for negative weight cycles
    for edge in edges:
        u = edge.source
        v = edge.dest
        weight = edge.weight
        if dist[u] != float("inf") and dist[u] + weight < dist[v]:
            print("Graph contains negative weight cycle")
            return

    # Print the shortest distance of each vertex from the source vertex
    print("Vertex Distance from Source")
    for i in range(V):
        print("%d\t\t%d" % (i, dist[i]))

# Test the implementation with a randomly generated example
if __name__ == "__main__":
    src = 0
    BellmanFord(src)
