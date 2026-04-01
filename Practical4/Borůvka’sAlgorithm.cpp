#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

int find(vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
    int xr = find(parent, x);
    int yr = find(parent, y);

    if (rank[xr] < rank[yr])
        parent[xr] = yr;
    else if (rank[xr] > rank[yr])
        parent[yr] = xr;
    else {
        parent[yr] = xr;
        rank[xr]++;
    }
}

void boruvka(int V, vector<Edge>& edges) {
    vector<int> parent(V), rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int numComponents = V;
    int mstWeight = 0;

    while (numComponents > 1) {
        vector<int> cheapest(V, -1);

        for (int i = 0; i < edges.size(); i++) {
            int u = find(parent, edges[i].u);
            int v = find(parent, edges[i].v);

            if (u != v) {
                if (cheapest[u] == -1 || edges[cheapest[u]].w > edges[i].w)
                    cheapest[u] = i;
                if (cheapest[v] == -1 || edges[cheapest[v]].w > edges[i].w)
                    cheapest[v] = i;
            }
        }

        for (int i = 0; i < V; i++) {
            if (cheapest[i] != -1) {
                Edge e = edges[cheapest[i]];
                int u = find(parent, e.u);
                int v = find(parent, e.v);

                if (u != v) {
                    mstWeight += e.w;
                    unite(parent, rank, u, v);
                    numComponents--;
                }
            }
        }
    }

    cout << "Weight of MST: " << mstWeight << endl;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5},
        {1,3,15}, {2,3,4}
    };

    boruvka(V, edges);
    return 0;
}