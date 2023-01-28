"""
Graph class has an attribute edge_list which is a list of tuples,
each tuple represents an edge in the graph

functions:
- add_edge method adds an edge between two vertices
- remove_edge method removes an edge between two vertices
- is_edge method checks if an edge exists between two vertices
- display method is used to display the edges of the graph
"""
class Graph:
    def __init__(self):
        self.edge_list = []

    def add_edge(self, v1, v2):
        self.edge_list.append((v1, v2))

    def remove_edge(self, v1, v2):
        if self.is_edge(v1, v2):
            self.edge_list.remove((v1, v2))
            self.edge_list.remove((v2, v1))

    def is_edge(self, v1, v2):
        return (v1, v2) in self.edge_list or (v2, v1) in self.edge_list

    def display(self):
        for edge in self.edge_list:
            print(f"{edge[0]} --> {edge[1]}")

# Example usage:
g = Graph()
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 3)

print("Edge List:")
g.display()

# Output:
# Edge List:
# 0 --> 1
# 0 --> 2
# 1 --> 2
# 2 --> 3
