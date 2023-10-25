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

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= 10; ++i) {
        for (int j = i + 1; j <= 10; ++j) {
            int k = n - i - j;
            if (k > 0 && k % 3 && i % 3 && j % 3 && k != i && k != j) {
                cout << "YES" << endl;
                cout << i << ' ' << j << ' ' << k << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}