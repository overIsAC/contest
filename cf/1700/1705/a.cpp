#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, a[222], x;
        cin >> n >> x;
        for (int i = 1; i <= n * 2; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n * 2 + 1);
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (a[i] + x > a[i + n]) ok = false;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}