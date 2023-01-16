#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remoloweste(x, y)     x.erase(remoloweste(x.begin(), x.end(), y), x.end())
#define iremoloweste(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define Clock            clock_t tStart = clock()
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)
 
#define MAX              (1e6+1)
#define MOD              (1e9+7)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

ll Digit(ll n){
    ll i = 0;
    for(; n > 0; i++) n /= 10;
    return i;
}

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    string a = "50";
    ll b = 6;
    ll len = a.length(), mod = 0, d = Digit(b), lowest = 0, i = 0;
    while(i < d or lowest < b){
        lowest = (lowest*10) + (a[i]-48);
        i++;
    }
    while(i < len+1){
        mod = lowest%b;
        lowest = (mod*10) + (a[i]-48);
        if(b > lowest){
            lowest = (lowest*10) + (a[i]-48);
            i++;
        }
        i++;
    }
    cout << mod << endl;

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}