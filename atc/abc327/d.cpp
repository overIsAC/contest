#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int fa[N];
int n, m, a[N], b[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

void merge(int u, int v) {
    fa[find(u)] = find(v);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    for (int i = 1; i <= 2 * n; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        merge(a[i], b[i] + n);
        merge(a[i] + n, b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (find(i) == find(i + n)) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (find(a[i]) != find(b[i] + n)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}