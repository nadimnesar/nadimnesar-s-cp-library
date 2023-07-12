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

void solve() {
  ll n;
  cin >> n;

  ll arr[n];
  for (ll i = 0; i < n; i++) cin >> arr[i];

  vector < ll > dp(n+1, LLONG_MAX);
  dp[0] = -LLONG_MAX;

  for(ll i = 1; i <= n; i++) dp[i] = LLONG_MAX;

  for (ll i = 0; i < n; i++) {
    ll idx = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
    
    if(dp[idx-1] < arr[i]) dp[idx] = arr[i];
  }

  ll lis = 0;
  for(ll i = 1; i <= n; i++){
    if(dp[i] < LLONG_MAX) lis = i;
  }

  cout << lis << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}