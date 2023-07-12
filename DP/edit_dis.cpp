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

string a, b;

ll dp[5000][5000];

ll edit(ll i, ll j) {
  if (i < 0 and j < 0) return 0;
  if (j < 0) return i + 1;
  if (i < 0) return j + 1;

  if (dp[i][j] != -1) return dp[i][j];

  if (a[i] == b[j]) return dp[i][j] = edit(i - 1, j - 1);

  return dp[i][j] = min({1 + edit(i - 1, j - 1), 1 + edit(i - 1, j), 1 + edit(i, j - 1)});
}

void solve() {
  cin >> a;
  cin >> b;

  for (ll i = 0; i < 5000; i++) {
    for (ll j = 0; j < 5000; j++) {
      dp[i][j] = -1;
    }
  }

  cout << edit(a.size() - 1, b.size() - 1) << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}