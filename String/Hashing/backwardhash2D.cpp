#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const ll maxx = 1e5 + 7;

ll base[2] = { 169, 369 };
ll mod[2] = { 1000003769, 1000004569 };
ll basePow[2][maxx];
ll front_hashTable[2][maxx];
ll back_hashTable[2][maxx];
ll n;

void init() {
    basePow[0][0] = basePow[1][0] = 1;
    for (ll i = 1; i < maxx; i++) {
        basePow[0][i] = (basePow[0][i - 1] * base[0]) % mod[0];
        basePow[1][i] = (basePow[1][i - 1] * base[1]) % mod[1];
    }
}

void build_front_hashTable(string &str) { // 1 based idx
    front_hashTable[0][1] = front_hashTable[1][1] = (str[0] - 'a' + 1);
    for (ll i = 1; str[i]; i++) {
        front_hashTable[0][i + 1] = ((front_hashTable[0][i] * base[0]) + (str[i] - 'a' + 1)) % mod[0];
        front_hashTable[1][i + 1] = ((front_hashTable[1][i] * base[1]) + (str[i] - 'a' + 1)) % mod[1];
    }
}

pair < ll, ll > get_subHash(ll left, ll right) { // 1 based idx
    pair < ll, ll > sub;
    sub.first = (front_hashTable[0][right] - (front_hashTable[0][left - 1] * basePow[0][right - left + 1])) % mod[0];
    sub.second = (front_hashTable[1][right] - (front_hashTable[1][left - 1] * basePow[1][right - left + 1])) % mod[1];
    if (sub.first < 0) sub.first += mod[0];
    if (sub.second < 0) sub.second += mod[1];
    return sub;
}

void build_back_hashTable(string &str) { // 1 based idx
    back_hashTable[0][n] = back_hashTable[1][n] = (str[n - 1] - 'a' + 1);
    for (ll i = n - 2; i >= 0; i--) {
        back_hashTable[0][i + 1] = ((back_hashTable[0][i + 2] * base[0]) + (str[i] - 'a' + 1)) % mod[0];
        back_hashTable[1][i + 1] = ((back_hashTable[1][i + 2] * base[1]) + (str[i] - 'a' + 1)) % mod[1];
    }
}

pair < ll, ll > get_backward_subHash(ll left, ll right) { // 1 based idx
    pair < ll, ll > sub;
    sub.first = (back_hashTable[0][left] - (back_hashTable[0][right + 1] * basePow[0][right - left + 1])) % mod[0];
    sub.second = (back_hashTable[1][left] - (back_hashTable[1][right + 1] * basePow[1][right - left + 1])) % mod[1];
    if (sub.first < 0) sub.first += mod[0];
    if (sub.second < 0) sub.second += mod[1];
    return sub;
}

bool check(ll siz) {
    for (ll i = 1; i <= n - siz + 1; i++) {
        if (get_subHash(i, i+siz-1) == get_backward_subHash(i, i+siz-1)) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;

    string s;
    cin >> s;

    build_front_hashTable(s);
    build_back_hashTable(s);

    ll l = 1;
    ll r = n;
    ll mid, res = 0;

    while (l <= r) {
        mid = (l + r) / 2;

        if (check(mid)) {
            res = max(mid, res);
            l = mid + 1;
        }
        else if (check(mid + 1)) {
            res = max(mid + 1, res);
            l = mid + 2;
        }
        else  r = mid - 1;
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    init();

    ll t;
    cin >> t;
    while(t--){
        solve();
        memset(front_hashTable, 0);
        memset(back_hashTable, 0);
    }
    

    return 0;
}