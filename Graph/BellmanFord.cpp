#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m;
    cin >> s;

    vector<pair<pair<int, int>, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
        // If the graph is undirected, add the reverse edge
        // edges.push_back({{v, u}, w});
    }

    vector<int> dist(n, INT_MAX); // Distance from source
    dist[s] = 0;

    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto it : edges) {
            int u = it.first.first;
            int v = it.first.second;
            int w = it.second;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto it : edges) {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;

        if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
            //Graph contains a negative-weight cycle.
            return -1;
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
