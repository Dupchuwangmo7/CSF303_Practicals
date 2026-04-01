#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

bool bellmanFord(vector<Edge>& edges, int V, int src, vector<int>& dist) {
    dist.assign(V, INF);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // detect negative cycle
    for (auto &e : edges) {
        if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v])
            return false;
    }
    return true;
}

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int V, int src) {
    vector<int> dist(V, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void johnson(vector<Edge>& edges, int V) {
    vector<Edge> newEdges = edges;

    // add extra node
    for (int i = 0; i < V; i++)
        newEdges.push_back({V, i, 0});

    vector<int> h;
    if (!bellmanFord(newEdges, V + 1, V, h)) {
        cout << "Negative cycle detected\n";
        return;
    }

    // reweight edges
    vector<vector<pair<int,int>>> adj(V);
    for (auto &e : edges) {
        adj[e.u].push_back({e.v, e.w + h[e.u] - h[e.v]});
    }

    // run dijkstra
    for (int i = 0; i < V; i++) {
        vector<int> dist = dijkstra(adj, V, i);

        cout << "From node " << i << ": ";
        for (int j = 0; j < V; j++) {
            if (dist[j] == INF)
                cout << "INF ";
            else
                cout << dist[j] - h[i] + h[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<Edge> edges = {
        {0,1,3}, {0,2,8}, {1,2,2},
        {2,3,1}, {3,0,2}
    };

    int V = 4;
    johnson(edges, V);

    return 0;
}