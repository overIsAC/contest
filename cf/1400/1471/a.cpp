#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N], x;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        LL q = 0, w = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            q += (a[i] + x - 1) / x;
            w += a[i];
        }
        w = (w + x - 1) / x;
        cout << w << ' ' << q << endl;
    }
    return 0;
}