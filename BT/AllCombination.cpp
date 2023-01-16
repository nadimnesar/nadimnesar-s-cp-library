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

void print(vector < ll > &storage){
    for(ll i = 0; i < storage.size(); i++){
        if(i == storage.size()-1) cout << storage[i] << endl;
        else cout << storage[i] << ' ';
    }
}

void AllCombination(vector < ll > &data, vector < ll > &storage, ll start, ll index){
    if(storage.size() == r){
        print(storage);
        return;
    }

    for(ll i = start; i < n; i++){
        storage.pb(data[index]);
        AllCombination(data, storage, i+1, index+1);
        storage.pop_back();
        index++;
    }
}

int main(){
    cin >> n >> r;
    vector < ll > data;
    for(ll i = 0; i < n; i++){
        ll value;
        cin >> value;
        data.pb(value);
    }
    vector < ll > storage;
    AllCombination(data, storage, 0, 0);
}