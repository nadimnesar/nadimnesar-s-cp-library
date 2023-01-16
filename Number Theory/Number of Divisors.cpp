ll nod(ll n){
    ll divisor = 1;
    for (ll i = 0; primes[i]*primes[i] <= n; i++){
        if (n%primes[i] == 0){
            ll cnt = 1;
            while(n % primes[i] == 0){
                n /= primes[i];
                cnt++;
            }
            divisor *= cnt;
        }
    }
    if (n > 1) divisor *= 2;
    return divisor;
}