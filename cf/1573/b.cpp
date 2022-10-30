#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N], b[N];
int c[N], d[N], t;

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
        if (a[1] < b[1]) {
            cout << 0 << endl;
            continue;
        }
        t = 1;
        c[1] = a[1];
        for (int i = 2; i <= n; ++i) {
            if (c[t] > a[i]) {
                c[++t] = a[i];
                d[t] = i - 1;
            }
        }
        int ans = n;
        for (int i = 1; i <= n; ++i) {
            int l = 1, r = t;
            while (l < r) {
                int mid = l + r >> 1;
                if (c[mid] < b[i])
                    r = mid;
                else
                    l = mid + 1;
            }
            ans = min(ans, d[r] + i - 1);
        }
        cout << ans << endl;
    }
    return 0;
}