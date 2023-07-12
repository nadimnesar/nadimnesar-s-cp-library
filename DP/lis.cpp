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

  vector < ll > arr;
  for (ll i = 0; i < n; i++){
    ll temp;
    cin >> temp;
    arr.pb(temp);
  }

  vector < ll > dp;
  for (ll i = 0; i < n; i++) {
    ll idx = upper_bound(full(dp), arr[i]) - dp.begin();

    if (idx == dp.size()){
      if(dp.size() == 0) dp.pb(arr[i]);
      else if(dp[idx-1] < arr[i]) dp.pb(arr[i]);
    }
    else{
      if(idx == 0) dp[idx] = arr[i];
      else if(dp[idx-1] < arr[i]) dp[idx] = arr[i];
    }
  }

  cout << dp.size() << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}