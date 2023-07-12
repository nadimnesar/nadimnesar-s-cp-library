#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define endl            '\n'
#define in              insert
#define pb              push_back

#define full(x)         x.begin(),x.end()
#define dot(x)          fixed<<setprecision(x)

#define gcd(x, y)       (ll)(__gcd(x, y))
#define lcm(x, y)       (ll)((x/gcd(x,y))*y)
#define log(b, x)       (double)(log(x)/log(b))

const ll mod = 1e9 + 7;
const ll maxx = 1e6 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll weight[101];
ll value[101];

ll dp[100][100001];

ll knapsack(ll idx, ll w) {
  if (idx < 0) return 0;

  if(~dp[idx][w]) return dp[idx][w];

  if (weight[idx] > w) return dp[idx][w] = knapsack(idx - 1, w);

  return dp[idx][w] = max(value[idx] + knapsack(idx - 1, w - weight[idx]),
             knapsack(idx - 1, w));
}

void solve() {
  ll n, w;
  cin >> n >> w;

  for (ll i = 0; i < n; i++) cin >> weight[i] >> value[i];

  for (ll i = 0; i < 100; i++) {
    for (ll j = 0; j < 100001; j++) {
      dp[i][j] = -1;
    }
  }

  cout << knapsack(n - 1, w) << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}