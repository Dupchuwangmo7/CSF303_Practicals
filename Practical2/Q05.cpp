#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<long long, int> pii;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pii>> adj(N+1);

    for(int i = 0; i < M; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(N+1, 1e18);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, w] : adj[u]) {
            if(dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    if(dist[N] == 1e18)
        cout << -1;
    else
        cout << dist[N];

    return 0;
}