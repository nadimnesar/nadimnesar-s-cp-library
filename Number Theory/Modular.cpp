ll big_mod(ll B, ll P, ll M) {
    if (P == 0) return 1;
    if (P & 1) {
        ll p1 = big_mod(B, P / 2, M);
        ll p2 = (p1 * B) % M;
        return (p1 * p2) % M;
    }
    else {
        ll p1 = big_mod(B, P / 2, M);
        return (p1 * p1) % M;
    }
}

ll bigmod(ll b, ll p) {
    ll x = 1;
    while (p) {
        if (p & 1)x = (x * b) % m;
        b = (b * b) % m;
        p >>= 1;
    } return x;
}

ll inverse_mod(ll B, ll M) {
    return big_mod(B, M - 2, M);
}

ll minus_mod(ll A, ll B, ll M) {
    ll res = (A - B) % M;
    if (res < 0) res += M;
    return (res % M);
}