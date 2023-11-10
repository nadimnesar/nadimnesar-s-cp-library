// indexing from right side and started at 0
// take 2^n for masking n positions

ll turnOnK(ll mask, ll k) {
	return (mask | (1 << k));
}

ll turnOffK(ll mask, ll k) {
	return (mask & ~(1 << k));
}

ll toggleK(ll mask, ll k) {
	return (mask ^ (1 << k));
}

bool isKthBitSet(ll mask, ll k) {
	return (mask & (1 << k));
}

ll get_bit_count(ll n){ //return count of set bit
    return __builtin_popcountll(n);
}

bool checkPowerOf2(ll x){ //check either 2^y = x or not
	return (x and !(x&(x-1)));
}

▣ Bitwise

	• 2^n = (1 << n)
	• n * 2 = (n << 1)
	• n * 2^k = (n << k)
	• n / 2 = (n >> 1)
	• n / 2^k = (n >> k)
