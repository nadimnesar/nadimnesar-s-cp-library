string decToBinary(ll n){
    string res;
    for (ll i = 31; i >= 0; i--) {
        ll k = n >> i;
        if (k & 1) res += '1';
        else res += '0';
    }
    return res;
}