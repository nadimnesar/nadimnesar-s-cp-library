#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
#define FastIO      ios_base::sync_with_stdio(false); cin.tie(0);
#define aPrint(a,b,c)for(int i=b;i<=c;i++)cout<<a[i]<<" ";cout<<endl;
#define vPrint(a)   for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;
#define Case(t)     printf("Case %d: ", t)
#define clr(x,a)    memset(x,a,sizeof(x))
#define debug(x)    cerr<<#x<<" = "<<(x)<<"\n"

#define umap        unordered_map
#define pii         pair<int, int>
#define ff          first
#define ss          second
#define mp          make_pair
#define pb          push_back
#define ppb         pop_back
#define sf          scanf
#define pf          printf
#define all(a)      a.begin(),a.end()
#define allr(a)     a.rbegin(),a.rend()
#define Unique(a)   sort(all(a)), a.erase(unique(all(a)),a.end())
template <class T> inline T bigmod(T b,T p,T M){T ret=1;for(;p>0;p>>=1){if(p&1) ret=(ret*b)%M;b=(b*b)%M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T lcm(T a,T b){return a*b / gcd<T>(a, b);}
template <class T> inline T power(T b,T p){ll x=1;while(p--)x*=b;return x;}
const ll mod = 1000000007;

#define pi        acos(-1.0)//3.1415926535897932
#define inf       1e9 + 7
#define MAX       1550
/// 'N'+'A'+'E'+'E'+'E'+'M' ///
ull base = 13331, poww[MAX], H[MAX];
int n, k, ans, cnt[MAX];
char s[MAX], t[MAX];
void prePower(){
    poww[0] = 1;
    for(int i=1; i<=n; i++){
        poww[i] = poww[i-1] * base;
    }
}
void computeHash(){
    for(int i=1; i<=n; i++){
        H[i] = (H[i-1] * base + s[i]);
    }
}
ll getHash(int l, int r){
    return (H[r]-H[l-1] * poww[r-l+1]);
}
int main()
{
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    FastIO;

    scanf("%s", s+1);
    scanf("%s", t+1);
    scanf("%d", &k);
    n = strlen(s+1);

    for(int i=1; i<=n; i++) {
        if(t[s[i]-'a'+1] == '0') cnt[i] = cnt[i-1] + 1;
        else cnt[i] = cnt[i-1];
    }
    prePower(); computeHash();
    //aPrint(cnt, 1, n); aPrint(H, 1, n);

    map<ll, bool> vis;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(cnt[j]-cnt[i-1] <= k){
                ll tmp = getHash(i, j);
                if(!vis.count(tmp)) {
                    //cout<<cnt[j]-cnt[i-1]<<" ,, "<<i<<" "<<j<<" = "<<tmp<<endl;
                    vis[tmp] = true, ans++;
                }
            }
        }
    }
    cout<<ans<<endl;

    #ifndef ONLINE_JUDGE
        printf("\n**Time -> %.10fs\n", (double)(clock()-tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
