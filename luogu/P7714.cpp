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
const int N = 3 + 1e6;

int n, a[N];

void solve() {
	cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int r = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        r = max(r, a[i]);
        if (r != i || r != a[i]) {
            ++ans;
        }
    }
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}