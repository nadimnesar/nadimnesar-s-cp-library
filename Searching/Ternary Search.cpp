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
#define maxx                (ll)(1e5+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void solve() {
    ll n;
    cin >> n;

    double v[n+7], t[n+7];

    double left = 1e8;
    double right = 0;

    for (ll i = 0; i < n; i++) cin >> v[i], left = min(v[i], left), right = max(v[i], right);
    for (ll i = 0; i < n; i++) cin >> t[i];

    while (abs(right - left) >= eps) {
        double mid1 = left + (right - left) / 3.0;
        double mid2 = right - (right - left) / 3.0;

        double time1 = -1, time2 = -1;
        for(ll i = 0; i < n; i++) time1 = max(t[i]+abs(v[i]-mid1), time1);
        for(ll i = 0; i < n; i++) time2 = max(t[i]+abs(v[i]-mid2), time2);

        if(time1 < time2) right = mid2;
        else left = mid1;
    }

    cout << dot(6) << left << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--) {
        // cout << "Case " << ++cn << ": ";
        solve();
    }
    // solve();

    return 0;
}