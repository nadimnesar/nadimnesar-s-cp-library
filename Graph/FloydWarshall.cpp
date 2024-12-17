#include <bits/stdc++.h>
using namespace std;

long long int dis[507][507];
void solve() {
    int n, m, q;
	cin >> n >> m >> q;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dis[i][j] = LLONG_MAX;
			if(i == j) dis[i][j] = 0;
		}
	}

	for(int i = 1; i <= m; i++) {
		long long int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = min(dis[u][v], w);
		dis[v][u] = min(dis[v][u], w);
	}

	for(int via = 1; via <= n; via++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(dis[i][via] <= 0 || dis[via][j] <= 0) {
					dis[i][j] = min(dis[i][j], dis[i][via] + dis[via][j]);
				}
				else if(dis[i][via] != LLONG_MAX && dis[via][j] != LLONG_MAX) {
					dis[i][j] = min(dis[i][j], dis[i][via] + dis[via][j]);
				}
			}
		}
	}

	while(q--) {
		int a, b;
		cin  >> a >> b;
		if(dis[a][b] == LLONG_MAX) cout << -1 << endl;
		else cout << dis[a][b] << endl;
	}
}

int main() {

	solve();

	return 0;
}
