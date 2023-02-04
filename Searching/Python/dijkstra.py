from heapq import heappush, heappop
import sys

# Number of nodes and edges
n, m = 5, 9

# Adjacency list to store the graph
adj = [[] for _ in range(n+1)]

# Array to store the minimum distance to each node
dist = [sys.maxsize] * (n+1)

# Array to store the visited nodes
vis = [False] * (n+1)

# Dijkstra's algorithm
def dijkstra(source):
    dist[source] = 0
    # Min-priority queue to pick the node with the minimum distance
    q = [(0, source)]
    while q:
        (d, u) = heappop(q)

        # Skip if the node has already been processed
        if vis[u]:
            continue

        vis[u] = True
        # Relax the edges and update the distance if it can be shortened
        for v, w in adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heappush(q, (dist[v], v))


if __name__ == '__main__':
    # Read the graph
    edges = [(1,2,4),(1,3,2),(2,3,1),(3,4,2),(3,5,4),(4,2,1),(4,5,2),(5,2,3),(5,4,1)]
    for u, v, w in edges:
        adj[u].append((v, w))
        adj[v].append((u, w))

    # Run Dijkstra's algorithm from node 1
    dijkstra(1)

    # Print the distance to all nodes
    print("The distance to all nodes from node 1 is: ", dist[1:])
