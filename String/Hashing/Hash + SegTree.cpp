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

string str;
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

typedef struct node {
	ll fHash0 = 0, fHash1 = 0;
	ll bHash0 = 0, bHash1 = 0;
	ll len = 0;
} node;

node hashTree[4 * maxx];

node marge(node left, node right) {
	node ret;
	ret.len = left.len + right.len;

	ret.fHash0 = (left.fHash0 * basePow[0][right.len]) % mod[0];
	ret.fHash0 = (ret.fHash0 + right.fHash0) % mod[0];

	ret.bHash0 = (right.bHash0 * basePow[0][left.len]) % mod[0];
	ret.bHash0 = (ret.bHash0 + left.bHash0) % mod[0];

	ret.fHash1 = (left.fHash1 * basePow[1][right.len]) % mod[1];
	ret.fHash1 = (ret.fHash1 + right.fHash1) % mod[1];

	ret.bHash1 = (right.bHash1 * basePow[1][left.len]) % mod[1];
	ret.bHash1 = (ret.bHash1 + left.bHash1) % mod[1];

	return ret;
}

node makedata(ll v) {
	node ret;
	ret.len = v ? 1 : 0;
	ret.fHash0 = ret.fHash1 = ret.bHash0 = ret.bHash1 = v;
	return ret;
}

void build_hashTree(ll idx, ll left, ll right) {
	if (left == right) {
		hashTree[idx] = makedata(str[left] - 'a' + 1);
		return;
	}

	ll mid = (left + right) >> 1, l = (idx << 1), r = l + 1;
	build_hashTree(l, left, mid);
	build_hashTree(r, mid + 1, right);

	hashTree[idx] = marge(hashTree[l], hashTree[r]);
}

node quary(ll idx, ll left, ll right, ll s, ll e) {
	if (right < s or left > e) return makedata(0);
	if (left >= s and right <= e) return hashTree[idx];

	ll mid = (left + right) >> 1, l = (idx << 1), r = l + 1;
	return marge(quary(l, left, mid, s, e), quary(r, mid + 1, right, s, e));
}

void update(ll idx, ll left, ll right, ll ith, ll v) {
	if (right < ith or left > ith) return;
	if (left == ith and right == ith) {
		hashTree[idx] = makedata(v);
		return;
	}

	ll mid = (left + right) >> 1, l = (idx << 1), r = l + 1;
	update(l, left, mid, ith, v);
	update(r, mid + 1, right, ith, v);

	hashTree[idx] = marge(hashTree[l], hashTree[r]);
}

void solve() {
	string s;
	cin >> s;

	ll n = s.size();

	str = '.' + s; //set string 1 base index
	build_hashTree(1, 1, n); //build tree

	ll q;
	cin >> q;
	while (q--) {
		char type, ch;
		cin >> type;
		if (type == 'U') {
			char ch;
			ll ith;
			cin >> ith >> ch;
			update(1, 1, n, ith, ch - 'a' + 1);
		}
		else {
			ll l, r;
			cin >> l >> r;
			node res = quary(1, 1, n, l, r);
			if (res.fHash0 == res.bHash0 and res.fHash1 == res.bHash1)
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

//https://toph.co/p/palindrome-query-i //ignored delete part