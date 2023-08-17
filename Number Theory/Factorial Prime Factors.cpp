ll factorialPrimePower (ll n, ll p ) {
    ll freq = 0;
    ll cur = p;
    while (n / cur) {
        freq += n / cur;
        cur *= p;
    }
    return freq;
}

void factFactorize ( int n ) {
    for ( int i = 0; i < prime.size() && prime[i] <= n; i++ ) {
        int p = prime[i];
        int freq = 0;
 
        while ( n / p ) {
            freq += n / p;
            p *= prime[i];
        }
 
        printf ( "%d^%d\n", prime[i], freq ); // Printing prime^freq which is factor of N!
    }
