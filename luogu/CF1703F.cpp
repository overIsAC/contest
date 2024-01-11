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
const int N = 3 + 2e5;

void solve() {
    int n, a[N];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b;
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= i) {
            continue;
        }
        if (b.size()) {
            int l = 0, r = b.size() - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (b[mid] < a[i]) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (b[r] < a[i]) {
                ans += r + 1;
            }
        }
        b.push_back(i);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}