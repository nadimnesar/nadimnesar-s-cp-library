#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define memset(x, y)        memset(x,y,sizeof(x))

typedef struct node {
    ll l, r, idx;
} Node;

bool cmp(Node x, Node y) {
    return x.r < y.r;
}

ll n, q;
ll arr[30007];
ll bit[30007];
ll flag[1000007];

Node allquery[200007];
ll res[200007];

void update(ll idx, ll val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

ll query(ll idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

void magic(){
    ll qidx = 1;
    for (ll i = 1; i <= n; i++) {
        if (~flag[arr[i]]) update (flag[arr[i]], -1);

        flag[arr[i]] = i;
        update(i, +1);

        while (qidx <= q && allquery[qidx].r == i)
        {
            if(allquery[qidx].l > 1) res[allquery[qidx].idx] = query(allquery[qidx].r) - query(allquery[qidx].l-1);
            else res[allquery[qidx].idx] = query(allquery[qidx].r);
            qidx++;
        }
    }
}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    cin >> q;
    for (ll i = 1; i <= q; i++) {
        ll x, y;
        cin >> x >> y;

        allquery[i].l = x;
        allquery[i].r = y;
        allquery[i].idx = i;
    }

    sort(allquery+1, allquery+q+1, cmp);

    magic();

    for(ll i = 1; i <= q; i++) cout << res[i] << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    memset(flag, -1);
    memset(bit, 0);
    memset(res, 0);
    solve();

    return 0;
}