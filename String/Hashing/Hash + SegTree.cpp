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

const ll maxx = 1e5 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

string str, revstr;
ll base[2] = { 169, 369 };
ll mod[2] = { 1000003769, 1000004569 };
ll basePow[2][maxx];

void init() {
	basePow[0][0] = basePow[1][0] = 1;
	for (ll i = 1; i < maxx; i++) {
		basePow[0][i] = (basePow[0][i - 1] * base[0]) % mod[0];
		basePow[1][i] = (basePow[1][i - 1] * base[1]) % mod[1];
	}
}

void preProcess(string s) {
	str = '.' + s;
	reverse(full(s));
	revstr = '.' + s;
}

typedef struct node {
	ll fHash0, fHash1;
	ll bHash0, bHash1;
	ll len = 0;
} node;

node hashTree[4 * maxx];

node marge(node left, node right) {
	if (!left.len) return right;
	if (!right.len) return left;

	node ret;
	ret.len = left.len + right.len;

	ret.fHash0 = (left.fHash0 * basePow[0][right.len]) % mod[0];
	ret.fHash0 = (ret.fHash0 + right.fHash0) % mod[0];

	ret.fHash1 = (left.fHash1 * basePow[1][right.len]) % mod[1];
	ret.fHash1 = (ret.fHash1 + right.fHash1) % mod[1];

	ret.bHash0 = (left.bHash0 * basePow[0][right.len]) % mod[0];
	ret.bHash0 = (ret.bHash0 + right.bHash0) % mod[0];

	ret.bHash1 = (left.bHash1 * basePow[1][right.len]) % mod[1];
	ret.bHash1 = (ret.bHash1 + right.bHash1) % mod[1];

	return ret;
}

void build_hashTree(ll idx, ll left, ll right) {
	if (left == right) {
		hashTree[idx].fHash0 = hashTree[idx].fHash1 = (str[left] - 'a' + 1);
		hashTree[idx].bHash0 = hashTree[idx].bHash1 = (revstr[left] - 'a' + 1);
		hashTree[idx].len = 1;
		return;
	}

	ll mid = (left + right) >> 1;
	build_hashTree((idx << 1), left, mid);
	build_hashTree((idx << 1) + 1, mid + 1, right);

	hashTree[idx] = marge(hashTree[(idx << 1)],
	                      hashTree[(idx << 1) + 1]);
}

node quary(ll idx, ll left, ll right, ll s, ll e) {
	if (right < s or left > e) {
		node ret;
		return ret;
	}
	if (left >= s and right <= e) return hashTree[idx];

	ll mid = (left + right) >> 1;
	return marge(quary((idx << 1), left, mid, s, e),
	             quary((idx << 1) + 1, mid + 1, right, s, e));
}

void updateF(ll idx, ll left, ll right, ll ith, char ch) {
	if (right < ith or left > ith) return;
	if (left == ith and right == ith) {
		hashTree[idx].fHash0 = hashTree[idx].fHash1 = (ch - 'a' + 1);
		return;
	}

	ll mid = (left + right) >> 1, l = (idx << 1), r = l + 1;
	updateF((idx << 1), left, mid, ith, ch);
	updateF((idx << 1) + 1, mid + 1, right, ith, ch);

	if (!hashTree[l].len) {
		hashTree[idx].fHash0 = hashTree[r].fHash0;
		hashTree[idx].fHash1 = hashTree[r].fHash1;
		hashTree[idx].len = hashTree[r].len;
	}
	else if (!hashTree[r].len) {
		hashTree[idx].fHash0 = hashTree[l].fHash0;
		hashTree[idx].fHash1 = hashTree[l].fHash1;
		hashTree[idx].len = hashTree[l].len;
	}
	else {
		hashTree[idx].len = hashTree[l].len + hashTree[r].len;
		hashTree[idx].fHash0 = (hashTree[l].fHash0 *
		                        basePow[0][hashTree[r].len]) % mod[0];
		hashTree[idx].fHash0 = (hashTree[idx].fHash0 +
		                        hashTree[r].fHash0) % mod[0];
		hashTree[idx].fHash1 = (hashTree[l].fHash1 *
		                        basePow[1][hashTree[r].len]) % mod[1];
		hashTree[idx].fHash1 = (hashTree[idx].fHash1 +
		                        hashTree[r].fHash1) % mod[1];
	}
}

void updateB(ll idx, ll left, ll right, ll ith, char ch) {
	if (right < ith or left > ith) return;
	if (left == ith and right == ith) {
		hashTree[idx].bHash0 = hashTree[idx].bHash1 = (ch - 'a' + 1);
		return;
	}

	ll mid = (left + right) >> 1, l = (idx << 1), r = l + 1;
	updateB((idx << 1), left, mid, ith, ch);
	updateB((idx << 1) + 1, mid + 1, right, ith, ch);

	if (!hashTree[l].len) {
		hashTree[idx].bHash0 = hashTree[r].bHash0;
		hashTree[idx].bHash1 = hashTree[r].bHash1;
		hashTree[idx].len = hashTree[r].len;
	}
	else if (!hashTree[r].len) {
		hashTree[idx].bHash0 = hashTree[l].bHash0;
		hashTree[idx].bHash1 = hashTree[l].bHash1;
		hashTree[idx].len = hashTree[l].len;
	}
	else {
		hashTree[idx].len = hashTree[l].len + hashTree[r].len;
		hashTree[idx].bHash0 = (hashTree[l].bHash0 *
		                        basePow[0][hashTree[r].len]) % mod[0];
		hashTree[idx].bHash0 = (hashTree[idx].bHash0 +
		                        hashTree[r].bHash0) % mod[0];
		hashTree[idx].bHash1 = (hashTree[l].bHash1 *
		                        basePow[1][hashTree[r].len]) % mod[1];
		hashTree[idx].bHash1 = (hashTree[idx].bHash1 +
		                        hashTree[r].bHash1) % mod[1];
	}
}

pair < ll, ll > backProcess(ll left, ll right) {
	pair < ll , ll > ret;
	ll n = str.size() - 1;
	ret.ss = n - left + 1;
	ret.ff = n - right + 1;
	return ret;
}

void solve() {
	string s;
	cin >> s;

	ll n = s.size();

	preProcess(s);
	build_hashTree(1, 1, n);

	ll q;
	cin >> q;
	while (q--) {
		char type, ch;
		cin >> type;
		if (type == 'U') {
			char ch;
			ll ith;
			cin >> ith >> ch;
			updateF(1, 1, n, ith, ch);
			pair < ll, ll > x = backProcess(ith, ith);
			updateB(1, 1, n, x.ff, ch);
		}
		else {
			ll left, right;
			cin >> left >> right;

			pair < ll , ll > x = backProcess(left, right);

			node f = quary(1, 1, n, left, right);
			node b = quary(1, 1, n, x.ff, x.ss);

			if (f.fHash0 == b.bHash0 and f.fHash1 == b.bHash1)
				cout << "Yes!" << endl;
			else cout << "No!" << endl;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	init();

	solve();

	return 0;
}

//https://toph.co/p/palindrome-query-i