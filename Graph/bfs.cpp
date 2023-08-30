#include "bits/stdc++.h"
using namespace std;

#define ll					long long int
#define endl				'\n'
#define ff					first
#define ss 					second
#define in 					insert
#define pb					push_back

#define full(x)			x.begin(),x.end()
#define dot(x)			fixed<<setprecision(x)

#define gcd(x, y)		(ll)(__gcd(x, y))
#define lcm(x, y)		(ll)((x/gcd(x,y))*y)
#define log(b, x)		(double)(log(x)/log(b))

const ll mod = 1e9 + 7;
const ll maxx = 1e5 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

vector < int > graph[maxx];
int parent[maxx];
int dis[maxx];
bool visied[maxx];

void bfs(ll start) {
	queue < int > q;

	q.push(start);
	visied[start] = true;

	while (!q.empty()) {
		ll node = q.front();
		q.pop();
		for (auto it : graph[node]) {
			if (!visied[it]) {
				visied[it] = true;
				q.push(it);
				parent[it] = node;
				dis[it] = 1 + dis[node];
			}
		}
	}
}

void solve() {
	ll n, m;
	cin >> n >> m;

	for (ll i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	bfs(1);

	if (!visied[n]) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	vector < ll > path;
	ll at = n;

	while (at != -1) {
		path.pb(at);
		at = parent[at];
	}

	cout << path.size() << endl;
	while (!path.empty()) {
		cout << path.back() << ' ';
		path.pop_back();
	}
	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	memset(parent, -1, sizeof(parent));
	memset(dis, 0, sizeof(dis));

	solve();

	return 0;
}