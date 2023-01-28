"""
Graph class has an attribute graph which is a dictionary where the keys are the vertices
and the values are lists of connected vertices.

functions:
- add_vertex method adds a new vertex to the graph
- add_edge method creates an edge between two vertices
- print method displays the connections of each vertex in the graph.
"""
class Graph:
    def __init__(self):
        self.graph = {}

    def add_vertex(self, vertex):
        if vertex not in self.graph:
            self.graph[vertex] = []

    def add_edge(self, vertex1, vertex2):
        if vertex1 in self.graph:
            self.graph[vertex1].append(vertex2)
        else:
            self.graph[vertex1] = [vertex2]

    def print(self):
        for vertex in self.graph:
            print(vertex, "-->", " ".join(str(self.graph[vertex])))

# Example usage:
graph = Graph()

graph.add_vertex(0)
graph.add_vertex(1)
graph.add_vertex(2)
graph.add_vertex(3)

graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(1, 2)
graph.add_edge(2, 0)
graph.add_edge(2, 3)
graph.add_edge(3, 3)

print("Adjacency list:")
graph.print()

# Output:
# Adjacency list:
# 0 --> 1 2
# 1 --> 2
# 2 --> 0 3
# 3 --> 3
