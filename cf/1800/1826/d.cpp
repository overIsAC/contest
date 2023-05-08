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

int n, a[N];
int pre[N], suf[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        pre[0] = -1e8;
        suf[n + 1] = -1e8;
        for (int i = 1; i <= n; ++i) {
            pre[i] = max(pre[i - 1], a[i] + i);
        }
        for (int i = n; i >= 1; --i) {
            suf[i] = max(suf[i + 1], a[i] - i);
        }
        int ans = -1e9;
        for (int i = 2; i < n; ++i) {
            ans = max(ans, pre[i - 1] + suf[i + 1] + a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}