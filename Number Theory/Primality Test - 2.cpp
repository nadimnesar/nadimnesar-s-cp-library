#include <cstdio>
#include <vector>
using namespace std;

#define ll                  long long int
#define pb                  push_back
#define maxx                (ll)(1.5e8+7)

vector < ll > primes;
vector < bool > ifprime(maxx);
void Sieve(){
    for(ll i = 3; i*i <= maxx; i += 2){
        if(!ifprime[i]){
            for(ll j = i*i; j < maxx; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    primes.pb(2);
    for(int i = 3; i < maxx; i+=2) if(!ifprime[i]) primes.pb(i);
}

bool pcheck(ll n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(!(n&1)) return false;
    if(!ifprime[n]) return true;
    else return false;
}

void solve() {
    ll n;
    scanf("%lld", &n);

    if(n <= 2e8) printf("%s\n", (pcheck(n) ? "YES": "NO"));
    else{
        bool flag = true;
        for(int i = 0; i < primes.size(); i++){
            if(n%primes[i] == 0){
                flag = false;
                break;
            }
        }
        printf("%s\n",  (flag ? "YES": "NO"));
    }
}

int main() {

    Sieve();
    int t;
    scanf("%d", &t);
    while (t--) solve();
    
    return 0;
}