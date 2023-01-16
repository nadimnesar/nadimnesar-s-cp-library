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

ll n, r;
void CombinationRepetitionUtil(vector < ll > chosen, vector < ll > v, ll index, ll start) {
    if (index == r) {
        for (ll i = 0; i < r; i++) cout << " " << v[chosen[i]];
        cout << "\n";
        return;
    }

    for (int i = start; i < n; i++) {
        chosen[index] = i;
        CombinationRepetitionUtil(chosen, v, index + 1, i);
    }
}

int main() {

    cin >> n;
    cin >> r;

    vector < ll > v;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    vector < ll > chosen(r+1);
    CombinationRepetitionUtil(chosen, v, 0, 0);

    return 0;
}
