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

ll dp[3001][3001];

void solve() {
  string a, b;
  cin >> a >> b;

  for (ll i = 0; i <= a.size(); i++) {
    for (ll j = 0; j <= b.size(); j++) {
      if (i  == 0 or j == 0) dp[i][j] = 0;
      else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

 
  ll i = a.size();
  ll j = b.size();

  string lcs;
  while(i > 0 and j > 0){

    if(a[i-1] == b[j-1]){
      lcs += a[i-1];
      i--;
      j--;
      continue;
    }
    
    if(dp[i-1][j] > dp[i][j-1]) i--;
    else j--;
  }

  reverse(full(lcs));

  cout << lcs << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}