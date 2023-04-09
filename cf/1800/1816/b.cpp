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

int ans[3][N];
int n;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        ans[1][1] = 2 * n;
        ans[2][n] = 2 * n - 1;
        int u = 2 * n - 2, v = 1;
        int flag = 0;
        for (int i = 2; i <= n; ++i) {
            if (flag) {
                ans[1][i] = u;
                ans[2][i - 1] = u - 1;
                u -= 2;
            } else {
                ans[1][i] = v + 1;
                ans[2][i - 1] = v;
                v += 2;
            }
            flag = !flag;
        }
        for (int i = 1; i <= 2; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}