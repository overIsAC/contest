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

int n, z, a[N];

int main() {
    cin >> n >> z;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 0, r = n / 2;
    auto ok = [&](int v) {
        for (int i = 1, j = n - v + 1; i <= v; ++i, ++j) {
            if (a[j] - a[i] >= z) {
            } else {
                return false;
            }
        }
        return true;
    };
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (ok(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
    return 0;
}