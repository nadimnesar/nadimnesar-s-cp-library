#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define first               ff
#define second              ss
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const int base = 69;
const int mod = 1e9 + 7;
const int maxx = 1e6 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll hashTable[maxx]; // 1_based_index
ll basePow[maxx];

void init() {
  basePow[0] = 1;
  for (ll i = 1; i < maxx; i++) {
    basePow[i] = (basePow[i - 1] * base) % mod;
  }
}

ll get_hashValue(string &str) {
  ll res = 0;
  for (ll i = 0; str[i]; i++) {
    res *= base; res %= mod;
    res += (str[i] - 'a' + 1);
  }
  return res;
}

void build_hashTable(string &str) {
  hashTable[0] = 0; hashTable[1] = (str[0] - 'a' + 1);
  for (ll i = 1; str[i]; i++) {
    hashTable[i+1] = ((hashTable[i] * base) % mod + (str[i] - 'a' + 1)) % mod;
  }
}

ll get_subHash(ll left, ll right) {
  return (ll)((hashTable[right] + mod) - ((hashTable[left - 1] * basePow[right - left + 1]) % mod)) % mod;
}

int main() {
  init();
  ll n;
  string sub, str;

  while (cin >> n) {
    cin >> sub >> str;

    build_hashTable(str);
    ll value = get_hashValue(sub);

    ll len = str.size();
    bool ok = false;
    for (int i = 1; i <= len-n+1; i++) {
      if (get_subHash(i, i+n-1) == value) {
        cout << i-1 << endl;
        ok = true;
      }
    }
    if (!ok) cout << endl;
  }
}