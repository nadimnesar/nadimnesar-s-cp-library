#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)23
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

// Supports min, max, gcd, or, and.....etc

int n;
int arr[maxx];
int sTable[26][maxx];
int Lg[maxx];

void build_sTable(){
    for(int i = 0; i <= Lg[n]; i++){
        for(int j = 0; j+(1 << i) <= n; j++){
            if(i == 0) sTable[i][j] = arr[j];
            else sTable[i][j] = min(sTable[i-1][j], sTable[i-1][j+(1 << (i-1))]);
        }
    }
}

int serarch_MIN(ll l, ll r){
    int i = Lg[(r - l)+1];
    return min(sTable[i][l], sTable[i][(r-(1 << i))+1]);
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build_sTable();

    int q;
    cin >> q;
    while(q--){
        ll leftt, rightt;
        cin >> leftt >> rightt;
        cout << serarch_MIN(leftt, rightt) << endl;
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // 2^x = N
    // log10 2^x = log10 N
    // x = log10 N / log10 2
    // x = log2 N
    // now,,,
    // log2 N/2 = log2 N - log2 2
    // log2 N/2 = log2 N - 1
    // log2 N/2 + 1 = log2 N
    // so,,,,
    // x = log2 N/2 + 1

    Lg[1] = 0;
    for(int i = 2; i < maxx; i++) Lg[i] = Lg[i >> 1] + 1;

    solve();
    
    return 0;
}
