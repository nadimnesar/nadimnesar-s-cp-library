#include "bits/stdc++.h"
using namespace std;

#define ll    long long int
#define endl  '\n'
#define ff    first
#define ss    second
#define in    insert
#define pb    push_back

#define full(x) x.begin(),x.end()
#define dot(x)  fixed<<setprecision(x)

#define gcd(x, y) (ll)(__gcd(x, y))
#define lcm(x, y) (ll)((x/gcd(x,y))*y)
#define log(b, x) (double)(log(x)/log(b))

const ll maxx = 1e6 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll base[2] = { 169, 369 };
ll mod[2] = { 1000003769, 1000004569 };
ll pre[27][2][101];

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

struct hashing {
	ll n;
	string s;
	pair < ll, ll > fHash, bHash;

	void build() {
		fHash.ff = fHash.ss = 0;
		for (int i = 1; i <= n; i++) {
			fHash.ff *= base[0];
			fHash.ff %= mod[0];
			fHash.ff += (s[i] - 'a' + 1);

			fHash.ss *= base[1];
			fHash.ss %= mod[1];
			fHash.ss += (s[i] - 'a' + 1);
		}

		bHash.ff = bHash.ss = 0;
		for (int i = n; i >= 1; i--) {
			bHash.ff *= base[0];
			bHash.ff %= mod[0];
			bHash.ff += (s[i] - 'a' + 1);

			bHash.ss *= base[1];
			bHash.ss %= mod[1];
			bHash.ss += (s[i] - 'a' + 1);
		}
	}

	hashing() { }

	hashing(string _s) {
		n = _s.size();
		s = "." + _s;
		build();
	}

	void in_front(pair < ll, ll > v, ll c) {
		fHash.ff = ((v.ff * big_mod(base[0], n, mod[0])) + fHash.ff) % mod[0];
		fHash.ss = ((v.ss * big_mod(base[1], n, mod[1])) + fHash.ss) % mod[1];

		bHash.ff = (((bHash.ff * big_mod(base[0], c, mod[0])) % mod[0])
		            + v.ff) % mod[0];
		bHash.ss = (((bHash.ss * big_mod(base[1], c, mod[1])) % mod[1])
		            + v.ss) % mod[1];
		n += c;
	}

	void in_back(pair < ll, ll > v, ll c) {
		bHash.ff = ((v.ff * big_mod(base[0], n, mod[0])) + bHash.ff) % mod[0];
		bHash.ss = ((v.ss * big_mod(base[1], n, mod[1])) + bHash.ss) % mod[1];

		fHash.ff = (((fHash.ff * big_mod(base[0], c, mod[0])) % mod[0]) + v.ff) % mod[0];
		fHash.ss = (((fHash.ss * big_mod(base[1], c, mod[1])) % mod[1]) + v.ss) % mod[1];
		n += c;
	}

	bool ispalindrome() {
		if (fHash == bHash) return true;
		return false;
	}
};

void solve() {
	string s;
	cin >> s;

	hashing H(s);

	ll q;
	cin >> q;
	while (q--) {
		char type, ch;
		ll cnt;
		cin >> type >> ch >> cnt;

		if (type == 'L') {
			H.in_front({pre[ch - 'a' + 1][0][cnt],
			            pre[ch - 'a' + 1][1][cnt]
			           }, cnt);
		}
		else {
			H.in_back({pre[ch - 'a' + 1][0][cnt],
			           pre[ch - 'a' + 1][1][cnt]
			          }, cnt);
		}

		if (H.ispalindrome()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	for (char ch = 'a'; ch <= 'z'; ch++) {
		ll v0 = 0, v1 = 0;
		for (ll i = 1; i <= 100; i++) {
			v0 = (v0 * base[0]) % mod[0];
			v0 = (v0 + (ch - 'a' + 1)) % mod[0];

			v1 = (v1 * base[1]) % mod[1];
			v1 = (v1 + (ch - 'a' + 1)) % mod[1];

			pre[ch - 'a' + 1][0][i] = v0;
			pre[ch - 'a' + 1][1][i] = v1;
		}
	}

	ll t, cn = 0;
	cin >> t;
	while (t--) {
		cout << "Case " << ++cn << ":" << endl;
		solve();
	}

	return 0;
}