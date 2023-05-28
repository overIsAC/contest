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
const int N = 3 + 4e5;

int a[N], b[N], n;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        if (a[1] == a[n] && count(a + 1, a + n + 1, a[1]) == n && count(b + 1, b + n + 1, a[1]) == n) {
            cout << 2 * n << endl;
            continue;
        }
        for (int i = 2; i <= n; ++i) {
            if (a[i - 1] != a[i]) {
                swap(a[i], b[i]);
            }
        }
        if (count(a + 1, a + n + 1, a[1]) == n && count(b + 1, b + n + 1, b[1]) == n) {
            cout << n << endl;
            continue;
        }
        cout << 1 << endl;
    }
    return 0;
}