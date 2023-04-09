#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int fa[N], sz[N];
char s[1003][1003];
int n, m, q;

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

int get(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n * m; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
        db(s[i] + 1);
    }
    db("??");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '.') {
                for (int k = 0; k < 4; ++k) {
                    int tx = dx[k] + i, ty = dy[k] + j;
                    if (s[tx][ty] == '.') {
                        fa[find(get(i, j))] = find(get(tx, ty));
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '*') {
                for (int k = 0; k < 4; ++k) {
                    int tx = dx[k] + i, ty = dy[k] + j;
                    if (s[tx][ty] == '.') {
                        ++sz[find(get(tx, ty))];
                    }
                }
            }
        }
    }
    db("");
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << sz[find(get(x, y))] << endl;
    }

    return 0;
}