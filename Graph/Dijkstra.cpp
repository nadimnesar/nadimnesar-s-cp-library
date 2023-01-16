#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define endl                '\n'
#define pb                  push_back
#define full(x)             x.begin(),x.end()
#define maxx                (int)(1e5+1)
#define inf                 (ll)(1e12)
#define pi                  pair < int, int >

// Complexity: Edges * Log (Vartex)

vector < pi > graph[maxx];
priority_queue < pi, vector< pi >, greater < pi > > pq;
ll dis[maxx];
int parent[maxx];

void nadimnesar() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].pb({b, w});
        graph[b].pb({a, w});
    }

    for(int i = 1; i <= n; i++) dis[i] = inf;
    for(int i = 1; i <= n; i++) parent[i] = i;
    dis[1] = 0;
    pq.push({0, 1});

    while(pq.size()){
        int v = pq.top().second;
        pq.pop();
        for(int i = 0; i < graph[v].size(); i++){
            int u = graph[v][i].first;
            int ucost = graph[v][i].second;

            if(dis[u] > dis[v]+ucost){
                dis[u] = dis[v]+ucost;
                parent[u] = v;
                pq.push({dis[u], u});
            }
        }
    }

    vector < ll > v;

    int at = n;
    while(at != 1){
        if(parent[at] == at){
            cout << -1 << endl;
            return;
        }
        v.pb(at);
        at = parent[at];
    }
    v.pb(at);
    reverse(full(v));

    for(int i = 0; i < v.size(); i++) cout << v[i]  << ' ';
    cout << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}