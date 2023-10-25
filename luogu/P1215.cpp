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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int vis[22][22][22];
int a, b, c;

void pull(int &ta, int &tb, int tc, int a, int b, int c) {
    ta += tb;
    tb = max(0, ta - a);
    ta = min(ta, a);
}

void dfs(int a, int b, int c) {
    if (vis[a][b][c]) {
        return;
    }
    vis[a][b][c] = 1;
    int ta = a, tb = b, tc = c;
    pull(ta, tb, tc, ::a, ::b, ::c);
    dfs(ta, tb, tc);
    ta = a, tb = b, tc = c;
    pull(ta, tc, tb, ::a, ::c, ::b);
    dfs(ta, tb, tc);

    ta = a, tb = b, tc = c;
    pull(tb, ta, tc, ::b, ::a, ::c);
    dfs(ta, tb, tc);
    ta = a, tb = b, tc = c;
    pull(tb, tc, ta, ::b, ::c, ::a);
    dfs(ta, tb, tc);

    ta = a, tb = b, tc = c;
    pull(tc, ta, tb, ::c, ::a, ::b);
    dfs(ta, tb, tc);
    ta = a, tb = b, tc = c;
    pull(tc, tb, ta, ::c, ::b, ::a);
    dfs(ta, tb, tc);
}

int main() {
    cin >> a >> b >> c;
    dfs(0, 0, c);
    for (int i = b; i >= 0; --i) {
        for (int j = 0; j <= c; ++j) {
            if (vis[0][i][j]) {
                cout << j << ' ';
            }
        }
    }
    return 0;
}