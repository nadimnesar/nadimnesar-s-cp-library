// indexing from right side and started at 0

ll turnOnK(ll mask, ll k) {
	return (mask | (1 << k));
}

ll turnOffK(ll mask, ll k) {
	return (mask & ~(1 << k));
}

bool isKthBitSet(ll mask, ll k) {
	if (mask & (1 << k)) return true;
	else return false;
}

ll get_bit_count(ll n){
    return __builtin_popcountll(n);
}