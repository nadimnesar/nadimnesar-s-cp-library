ll binpow(ll n, ll p){
    if(p == 0) return 1;
    ll res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}