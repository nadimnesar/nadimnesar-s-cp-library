#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define untype              template<typename T>
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define pqueue              priority_queue<ll,vector<ll>,greater<ll>>
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

untype llu GCD(T a, T b) {if (b == 0) return a; return GCD(b, a % b);}
untype void vout(vector < T > &v) { for (llu i = 0; i < v.size(); i++) {
(i + 1 == v.size()) ? (cout << v[i] << endl) : (cout << v[i] << ' '); } }
untype llu LCM(T a, T b) {a = abs(a); b = abs(b); return (a / GCD(a, b)) * b;}
untype llu binpow(T n, T p){ if(p == 0) return 1; llu res = binpow(n, p/2);
if(p%2) return res*res*n; else return res*res; }

ll i, j, v;
ll arr[maxx];
vector < ll > segTree[maxx * 4];

vector < ll > marge(vector < ll > leftarray, vector < ll > rightarray){
    int i = 0;
    int j = 0;
    vector < ll > margearray;
    while(i < leftarray.size() and j < rightarray.size()){
        if(leftarray[i] <= rightarray[j]) margearray.pb(leftarray[i++]);
        else margearray.pb(rightarray[j++]);
    }
    while(i < leftarray.size()) margearray.pb(leftarray[i++]);
    while(j < rightarray.size()) margearray.pb(rightarray[j++]);

    return margearray;
}

void build_segTree(ll index, ll left, ll right){
    if(left == right){
        segTree[index].pb(arr[left]);
        return;
    }

    ll mid = (left+right) >> 1;
    build_segTree((index << 1), left, mid);
    build_segTree((index << 1)+1, mid+1, right);

    segTree[index] = marge(segTree[(index << 1)], segTree[(index << 1)+1]);
}

ll quary(int index, int left, int right){
    if(right < i or left > j) return 0;
    if(left >= i and right <= j){

        auto it = upper_bound(full(segTree[index]), v);
        if(it == segTree[index].end()) return 0;

        ll idx = it - segTree[index].begin();

        return segTree[index].size()-idx;
    }
        
    ll mid = (left+right) >> 1;
    ll left_product = quary((index << 1), left, mid);
    ll right_product = quary((index << 1)+1, mid+1, right);

    return (left_product+right_product);
}

void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> arr[i];
    build_segTree(1, 1, n);

    ll q;
    cin >> q;
    while(q--){
        cin >> i >> j >> v;
        cout << quary(1, 1, n) << endl;
    }

    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    // int t, cn = 0;
    // cin >> t;
    // while (t--) {
    //     // cout << "Case " << ++cn << ": ";
    //     solve();
    // }

    solve();

    // ll cn = 0;
    // while(cin >> n and n){
    //     cout << "Case " << ++cn << ": ";
        
    // }

    return 0;
}