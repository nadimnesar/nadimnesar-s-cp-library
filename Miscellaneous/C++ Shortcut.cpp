• remove kth index
	v.erase(v.begin() + k)
• remove all value = k
	v.erase(remove(v.begin(), v.end(), k), v.end())
• make all unique value
    sort(full(x)); x.resize(distance(x.begin(), unique(full(x))));

ll dx[] = { 0, 0, 1, -1 };
ll dy[] = { 1, -1, 0, 0 };

ll knightx[8] = { +2, +2, -2, -2, +1, -1, -1, +1 };
ll knighty[8] = { -1, +1, +1, -1, +2, +2, -2, -2 };

bool valid(ll r, ll c) {
	if (r < 1) return false;
	if (r > 8) return false;
	if (c < 1) return false;
	if (c > 8) return false;
	return true;
}

#ifdef ONLINE_JUDGE
	clock_t tStart = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifdef ONLINE_JUDGE
	fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif