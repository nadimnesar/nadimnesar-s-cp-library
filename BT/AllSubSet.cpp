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

ll n;
void print(vector < ll > &sub){
    for(ll i = 0; i < sub.size(); i++){
        if(i == sub.size()-1) cout << sub[i] << endl;
        else cout << sub[i] << ' ';
    }
}

void allsubsets(vector < ll > &set, vector < ll > &sub, ll index){
    if(index == n){
        print(sub);
        return;
    }
    sub.pb(set[index]);
    allsubsets(set, sub, index+1);
    sub.pop_back();
    allsubsets(set, sub, index+1);
}
 
int main(){
 
    cin >> n;
    vector < ll > set;
    for(ll i = 0; i < n; i++){
        ll value;
        cin >> value;
        set.pb(value);
    }

    vector < ll > sub;
    allsubsets(set, sub, 0);
}