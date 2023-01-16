#include <bits/stdc++.h>
using namespace std;
#define maxx              (10000007)
#define ll               long long int
#define pop              pop_back

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
    for(ll i = 3; i < maxx; i+=2) if(!ifprime[i]) primes.pb(i);
}

bool pcheck(ll n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(!(n&1)) return false;
    if(!ifprime[n]) return true;
    else return false;
}

int main(){
    Sieve();
}