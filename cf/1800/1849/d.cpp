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

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (a[1] == 2) {
        a[1] = 1;
    }
    if (a[n] == 2) {
        a[n] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= 0) {
            continue;
        }
        int j = i;
        while (j + 1 <= n && a[j + 1]) {
            ++j;
        }
        int p = 0;
        for (int k = i; k <= j; ++k) {
            if (a[k] == 2) {
                p = 1;
            }
        }
        if (p) {
            ++ans;
            for (int k = i - 1; k <= j + 1; ++k) {
                a[k] = -1;
                // cout << "** " << k << endl;
            }
        } else {
            if (i - 1 >= 1 && a[i - 1] == 0) {
                ++ans;
                for (int k = i - 1; k <= j; ++k) {
                    a[k] = -1;
                    // cout << "-- " << k << endl;
                }
            } else {
                ++ans;
                // cout << "++ " << i << ' ' << j << endl;
                for (int k = i; k <= j + 1; ++k) {
                    a[k] = -1;
                    // cout << "++ " << k << endl;
                }
            }
        }

        i = j;
    }
    for (int i = 1; i <= n; ++i) {
        // cout << i << ' ' << a[i] << endl;
        if (a[i] == 0) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}