#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const int maxx = 1e6 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll base[2] = { 169, 369 };
ll mod[2] = { 1000003769, 1000004569 };
ll hashTable[2][maxx];
ll basePow[2][maxx];

void init() {
  basePow[0][0] = basePow[1][0] = 1;
  for (ll i = 1; i < maxx; i++) {
    basePow[0][i] = (basePow[0][i - 1] * base[0]) % mod[0];
    basePow[1][i] = (basePow[1][i - 1] * base[1]) % mod[1];
  }
}

void build_hashTable(string &str) { // 1 based inx
  hashTable[0][1] = hashTable[1][1] = (str[0] - 'a' + 1);
  for (ll i = 1; str[i]; i++) {
    hashTable[0][i + 1] = (((hashTable[0][i] * base[0]) % mod[0]) + (str[i] - 'a' + 1)) % mod[0];
    hashTable[1][i + 1] = (((hashTable[1][i] * base[1]) % mod[1]) + (str[i] - 'a' + 1)) % mod[1];
  }
}

pair < ll, ll > get_subHash(ll left, ll right) { // 1 based inx
  pair < ll, ll > sub;
  sub.first = ((hashTable[0][right] + mod[0]) - ((hashTable[0][left - 1] * basePow[0][right - left + 1]) % mod[0])) % mod[0];
  sub.second = ((hashTable[1][right] + mod[1]) - ((hashTable[1][left - 1] * basePow[1][right - left + 1]) % mod[1])) % mod[1];
  return sub;
}

pair < ll, ll > get_hashValue(string &str) {
  pair < ll, ll > res; res.first = 0; res.second = 0;
  for (ll i = 0; str[i]; i++) {
    res.first *= base[0]; res.first %= mod[0];
    res.first += (str[i] - 'a' + 1);

    res.second *= base[1]; res.second %= mod[1];
    res.second += (str[i] - 'a' + 1);
  }

  return res;
}

int main() {
  init();
  ll n;
  string sub, str;

  while (cin >> n) {
    cin >> sub >> str;

    build_hashTable(str);
    pair < ll, ll > value = get_hashValue(sub);

    ll len = str.size();
    bool ok = false;
    for (int i = 0; i < len - (n - 1); i++) {
      if (get_subHash(i + 1, i + (n - 1) + 1) == value) {
        cout << i << endl;
        ok = true;
      }
    }
    if (!ok) cout << endl;
  }
}