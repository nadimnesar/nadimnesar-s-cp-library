#define llu                 long long unsigned int
#define ll                  long long int

#define ff                  first
#define ss                  second
#define pb                  push_back
#define popb                pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define rremove(x, y)       x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x)    		sort(full(x)); x.resize(distance(x.begin(),unique(full(x))));

#define fastIO              ios_base::sync_with_stdio(false);cin.tie(nullptr)

#define EPS                 (1e-7)
#define MAX                 (int)(1e5+7)
#define MOD                 (1e9+7)
#define PI                  (acos(-1.0))
#define LOG(b, x)           (log(x)/log(b))

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y) {cerr << '#' << X << ": " << Y << endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M) {cerr << '#'; }

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define untype              template<typename T>
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define pqueue              priority_queue<ll,vector<ll>,greater<ll>>
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

untype llu GCD(T a, T b) {if (b == 0) return a; return GCD(b, a % b);}
untype void vout(vector < T > &v) {
	for (llu i = 0; i < v.size(); i++) {
		(i + 1 == v.size()) ? (cout << v[i] << endl) : (cout << v[i] << ' ');
	}
}
untype llu LCM(T a, T b) {a = abs(a); b = abs(b); return (a / GCD(a, b)) * b;}
untype llu binpow(T n, T p) {
	if (p == 0) return 1; llu res = binpow(n, p / 2);
	if (p % 2) return res * res * n; else return res * res;
}

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