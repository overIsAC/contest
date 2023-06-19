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

int n, m, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<LL> b;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > 0) {
                b.push_back((n - i + 1LL) * a[i]);
            }
        }
        LL ans = accumulate(a + 1, a + n + 1, 0LL);
        sort(b.rbegin(), b.rend());
        for (int i = 1; i <= n && i <= b.size() && i <= m; ++i) {
            ans -= b[i - 1];
        }
        cout << ans << endl;
    }
    return 0;
}