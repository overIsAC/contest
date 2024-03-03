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
const int N = 3 + 100;

int n, m;
char s[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '?') {
                int ans = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int tx = dx + i, ty = dy + j;
                        if (1 <= tx && tx <= n && 1 <= ty && ty <= m) {
                            if (s[tx][ty] == '*') {
                                ans += 1;
                            }
                        }
                    }
                }

                s[i][j] = ans + '0';
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << s[i] + 1 << endl;
    }
    return 0;
}