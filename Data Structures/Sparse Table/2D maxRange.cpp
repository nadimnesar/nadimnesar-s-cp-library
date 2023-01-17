#include<bits/stdc++.h>
using namespace std;

#define endl                '\n'
#define maxx                (int)(5e2+7)

const int LG = 10;

int st[maxx][maxx][LG][LG];
int a[maxx][maxx], lg2[maxx];

int search_max(int x1, int y1, int x2, int y2) {
    x2++; y2++;
    int a = lg2[x2 - x1], b = lg2[y2 - y1];
    return max(max(st[x1][y1][a][b], st[x2 - (1 << a)][y1][a][b]),
               max(st[x1][y2 - (1 << b)][a][b], st[x2 - (1 << a)][y2 - (1 << b)][a][b]));
}

void build2Dst(int n, int m) { // 0 indexed
    for (int a = 0; a < LG; a++) {
        for (int b = 0; b < LG; b++) {
            if (a + b == 0) continue;
            for (int i = 0; i + (1 << a) <= n; i++) {
                for (int j = 0; j + (1 << b) <= m; j++) {
                    if (!a) {
                        st[i][j][a][b] = max(st[i][j][a][b - 1], st[i][j + (1 << (b - 1))][a][b - 1]);
                    } else {
                        st[i][j][a][b] = max(st[i][j][a - 1][b], st[i + (1 << (a - 1))][j][a - 1][b]);
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    lg2[1] = 0;
    for (int i = 2; i < maxx; i++) lg2[i] = lg2[i >> 1] + 1;

    int t, cn = 0;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                st[i][j][0][0] = a[i][j];
            }
        }

        build2Dst(n, n);

        cout << "Case " << ++cn << ":" << endl;
        while (q--) {
            int x1, y1, s;
            cin >> x1 >> y1 >> s;
            int x4 =  x1 + s - 1, y4 = y1 + s - 1;

            x1--; y1--; x4--; y4--;
            cout << search_max(x1, y1, x4, y4) << endl;
        }
    }
    return 0;
}