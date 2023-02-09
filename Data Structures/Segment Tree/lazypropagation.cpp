#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const int mod = 1e9 + 7;
const int maxx = 3e4 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll segTree[4 * maxx];
ll lazy[4 * maxx];

void build(int idx, int left, int right) {
    if (left == right) {
        segTree[idx] = 0;
        return;
    }

    int mid = ((left + right) >> 1);
    build((idx << 1), left, mid);
    build((idx << 1) + 1, mid + 1, right);

    segTree[idx] = segTree[(idx << 1)] + segTree[(idx << 1) + 1];
}

void propagation(int idx, int left, int right) {
    segTree[idx] += (lazy[idx] * ((right - left) + 1));
    if (left != right) {
        lazy[(idx << 1)] += lazy[idx];
        lazy[(idx << 1) + 1] += lazy[idx];
    }
    lazy[idx] = 0;
}

void update(int idx, int left, int right, int p, int q, ll v) {
    if (lazy[idx]) propagation(idx, left, right);

    if (left > q or right < p) return;
    if (left >= p and right <= q) {
        segTree[idx] += (v * ((right - left) + 1));
        if (left != right) {
            lazy[(idx << 1)] += v;
            lazy[(idx << 1) + 1] += v;
        }
        return;
    }

    int mid = ((left + right) >> 1);
    update((idx << 1), left, mid, p, q, v);
    update((idx << 1) + 1, mid + 1, right, p, q, v);

    segTree[idx] = segTree[(idx << 1)] + segTree[(idx << 1) + 1];
}

ll quary(int idx, int left, int right, int p, int q) {
    if (lazy[idx]) propagation(idx, left, right);
    if (right < p or left > q) return 0;
    if (left >= p and right <= q) return segTree[idx];

    int mid = ((left + right) >> 1);
    return (quary((idx << 1), left, mid, p, q) +
            quary((idx << 1) + 1, mid + 1, right, p, q));
}

void solve() {
    ll n, c, type, p, q, v;
    cin >> n >> c;
    build(1, 1, n);
    for (int i = 1; i <= c; i++) {
        cin >> type;
        if (type) {
            cin >> p >> q;
            cout << quary(1, 1, n, p, q) << endl;
        }
        else {
            cin >> p >> q >> v;
            update(1, 1, n, p, q, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
        memset(segTree, 0);
        memset(lazy, 0);
    }
    return 0;
}
