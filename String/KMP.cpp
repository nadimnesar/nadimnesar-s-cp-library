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

vector< ll > build_lps(string &p) {
	ll sz = p.size();
	vector <ll> lps(sz, 0);
	ll j = 0;
	lps[0] = 0;
	for (ll i = 1; i < sz; i++) {
		while (j >= 0 && p[i] != p[j]) {
			if (j >= 1) j = lps[j - 1];
			else j = -1;
		}
		j++;
		lps[i] = j;
	}
	return lps;
}

vector < ll > ans;
void kmp(vector<ll> &lps, string &s, string &p) {
	ll psz = p.size();
	ll ssz = s.size();
	ll j = 0;
	for (ll i = 0; i < ssz; i++) {
		while (j >= 0 && p[j] != s[i]) {
			if (j >= 1) j = lps[j - 1];
			else j = -1;
		}
		j++;
		if (j == psz) {
			j = lps[j - 1];
			ans.push_back(i - psz + 1); // pattern found at position i-psz+1
		}
	}
}

void solve() {
	string s, p;
	cin >> s >> p;
	vector < ll > lps = build_lps(p);

	kmp(lps, s, p);

	cout << ans.size() << endl;
	for (ll i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	solve();

	return 0;
}