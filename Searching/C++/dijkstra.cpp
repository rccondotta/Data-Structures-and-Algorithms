#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
const int INF=0x3f3f3f3f;
vector<pair<int,int>> adj[N];
vector<int> dist(N,INF);
vector<bool> vis(N,false);
int n,m;

// Dijkstra's algorithm
void dijkstra(int source) {
    dist[source]=0;

    // Min-priority queue to pick the node with the minimum distance
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,source});

    while(!q.empty()) {
        auto [d,u]=q.top();
        q.pop();

        // Skip if the node has already been processed
        if(vis[u])
            continue;

        vis[u]=true;
        // Relax the edges and update the distance if it can be shortened
        for(auto &[v,w]:adj[u]) {
            if(dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
}

int main() {
    n = 5;
    m = 9;
    int edges[9][3] = {{1,2,4},{1,3,2},{2,3,1},{3,4,2},{3,5,4},{4,2,1},{4,5,2},{5,2,3},{5,4,1}};

    // Read the graph
    for(int i=0;i<m;i++) {
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    // Run Dijkstra's algorithm from node 1
    dijkstra(1);

    // Print the distance to all nodes
    cout<<"The distance to all nodes from node 1 is: ";
    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
    return 0;
}
