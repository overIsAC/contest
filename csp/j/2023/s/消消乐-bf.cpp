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
const int N = 3 + 8000;

int r[N];
char s[N];
int n;
bool vis[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> s + 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == s[i + 1]) {
            vis[i][i + 1] = 1;
            ++ans;
        }
    }
    for (int len = 4; len <= n; len += 2) {
        for (int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
            if (vis[l + 1][r - 1] && s[l] == s[r]) {
                vis[l][r] = 1;
            }
            for (int i = l + 1; i + 2 <= r && !vis[l][r]; i += 2) {
                if (vis[l][i] && vis[i + 1][r]) {
                    vis[l][r] = 1;
                }
            }
            if (vis[l][r]) {
                ++ans;
                for (int q = r - 1, w = q - 1; w >= 1 && q - w + 1 <= len; w -= 2) {
                    if (vis[w][q]) {
                        vis[w][r] = 1;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}