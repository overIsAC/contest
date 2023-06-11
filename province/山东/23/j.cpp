#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 3 + 1e5;

int fa[66][N];
int n, m, q;
LL V;

int find(int *fa, int p) {
    return fa[p] == p ? p : fa[p] = find(fa, fa[p]);
}

void merge(int *fa, int u, int v) {
    fa[find(fa, u)] = fa[find(fa, v)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q >> V;
    for (int i = 0; i < 60; ++i) {
        for (int j = 1; j <= n; ++j) {
            fa[i][j] = j;
        }
    }
    while (m--) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        int ok = 1;
        for (int i = 59; i >= 1; --i) {
            if (w >> i & 1) {
                if (V >> i & 1) {
                } else {
                    merge(fa[i], u, v);
                }
            } else {
                if (V >> i & 1) {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok && ((w & 1) >= (V & 1))) {
            merge(fa[0], u, v);
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        int ok = 0;
        for (int i = 59; i >= 1; --i) {
            if (find(fa[i], u) == find(fa[i], v)) {
                ok = 1;
                break;
            }
        }
        if (find(fa[0], u) == find(fa[0], v)) {
            ok = 1;
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}