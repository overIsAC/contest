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
const int N = 3 + 3e5;

int n, a[N];
bool pre[N], suf[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        pre[0] = 1;
        suf[n + 1] = 1;
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1];
            if (a[i] < i - 1) {
                pre[i] = 0;
            }
        }
        for (int i = n; i >= 1; --i) {
            suf[i] = suf[i + 1];
            if (a[i] < n - i) {
                suf[i] = 0;
            }
        }
        int ok = false;
        for (int i = 1; i <= n; ++i) {
            if (pre[i] && suf[i]) {
                ok = true;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}