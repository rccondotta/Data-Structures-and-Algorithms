"""
Graph class has an attribute adj_matrix which is a 2D list (or matrix)
representing the edges of the graph.

functions:
- add_edge method adds an edge between two vertices
- remove_edge method removes an edge between two vertices
- is_edge method checks if an edge exists between two vertices
- display method is used to display the adjacency matrix.
"""
class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_matrix = [[0 for _ in range(num_vertices)] for _ in range(num_vertices)]

    def add_edge(self, v1, v2):
        self.adj_matrix[v1][v2] = 1
        self.adj_matrix[v2][v1] = 1

    def remove_edge(self, v1, v2):
        if self.is_edge(v1, v2):
            self.adj_matrix[v1][v2] = 0
            self.adj_matrix[v2][v1] = 0

    def is_edge(self, v1, v2):
        return True if self.adj_matrix[v1][v2] > 0 else False

    def display(self):
        for row in self.adj_matrix:
            for val in row:
                print(val, end=" ")
            print()

# Example usage:
g = Graph(5)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)

print("Adjacency Matrix:")
g.display()

# Output:
# Adjacency Matrix:
# 0 1 1
# 1 0 1
# 1 1 0
# 0 0 0
# 0 0 0
