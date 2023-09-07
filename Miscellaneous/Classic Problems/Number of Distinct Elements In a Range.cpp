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

ll n, qq;
ll arr[30007];

ll flag[1000007];
ll segTree[4*30007];
ll lazy[4*30007];
ll p, q, v;

Node allquery[200007];
ll res[200007];

void build(ll idx, ll left, ll right){
    if(left == right){
        segTree[idx] = 0;
        return;
    }

    ll mid = ((left+right) >> 1);
    build((idx << 1), left, mid);
    build((idx << 1)+1, mid+1, right);

    segTree[idx] = segTree[(idx << 1)] + segTree[(idx << 1)+1];
}

void propagation(ll idx, ll left, ll right){
    segTree[idx] += (lazy[idx]*((right-left)+1));
    if(left != right){
        lazy[(idx << 1)] += lazy[idx];
        lazy[(idx << 1)+1] += lazy[idx];
    }
    lazy[idx] = 0;
}

void update(ll idx, ll left, ll right){
    if(lazy[idx]) propagation(idx, left, right);

    if(left > q or right < p) return;
    if(left >= p and right <= q){
        segTree[idx] += (v*((right-left)+1));
        if(left != right){
            lazy[(idx << 1)] += v;
            lazy[(idx << 1)+1] += v;
        }
        return;
    }

    ll mid = ((left+right) >> 1);
    update((idx << 1), left, mid);
    update((idx << 1)+1, mid+1, right);

    segTree[idx] = segTree[(idx << 1)] + segTree[(idx << 1)+1];
}

ll quary(ll idx, ll left, ll right){

    if(lazy[idx]) propagation(idx, left, right);
    if(right < p or left > q) return 0;
    if(left >= p and right <= q) return segTree[idx];

    ll mid = ((left+right) >> 1);
    return (quary((idx << 1), left, mid)+quary((idx << 1)+1, mid+1, right));
}


void magic(){
    ll qidx = 1;
    for (ll i = 1; i <= n; i++) {
        if (~flag[arr[i]]){
            p = flag[arr[i]];
            q = flag[arr[i]];
            v = -1;
            update (1, 1, n);
        }

        flag[arr[i]] = i;
        p = i;
        q = i;
        v = 1;
        update (1, 1, n);

        while (qidx <= qq && allquery[qidx].r == i)
        {
            p = allquery[qidx].l, q = allquery[qidx].r;
            res[allquery[qidx].idx] = quary(1, 1, n);
            qidx++;
        }
    }
}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    cin >> qq;
    for (ll i = 1; i <= qq; i++) {
        ll x, y;
        cin >> x >> y;

        allquery[i].l = x;
        allquery[i].r = y;
        allquery[i].idx = i;
    }

    sort(allquery+1, allquery+qq+1, cmp);

    magic();

    for(ll i = 1; i <= qq; i++) cout << res[i] << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    memset(flag, -1);
    memset(segTree, 0);
    memset(lazy, 0);
    memset(res, 0);
    solve();

    return 0;
}