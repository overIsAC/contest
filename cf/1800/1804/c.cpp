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

int n, x, p;

void solve() {
    LL sum = x;
    for (int i = 1; i <= 2 * n && i <= p; ++i) {
        sum = (sum + i) % n;
        if (sum == 0) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x >> p;
        solve();
    }
    return 0;
}