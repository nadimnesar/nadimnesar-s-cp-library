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

	struct node {
		node* next[26];
		bool isleaf = false;
		ll count[26] = { 0 };

		bool iscontain(char &ch) {
			return (next[ch - 'a'] != NULL);
		}
		void putnext(char &ch, node* nw) {
			next[ch - 'a'] = nw;
		}
		node* getnext(char &ch) {
			return next[ch - 'a'];
		}
	};

	node* root = new node();

	void add(string &s) {
		node* cur = root;
		for (auto it : s) {
			if (!(cur -> iscontain(it)))
				cur -> putnext(it, new node());
			cur -> count[it - 'a']++;
			cur = cur -> getnext(it);
		}
		cur -> isleaf = true;
	}

	bool search(string &s) {
		node* cur = root;
		for (auto it : s) {
			if (!(cur -> iscontain(it))) return false;
			cur = cur -> getnext(it);
		}
		return (cur -> isleaf);
	}

	ll count_prefix(string &s) {
		node* cur = root;
		ll ret;
		for (auto it : s) {
			if (!(cur -> iscontain(it))) return 0;
			ret = cur -> count[it - 'a'];
			cur = cur -> getnext(it);
		}
		return ret;
	}

	void clear(){
		clear(root);
	}

	void clear(node* cur){
		for(ll i = 0; i < 26; i++){
			if(cur -> next[i] != nullptr){
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

	Trie trie;

	vector < string > v;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.pb(s);
		trie.add(s);
	}

	bool flag = true;

	for (ll i = 0; i < n; i++) {
		if (trie.count_prefix(v[i]) > 1) {
			flag = false;
			break;
		}
	}

	cout << (flag ? "YES" : "NO") << endl;

	trie.clear();
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}