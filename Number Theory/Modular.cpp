ll big_mod(ll B, ll P, ll M) {
    if (P == 0) return 1;
    if (P & 1) {
        ll p1 = B % M;
        ll p2 = (big_mod(B, P - 1, M)) % M;
        return (p1 * p2) % M;
    }
    else {
        ll p1 = (big_mod(B, P / 2, M)) % M;
        return (p1 * p1) % M;
    }
}

ll inverse_mod(ll B, ll M) {
    return big_mod(B, M - 2, M);
}

ll minus_mod(ll A, ll B, ll M) {
    ll res = (A - B) % M;
    if (res < 0) res += M;
    return (res % M);
}