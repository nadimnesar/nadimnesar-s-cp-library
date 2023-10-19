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

const ll mod = 1e9 + 7;
const ll maxx = 1e6 + 7;
const double eps = 1e-7;
const double pi = acos(-1.0);

struct Trie {
	static const int bit = 32;

	struct node {
		node* next[2];
		int count[2] = { 0 };

		bool iscontain(bool v) {
			return (next[v] != NULL);
		}
		void putnext(bool v, node* nw) {
			next[v] = nw;
		}
		node* getnext(bool v) {
			return next[v];
		}
	};

	node* root = new node();

	void add(ll val) {
		node* cur = root;
		for (int i = bit - 1; i >= 0; i--) {
			bool b = val >> i & 1;
			if (!(cur -> iscontain(b)))
				cur -> putnext(b, new node());
			cur -> count[b]++;
			cur = cur -> getnext(b);
		}
	}

	int query(int x, int k) { // number of values that v ^ x < k
		node* cur = root;
		int ans = 0;
		for (int i = bit - 1; i >= 0; i--) {
			if (cur == nullptr) break;
			bool bx = x >> i & 1;
			bool bk = k >> i & 1;
			if (bk) {
				if (cur -> iscontain(bx)) ans += cur -> count[bx];
				cur = cur -> getnext(!bx);
			} else cur = cur -> getnext(bx);
		}
		return ans;
	}

	ll get_max(ll val) {
		node* cur = root;
		ll mxv = 0;
		for (int i = bit - 1; i >= 0; i--) {
			bool b = val >> i & 1;
			if (cur -> iscontain(!b)) {
				mxv = mxv | (1 << i);
				cur = cur -> getnext(!b);
			}
			else cur = cur -> getnext(b);
		}
		return mxv;
	}

	ll get_min(ll val) {
		node* cur = root;
		ll mnv = 0;
		for (int i = bit - 1; i >= 0; i--) {
			bool b = val >> i & 1;
			if (cur -> iscontain(b)) cur = cur -> getnext(b);
			else {
				cur = cur -> getnext(!b);
				mnv = mnv | (1 << i);
			}
		}
		return mnv;
	}

	void clear() {
		clear(root);
	}

	void clear(node* cur) {
		for (ll i = 0; i < 2; i++) {
			if (cur -> next[i] != nullptr) {
				clear(cur -> next[i]);
				cur -> next[i] = nullptr;
			}
		}
		delete(cur);
	}
};

void solve() {
	ll n;
	cin >> n;

	vector < ll > v;
	ll x = 0;
	for (ll i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		v.pb(x);
	}

	Trie trie;
	trie.add(0);

	ll mx = 0;
	ll mn = LLONG_MAX;
	for (ll i = 0; i < n; i++) {
		mx = max(mx, trie.get_max(v[i]));
		mn = min(mn, trie.get_min(v[i]));
		trie.add(v[i]);
	}

	cout << mx << ' ' << mn << endl;

	trie.clear();
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	ll t, cn = 0;
	cin >> t;
	while (t--) {
		cout << "Case " << ++cn << ": ";
		solve();
	}

	return 0;
}