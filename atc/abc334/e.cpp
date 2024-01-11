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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e3;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
char s[N][N];
int fa[N * N];

int get(int x, int y) {
    return (x - 1) * m + y;
}

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    for (int i = 1; i <= n * m; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '#') {
                for (int k = 0; k < 4; ++k) {
                    int tx = dx[k] + i, ty = dy[k] + j;
                    if (1 <= tx && tx <= n && 1 <= ty && ty <= m) {
                        if (s[tx][ty] == '#') {
                            int u = get(i, j), v = get(tx, ty);
                            u = find(u);
                            v = find(v);
                            if (u == v) {
                                continue;
                            }
                            fa[u] = v;
                        }
                    }
                }
            }
        }
    }

    int a = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '.') {
                ++a;
            } else {
                if (get(i, j) == find(get(i, j))) {
                    ++b;
                }
            }
        }
    }

    LL ans = 0;

    const int inv = qpow(a, mod - 2);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '.') {
                set<int> st;
                for (int k = 0; k < 4; ++k) {
                    int tx = dx[k] + i, ty = dy[k] + j;
                    if (1 <= tx && tx <= n && 1 <= ty && ty <= m) {
                        if (s[tx][ty] == '#') {
                            st.insert(find(get(tx, ty)));
                        }
                    }
                }
                ans += (LL)(b + 1 - st.size()) * inv;
                ans %= mod;
            }
        }
    }
    cout << ans << endl;

    return 0;
}