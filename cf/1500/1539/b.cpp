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
const int N = 3 + 1e5;

int pre[N][26];
char s[N];
int n, q;

int main() {
    cin >> n >> q;
    cin >> s + 1;
    for (int i = 1; i <= n; ++i) {
        memcpy(pre[i], pre[i - 1], sizeof(pre[i]));
        ++pre[i][s[i] - 'a'];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += (i + 1) * (pre[r][i] - pre[l - 1][i]);
        }
        cout << ans << endl;
    }
    return 0;
}