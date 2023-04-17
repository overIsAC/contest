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
const int N = 3 + 1000;

int n, m, q;
char s[N], t[N];
int ans[N][N];

int main() {
    cin >> n >> m >> q;
    cin >> s + 1;
    cin >> t + 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int k = 0;
            while (i + k <= n && j + k <= m && s[i + k] == t[j + k]) {
                ++ans[i][i + k];
            }
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ans[l][r] << endl;
    }
    return 0;
}