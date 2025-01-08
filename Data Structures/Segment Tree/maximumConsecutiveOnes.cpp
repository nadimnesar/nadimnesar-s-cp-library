#include "bits/stdc++.h"
using namespace std;

#define ll    int
#define endl  '\n'
const ll maxx = 5e5 + 7;

bool arr[maxx];

typedef struct node {
	ll mx1 = 0, lef1 = 0, rig1 = 0;
	bool tot1 = 0;
	ll mx0 = 0, lef0 = 0, rig0 = 0;
	bool tot0 = 0;
} node;

node segTree[4 * maxx];
ll lazy[4 * maxx];

node marge(node x, node y) {
	node z;

	z.lef1 = x.lef1 + (x.tot1 * y.lef1);
	z.lef0 = x.lef0 + (x.tot0 * y.lef0);

	z.rig1 = y.rig1 + (y.tot1 * x.rig1);
	z.rig0 = y.rig0 + (y.tot0 * x.rig0);

	z.tot1 = (x.tot1 and y.tot1);
	z.tot0 = (x.tot0 and y.tot0);

	z.mx1 = max({x.mx1, y.mx1, x.rig1 + y.lef1, z.lef1, z.rig1});
	z.mx0 = max({x.mx0, y.mx0, x.rig0 + y.lef0, z.lef0, z.rig0});

	return z;
}

void build(ll idx, ll left, ll right) {
	if (left > right) return;

	if (left == right) {
		segTree[idx].mx1 = arr[left];
		segTree[idx].lef1 = arr[left];
		segTree[idx].rig1 = arr[left];
		segTree[idx].tot1 = arr[left];

		segTree[idx].mx0 = !arr[left];
		segTree[idx].lef0 = !arr[left];
		segTree[idx].rig0 = !arr[left];
		segTree[idx].tot0 = !arr[left];
		return;
	}

	ll mid = ((left + right) >> 1);
	build((idx << 1), left, mid);
	build((idx << 1) + 1, mid + 1, right);

	segTree[idx] = marge(segTree[(idx << 1)], segTree[(idx << 1) + 1]);
}

void propagation(ll idx, ll left, ll right) {
	if (left > right) return;

	swap(segTree[idx].mx1,  segTree[idx].mx0);
	swap(segTree[idx].lef1,  segTree[idx].lef0);
	swap(segTree[idx].rig1,  segTree[idx].rig0);
	swap(segTree[idx].tot1,  segTree[idx].tot0);

	if (left != right) {
		lazy[(idx << 1)] ^= lazy[idx];
		lazy[(idx << 1) + 1] ^= lazy[idx];
	}

	lazy[idx] = 0;
}

void update(ll idx, ll left, ll right, ll p, ll q) {
	if (left > right) return;
	if (lazy[idx]) propagation(idx, left, right);

	if (left > q or right < p) return;
	if (left >= p and right <= q) {

		swap(segTree[idx].mx1,  segTree[idx].mx0);
		swap(segTree[idx].lef1,  segTree[idx].lef0);
		swap(segTree[idx].rig1,  segTree[idx].rig0);
		swap(segTree[idx].tot1,  segTree[idx].tot0);

		if (left != right) {
			lazy[(idx << 1)] ^= 1;
			lazy[(idx << 1) + 1] ^= 1;
		}
		return;
	}

	ll mid = ((left + right) >> 1);
	update((idx << 1), left, mid, p, q);
	update((idx << 1) + 1, mid + 1, right, p, q);

	segTree[idx] = marge(segTree[(idx << 1)], segTree[(idx << 1) + 1]);
}

node quary(ll idx, ll left, ll right, ll p, ll q) {
	if (lazy[idx]) propagation(idx, left, right);

	if (right < p or left > q) {
		node z;
		return z;
	}

	if (left >= p and right <= q) return segTree[idx];

	ll mid = ((left + right) >> 1);
	return marge(quary((idx << 1), left, mid, p, q),
	             quary((idx << 1) + 1, mid + 1, right, p, q));
}

void solve() {
	ll n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	for (ll i = 1; i <= n; i++) arr[i] = (s[i - 1] - '0');

	build(1, 1, n);

	while (q--) {
		ll type;
		cin >> type;
		if (type == 1) {
			ll p, q;
			cin >> p >> q;
			update(1, 1, n, p, q);
		}
		else {
			ll p, q;
			cin >> p >> q;
			cout << quary(1, 1, n, p, q).mx1 << endl;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	solve();
	

	return 0;
}
