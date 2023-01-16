#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)(10)
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void nadimnesar() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    string b = s;
    reverse(full(b));
    if(s == b){
        cout << "YES" << endl;
        return;
    }

    ll l = 0;
    ll r = n-1;

    while(l < r){
        if(s[l] != s[r]){
            if(s[l] == 'B' and r-l+1 > 2) cout << "YES" << endl;
            else cout << "No" << endl;

            return;
        }
        l++;
        r--;
    }
    
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}