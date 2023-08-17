ll factorialPrimePower (ll n, ll p ) {
  ll freq = 0;
  ll cur = p;
  while (n / cur) {
    freq += n / cur;
    cur *= p;
  }
  return freq;
}

void factFactorize (ll n) {
  for ( ll i = 0; i < primes.size() && prime[i] <= n; i++ ) {
    ll p = prime[i];
    ll freq = 0;

    while ( n / p ) {
      freq += n / p;
      p *= prime[i];
    }
    
    cout << prime[i] << ' ' << freq << endl;
  }
}