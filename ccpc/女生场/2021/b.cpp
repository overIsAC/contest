#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, m;
char s[N];
int nxt[N][26];
int f[N][20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    cin >> s + 1;
    for (int i = 0; i < m; ++i) {
        nxt[n + 1][i] = n + 1;
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < m; ++j) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i] - 'a'] = i;
    }
    for (int i = n + 1; i >= 1; --i) {
        int c = 0;
        for (int j = 0; j < m; ++j) {
            c = max(c, nxt[i][j]);
        }
        f[i][0] = c;
        for (int j = 1; j < 20; ++j) {
            f[i][j] = f[min(f[i][j - 1] + 1, n + 1)][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 19; i >= 0 && l <= r; --i) {
            if (f[l][i] <= r) {
                l = f[l][i] + 1;
                ans += 1 << i;
            }
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}