void segSeive(ll low, ll high) {
    vector < bool > area((high - low) + 1, true);
    for (ll i = 0; primes[i]*primes[i] <= high; i++) {
        ll start = ((low / primes[i]) * primes[i]);
        if (start < low) start += primes[i];
        for (ll j = start; j <= high; j += primes[i]) {
            if (j == primes[i]) continue;
            area[j - low] = false;
        }
    }

    for (ll i = 0; i < (high - low) + 1; i++) {
        if (area[i]) {
            if (i + low != 1 and i + low != 0) {
                cout << i + low << endl;
            }
        }
    }
}
