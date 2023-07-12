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

string a, b, c;

ll dp[50][50][50];
ll lcs(ll i, ll j, ll k) {
  if (i < 0) return 0;
  if (j < 0) return 0;
  if (k < 0) return 0;

  if (dp[i][j][k] != -1) return dp[i][j][k];
  if (a[i] == b[j] and a[i] == c[k]) return dp[i][j][k] = 1 + lcs(i - 1, j - 1, k - 1);
  return dp[i][j][k] = max({lcs(i - 1, j, k), lcs(i, j - 1, k), lcs(i, j, k - 1)});
}

void solve() {
  cin >> a >> b >> c;
  cout << lcs(a.size() - 1, b.size() - 1, c.size() - 1) << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ll t, cn = 0;
  cin >> t;
  while (t--) {
    cout << "Case " << ++cn << ": ";
    for (ll i = 0; i < 50; i++) {
      for (ll j = 0; j < 50; j++) {
        for (ll k = 0; k < 50; k++) {
          dp[i][j][k] = -1;
        }
      }
    }
    
    solve();
  }

  return 0;
}