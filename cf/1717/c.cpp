#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], b[N];
bool c[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            c[i] = false;
        }
        bool ok = true;
        int mn = 2e9;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            if (a[i] > b[i]) {
                ok = false;
            }
            if (a[i] == b[i]) {
                c[i] = true;
            }
            mn = min(mn, b[i]);
        }
        if (!ok) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (b[i] == mn) {
                c[i] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!c[i]) continue;
            int j = (i - 1 + n) % n;
            while (!c[j] && b[j] <= b[(j + 1) % n] + 1) {
                c[j] = true;
                j = (j - 1 + n) % n;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!c[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}