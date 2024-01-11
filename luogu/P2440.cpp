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

int n, k;
int a[N];

int ok(int z) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += a[i] / z;
        if (cnt >= k) {
            return 1;
        }
    }
    return 0;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int L = 1, R = 1e8;
    while (L < R) {
        int mid = L + R + 1 >> 1;
        if (ok(mid)) {
            L = mid;
        } else {
            R = mid - 1;
        }
    }
    if (!ok(R)) {
        R = 0;
    }
    cout << R << endl;
    return 0;
}