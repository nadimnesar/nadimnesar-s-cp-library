#include <bits/stdc++.h>
using namespace std;
 
#define llu                 long long unsigned int
#define ll                  long long int
 
#define ff                  first
#define ss                  second
#define pb                  push_back
#define popb                pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define rremove(x, y)       x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)       x.resize(distance(x.begin(),unique(x.begin(),x.begin()+y)))
#define fastIO              ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#define EPS                 (1e-7)
#define MAX                 (int)(1e5+7)
#define MOD                 (1e9+7)
#define PI                  (acos(-1.0))
#define LOG(b, x)           (log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#'; }

ll segTree[4*MAX];
ll lazy[4*MAX];
ll p, q, v;

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

void solve(){
    ll n, c, type;
    sf("%lld %lld", &n, &c);
    build(1, 1, n);
    for(ll i = 1; i <= c; i++){
        sf("%lld", &type);
        if(type){
            sf("%lld %lld", &p, &q);
            pf("%lld\n", quary(1, 1, n));
        }
        else{
            sf("%lld %lld %lld", &p, &q, &v);
            update(1, 1, n);
        }
    }
}

int main(){
    ll t;
    sf("%lld", &t);
    while(t--){
        solve();
        memset(segTree, 0, sizeof(segTree));
        memset(lazy, 0, sizeof(lazy));
    }
    return 0;
}
